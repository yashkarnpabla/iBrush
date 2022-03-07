/** Weather widget class
 *This class is designed to retrieve a JSON file from the
 *openweathermap API and parse it to display local weather statistics
 * @author Spencer Poultney
 * @brief displays form containing weather data
 */

#include "widget.h"
#include "ui_widget.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QUrl>
#include <QPixmap>

/**
 * @brief creates weather widget
 * @param parent
 */
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPixmap weatherBackgroundPic("/home/pi/toothBrushGUI/weatherIcons/weatherbackgroundrsz.jpg");
    ui->weatherBackground->setPixmap(weatherBackgroundPic);

    networkManager = new QNetworkAccessManager();

    // Connect networkManager response to the handler
    connect(networkManager, &QNetworkAccessManager::finished, this, &Widget::onResult);
    // We get the data, namely JSON file from a site on a particular url
    networkManager->get(QNetworkRequest(QUrl("http://api.openweathermap.org/data/2.5/weather?lat=42.983612&lon=-81.249725&appid=c4ac218355fde02e245e6b5ba2e16137")));   //request from openweathermap API using provided key
}

/**
 * @brief deletes weather widget
 */
Widget::~Widget()
{
    delete ui;
}

/**
 * @brief Uses QNetworkReply to retrieve JSON and parse it to store
 *         weather data
 * @param reply
 */
void Widget::onResult(QNetworkReply *reply)
{
    // If there are no errors
    if(!reply->error()){

        // So create an object Json Document, by reading into it all the data from the response

        QJsonDocument document = QJsonDocument::fromJson(reply->readAll());

        //get root object of document
        QJsonObject root = document.object();


        //GET NAME OF LOCATION
        QString locationName = root.value(root.keys().at(7)).toString();

        //GET WEATHER DATA
        QJsonValue weatherJson = root.value("weather");
        QJsonArray weatherArray = weatherJson.toArray();

        QString main;
        QString description;
        QString icon;

        foreach (const QJsonValue & v, weatherArray) {
            QString getMain = v.toObject().value("main").toString();   //USE THIS TO DECIDE WEATHER ICON
            main = getMain;
            QString getDescription = v.toObject().value("description").toString();
            description = getDescription;
            QString getIcon = v.toObject().value("icon").toString();
            icon = getIcon;
        }

        //GET MAIN DATA
        QJsonValue mainJson = root.value("main");

        double temp = (mainJson.toObject().value("temp").toDouble()) - 273.15;  //convert from kelvin to celcius
        double feels_like = mainJson.toObject().value("feels_like").toDouble() - 273.15;
        double temp_min = mainJson.toObject().value("temp_min").toDouble() - 273.15;
        double temp_max = mainJson.toObject().value("temp_max").toDouble() - 273.15;
        int humidity = mainJson.toObject().value("humidity").toInt();



        //GET WIND DATA
        QJsonValue windJson = root.value("wind");

        double speed = windJson.toObject().value("speed").toDouble() * 2.237; //convert to mph
        int deg = windJson.toObject().value("deg").toInt();

        QString windDirection;

        if (deg > 348.75 || deg < 11.25) {
            windDirection = "N";
        }
        if (deg > 11.25 & deg < 33.75) {
            windDirection = "NNE";
        }
        if (deg > 33.75 & deg < 56.25) {
            windDirection = "NE";
        }
        if (deg > 56.25 & deg < 78.75) {
            windDirection = "ENE";
        }
        if (deg > 78.75 & deg < 101.25) {
            windDirection = "E";
        }
        if (deg > 101.25 & deg < 123.75) {
            windDirection = "ESE";
        }
        if (deg > 123.75 & deg < 146.25) {
            windDirection = "SE";
        }
        if (deg > 146.25 & deg < 168.75) {
            windDirection = "SSE";
        }
        if (deg > 168.75 & deg < 191.25) {
            windDirection = "S";
        }
        if (deg > 191.25 & deg < 213.75) {
            windDirection = "SSW";
        }
        if (deg > 213.75 & deg < 236.25) {
            windDirection = "SW";
        }
        if (deg > 236.25 & deg < 258.75) {
            windDirection = "WSW";
        }
        if (deg > 258.75 & deg < 281.25) {
            windDirection = "W";
        }
        if (deg > 281.25 & deg < 303.75) {
            windDirection = "WNW";
        }
        if (deg > 303.75 & deg < 326.25) {
            windDirection = "NW";
        }
        if (deg > 326.25 & deg < 348.75) {
            windDirection = "NNW";
        }

        //Append all of the collected data to the interface
        ui->locationNameTextEdit->append(locationName + "'s Local Weather");
        ui->tempTextEdit->append("Current Temp: " + QString::number(temp) + "°");
        ui->tempTextEdit->append("\nFeels Like: " + QString::number(feels_like) + "°");
        ui->tempTextEdit->append("\nDaily high of: " + QString::number(temp_max) + "°");
        ui->tempTextEdit->append("\nDaily low of: " + QString::number(temp_min) + "°");
        ui->humidityTextEdit->append("Humidity: " + QString::number(humidity) + "%");
        ui->windTextEdit->append("  Wind Speed: " + QString::number(speed) + " mph    Direction: " + windDirection);
        ui->descriptionTextEdit->append(description);

        //Update icon
        QString iconFile = "/home/pi/toothBrushGUI/weatherIcons/" + icon + "@2x.png";
        QPixmap iconPic(iconFile);
        ui->weatherIconLabel->setPixmap(iconPic);
    }
    reply->deleteLater();
}
