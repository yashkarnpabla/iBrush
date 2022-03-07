/** Sports window class
 * This class is designed to allow the user to pull up team statistics
 * and media for a variety of sports' respective professional leagues.
 * @author YASHKARN PABLA
 * @brief Allows user to view sports stats
 */

#include "sportswindow.h"
#include "ui_sportswindow.h"
#include "mediawindow.h"
#include <QDesktopServices>
#include <QUrl>
#include <QPixmap>

/**
 * @brief creates sports window
 * @param parent
 */
sportsWindow::sportsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sportsWindow)
{
    ui->setupUi(this);

    QPixmap defaultPic("/home/pi/toothBrushGUI/sportsPics/deafultrsz.jpg");

    ui->sportsPicture->setPixmap(defaultPic);   //Set default background

    ui->label->setStyleSheet("QLabel { background-color : grey;}"); //Make qcheckbox more visible

    //These get set visible upon select click
    ui->teamLineEdit->setVisible(false);
    ui->upcomingGamesButton->setVisible(false);
    ui->teamStatsButton->setVisible(false);
}

/**
 * @brief deletes sports window
 */
sportsWindow::~sportsWindow()
{
    delete ui;
}

/**
 * @brief allows for team specific functionality to appear on button click
 */
void sportsWindow::on_sportsSelectButton_clicked()
{
    //Now allow user to search for teams
    ui->teamLineEdit->setVisible(true);
    ui->upcomingGamesButton->setVisible(true);
    ui->teamStatsButton->setVisible(true);

    //Football (NFL)
    if (ui->sportsComboBox->currentText() == "Football") {
        QPixmap footballPic("/home/pi/toothBrushGUI/sportsPics/NFLbackgroundrsz.jpg");
        ui->sportsPicture->setPixmap(footballPic);

        if (ui->openYoutubeCheckBox->isChecked()) {
            QDesktopServices::openUrl(QUrl("https://www.youtube.com/c/NFL/videos"));
        }
    }

    //Basketball (NBA)
    if (ui->sportsComboBox->currentText() == "Basketball") {
        QPixmap basketballPic("/home/pi/toothBrushGUI/sportsPics/NBAbackgroundrsz.jpg");
        ui->sportsPicture->setPixmap(basketballPic);

        if (ui->openYoutubeCheckBox->isChecked()) {
        QDesktopServices::openUrl(QUrl("https://www.youtube.com/c/NBA/videos"));
        }
    }

    //Baseball (MLB)
    if (ui->sportsComboBox->currentText() == "Baseball") {
        QPixmap baseballPic("/home/pi/toothBrushGUI/sportsPics/MLBbackgroundrsz.jpg");
        ui->sportsPicture->setPixmap(baseballPic);

        if (ui->openYoutubeCheckBox->isChecked()) {
        QDesktopServices::openUrl(QUrl("https://www.youtube.com/c/MLB/videos"));
        }
    }

    //Hockey (NHL)
    if (ui->sportsComboBox->currentText() == "Hockey") {
        QPixmap hockeyPic("/home/pi/toothBrushGUI/sportsPics/NHLbackgroundrsz.jpg");
        ui->sportsPicture->setPixmap(hockeyPic);

        if (ui->openYoutubeCheckBox->isChecked()) {
        QDesktopServices::openUrl(QUrl("https://www.youtube.com/c/NHL/videos"));
        }
    }

}

/**
 * @brief closes current window and opens previous window
 */
void sportsWindow::on_sportsBackButton_clicked()
{
    hide();
    mediaWindow mediaWindowBack;
    mediaWindowBack.setModal(true);
    mediaWindowBack.exec();
}

/**
 * @brief opens team databases specified by user on button click
 */
void sportsWindow::on_teamStatsButton_clicked() {
    QString teamName = ui->teamLineEdit->displayText().toLower();

    /**
      This lengthy segment of code allows for multiple search formats
      for each respective team. This includes any combo of capital/
      lowercase letters.
      **/

    //NFL
    if (ui->sportsComboBox->currentText() == "Football") {

        if (teamName == "bills" || teamName == "buffalo" || teamName == "buffalo bills") {
            teamName = "buffalo-bills";
        }
        if (teamName == "steelers" || teamName == "pittsburgh" || teamName == "pittsburgh steelers") {
            teamName = "pittsburgh-steelers";
        }
        if (teamName == "chiefs" || teamName == "kansas city" || teamName == "kansas city chiefs") {
            teamName = "kansas-city-chiefs";
        }
        if (teamName == "patriots" || teamName == "new england" || teamName == "new england patriots") {
            teamName = "new-england-patriots";
        }
        if (teamName == "saints" || teamName == "new orleans" || teamName == "new orleans saints") {
            teamName = "new-orleans-saints";
        }
        if (teamName == "packers" || teamName == "green bay" || teamName == "green bay packers") {
            teamName = "green-bay-packers";
        }
        if (teamName == "eagles" || teamName == "philadelphia" || teamName == "philadelphia eagles") {
            teamName = "philadelphia-eagles";
        }
        if (teamName == "rams" || teamName == "los angeles" || teamName == "los angeles rams") {
            teamName = "los-angeles-rams";
        }
        if (teamName == "cowboys" || teamName == "dallas" || teamName == "dallas cowboys") {
            teamName = "dallas-cowboys";
        }
        if (teamName == "raiders" || teamName == "las vegas" || teamName == "las vegas raiders") {
            teamName = "las-vegas-raiders";
        }
        if (teamName == "titans" || teamName == "tennessee" || teamName == "tennessee titans") {
            teamName = "tennessee-titans";
        }
        if (teamName == "49ers" || teamName == "san fransisco" || teamName == "san fransisco 49ers") {
            teamName = "san-fransisco-49ers";
        }
        if (teamName == "seahawks" || teamName == "seattle" || teamName == "seattle seahawks") {
            teamName = "seattle-seahawks";
        }
        if (teamName == "falcons" || teamName == "atlanta" || teamName == "atlanta falcons") {
            teamName = "atlanta-falcons";
        }
        if (teamName == "broncos" || teamName == "denver" || teamName == "denver broncos") {
            teamName = "denver-broncos";
        }
        if (teamName == "browns" || teamName == "cleveland" || teamName == "cleveland browns") {
            teamName = "cleveland-browns";
        }
        if (teamName == "cardinals" || teamName == "arizona" || teamName == "arizona cardinals") {
            teamName = "arizona-cardinals";
        }
        if (teamName == "football team" || teamName == "washington" || teamName == "washington football team") {
            teamName = "washington-football-team";
        }
        if (teamName == "bengals" || teamName == "cincinnati" || teamName == "cincinnati bengals") {
            teamName = "cincinnati-bengals";
        }
        if (teamName == "vikings" || teamName == "minnesota" || teamName == "minnesota vikings") {
            teamName = "minnesota-vikings";
        }
        if (teamName == "ravens" || teamName == "baltimore" || teamName == "baltimore ravens") {
            teamName = "baltimore-ravens";
        }
        if (teamName == "chargers" || teamName == "los angeles chargers") {
            teamName = "los-angeles-chargers";
        }
        if (teamName == "giants" || teamName == "new york" || teamName == "new york giants") {
            teamName = "new-york-giants";
        }
        if (teamName == "jets" || teamName == "new york jets") {
            teamName = "new-york-jets";
        }
        if (teamName == "dolphins" || teamName == "miami" || teamName == "miami dolphins") {
            teamName = "miami-dolphins";
        }
        if (teamName == "panthers" || teamName == "carolina" || teamName == "carolina panthers") {
            teamName = "carolina-panthers";
        }
        if (teamName == "colts" || teamName == "indianapolis" || teamName == "indianapolis colts") {
            teamName = "indianapolis-colts";
        }
        if (teamName == "lions" || teamName == "detroit" || teamName == "detroit lions") {
            teamName = "detroit-lions";
        }
        if (teamName == "bears" || teamName == "chicago" || teamName == "chicago bears") {
            teamName = "chicago-bears";
        }
        if (teamName == "texans" || teamName == "houston" || teamName == "houston texans") {
            teamName = "houston-texans";
        }
        if (teamName == "buccaneers" || teamName == "tampa bay" || teamName == "tampa bay buccaneers") {
            teamName = "tampa-bay-buccaneers";
        }
        if (teamName == "jaguars" || teamName == "jacksonville" || teamName == "jacksonville jaguars") {
            teamName = "jacksonville-jaguars";
        }

        QDesktopServices::openUrl(QUrl("https://www.footballdb.com/teams/nfl/" + teamName));
    }

    //MLB
    if (ui->sportsComboBox->currentText() == "Baseball") {

        if (teamName == "yankees" || teamName == "new york" || teamName == "new york yankees") {
            teamName = "yankees";
        }
        if (teamName == "dodgers" || teamName == "los angeles" || teamName == "los angeles dodgers") {
            teamName = "dodgers";
        }
        if (teamName == "mets" || teamName == "new york mets") {
            teamName = "mets";
        }
        if (teamName == "red sox" || teamName == "boston" || teamName == "boston red sox") {
            teamName = "redsox";
        }
        if (teamName == "cubs" || teamName == "chicago" || teamName == "chicago cubs") {
            teamName = "cubs";
        }
        if (teamName == "braves" || teamName == "atlanta" || teamName == "atlanta braves") {
            teamName = "braves";
        }
        if (teamName == "blue jays" || teamName == "toronto" || teamName == "toronto blue jays") {
            teamName = "bluejays";
        }
        if (teamName == "cardinals" || teamName == "st. louis" || teamName == "st. louis cardinals") {
            teamName = "cardinals";
        }
        if (teamName == "white sox" || teamName == "chicago white sox") {
            teamName = "whitesox";
        }
        if (teamName == "angels" || teamName == "los angeles angels") {
            teamName = "angels";
        }
        if (teamName == "astros" || teamName == "houston" || teamName == "houston astros") {
            teamName = "astros";
        }
        if (teamName == "phillies" || teamName == "philadelphia" || teamName == "philadelphia phillies") {
            teamName = "phillies";
        }
        if (teamName == "giants" || teamName == "san fransisco" || teamName == "san francisco giants") {
            teamName = "giants";
        }
        if (teamName == "indians" || teamName == "cleveland" || teamName == "cleveland indians") {
            teamName = "indians";
        }
        if (teamName == "athletics" || teamName == "oakland" || teamName == "oakland athletics") {
            teamName = "athletics";
        }
        if (teamName == "tigers" || teamName == "detroit" || teamName == "detroit tigers") {
            teamName = "tigers";
        }
        if (teamName == "padres" || teamName == "san diego" || teamName == "san diego padres") {
            teamName = "padres";
        }
        if (teamName == "twins" || teamName == "minnesota" || teamName == "minnesota twins") {
            teamName = "twins";
        }
        if (teamName == "marlins" || teamName == "miami" || teamName == "miami marlins") {
            teamName = "marlins";
        }
        if (teamName == "reds" || teamName == "cincinnati" || teamName == "cincinnati reds") {
            teamName = "reds";
        }
        if (teamName == "mariners" || teamName == "seattle" || teamName == "seattle mariners") {
            teamName = "mariners";
        }
        if (teamName == "rays" || teamName == "tampa bay" || teamName == "tampa bay rays") {
            teamName = "rays";
        }
        if (teamName == "pirates" || teamName == "pittsburgh" || teamName == "pittsburgh pirates") {
            teamName = "pirates";
        }
        if (teamName == "nationals" || teamName == "washington" || teamName == "washington nationals") {
            teamName = "";
        }
        if (teamName == "brewers" || teamName == "milwaukee" || teamName == "milwaukee brewers") {
            teamName = "brewers";
        }
        if (teamName == "orioles" || teamName == "baltimore" || teamName == "baltimore orioles") {
            teamName = "orioles";
        }
        if (teamName == "rangers" || teamName == "texas" || teamName == "texas rangers") {
            teamName = "rangers";
        }
        if (teamName == "royals" || teamName == "kansas city" || teamName == "kansas city royals") {
            teamName = "royals";
        }
        if (teamName == "rockies" || teamName == "colorado" || teamName == "colorado rockies") {
            teamName = "rockies";
        }
        if (teamName == "diamondbacks" || teamName == "arizona" || teamName == "arizona diamondbacks") {
            teamName = "diamondbacks";
        }

        QDesktopServices::openUrl(QUrl("https://www.mlb.com/" + teamName));
    }

    //NBA
    if (ui->sportsComboBox->currentText() == "Basketball") {

        if (teamName == "raptors" || teamName == "toronto" || teamName == "toronto raptors") {
            teamName = "toronto-raptors-team";
        }
        if (teamName == "lakers" || teamName == "los angeles" || teamName == "los angeles lakers") {
            teamName = "los-angeles-lakers-team";
        }
        if (teamName == "rockets" || teamName == "houston" || teamName == "houston rockets") {
            teamName = "houston-rockets-team";
        }
        if (teamName == "bucks" || teamName == "milwaukee" || teamName == "milwaukee bucks") {
            teamName = "milwaukee-bucks-team";
        }
        if (teamName == "celtics" || teamName == "boston" || teamName == "boston celtics") {
            teamName = "boston-celtics-team";
        }
        if (teamName == "thunder" || teamName == "oklahoma city" || teamName == "oklahoma city thunder") {
            teamName = "oklahoma-city-thunder-team";
        }
        if (teamName == "knicks" || teamName == "new york" || teamName == "new york knicks") {
            teamName = "new-york-knicks-team";
        }
        if (teamName == "trail blazers" || teamName == "portland" || teamName == "portland trail blazers") {
            teamName = "portland-trail-blazers-team";
        }
        if (teamName == "clippers" || teamName == "los angeles clippers") {
            teamName = "los-angeles-clippers-team";
        }
        if (teamName == "jazz" || teamName == "utah" || teamName == "utah jazz") {
            teamName = "utah-jazz-team";
        }
        if (teamName == "76ers" || teamName == "philadelphia" || teamName == "philadelphia 76ers") {
            teamName = "philadelphia-76ers-team";
        }
        if (teamName == "warriors" || teamName == "golden state" || teamName == "golden state warriors") {
            teamName = "golden-state-warriors-team";
        }
        if (teamName == "heat" || teamName == "miami" || teamName == "miami heat") {
            teamName = "miami-heat-team";
        }
        if (teamName == "nuggets" || teamName == "denver" || teamName == "denver nuggets") {
            teamName = "denver-nuggets-team";
        }
        if (teamName == "mavericks" || teamName == "dallas" || teamName == "dallas mavericks") {
            teamName = "dallas-mavericks-team";
        }
        if (teamName == "wizards" || teamName == "washington" || teamName == "washington wizards") {
            teamName = "washington-wizards-team";
        }
        if (teamName == "spurs" || teamName == "san antonio" || teamName == "san antonio spurs") {
            teamName = "san-antonio-spurs-team";
        }
        if (teamName == "pistons" || teamName == "detroit" || teamName == "detroit pistons") {
            teamName = "detroit-pistons-team";
        }
        if (teamName == "suns" || teamName == "phoenix" || teamName == "phoenix suns") {
            teamName = "phoenix-suns-team";
        }
        if (teamName == "pelicans" || teamName == "new orleans" || teamName == "new orleans pelicans") {
            teamName = "new-orleans-pelicans-team";
        }
        if (teamName == "hornets" || teamName == "charlotte" || teamName == "charlotte hornets") {
            teamName = "charlotte-hornets-team";
        }
        if (teamName == "cavaliers" || teamName == "cleveland" || teamName == "cleveland cavaliers") {
            teamName = "cleveland-cavaliers-team";
        }
        if (teamName == "pacers" || teamName == "indiana" || teamName == "indiana pacers") {
            teamName = "indiana-pacers-team";
        }
        if (teamName == "nets" || teamName == "brooklyn" || teamName == "brooklyn nets") {
            teamName = "brooklyn-nets-team";
        }
        if (teamName == "hawks" || teamName == "atlanta" || teamName == "atlanta hawks") {
            teamName = "atlanta-hawks-team";
        }
        if (teamName == "bulls" || teamName == "chicago" || teamName == "chicago bulls") {
            teamName = "chicago-bulls-team";
        }
        if (teamName == "grizzlies" || teamName == "memphis" || teamName == "memphis grizzlies") {
            teamName = "memphis-grizzlies-team";
        }
        if (teamName == "timberwolves" || teamName == "minnesota" || teamName == "minnesota timberwolves") {
            teamName = "minnesota-timberwolves-team";
        }
        if (teamName == "kings" || teamName == "sacramento" || teamName == "sacramento") {
            teamName = "sacramento-kings-team";
        }
        if (teamName == "magic" || teamName == "orlando" || teamName == "orlando magic") {
            teamName = "orlando-magic-team";
        }

        QDesktopServices::openUrl(QUrl("https://www.foxsports.com/nba/" + teamName));
    }

    //NHL
    if (ui->sportsComboBox->currentText() == "Hockey") {

        if (teamName == "maple leafs" || teamName == "toronto" || teamName == "toronto maple leafs") {
            teamName = "TOR";
        }
        if (teamName == "ducks" || teamName == "anaheim" || teamName == "anaheim ducks") {
            teamName = "ANA";
        }
        if (teamName == "coyotes" || teamName == "arizona" || teamName == "arizona coyotes") {
            teamName = "ARI";
        }
        if (teamName == "bruins" || teamName == "boston" || teamName == "boston bruins") {
            teamName = "BOS";
        }
        if (teamName == "sabres" || teamName == "buffalo" || teamName == "buffalo sabres") {
            teamName = "BUF";
        }
        if (teamName == "hurricanes" || teamName == "carolina" || teamName == "carolina hurricanes") {
            teamName = "CAR";
        }
        if (teamName == "flames" || teamName == "calgary" || teamName == "calgary flames") {
            teamName = "CGY";
        }
        if (teamName == "blackhawks" || teamName == "chicago" || teamName == "chicago blackhawks") {
            teamName = "CHI";
        }
        if (teamName == "blue jackets" || teamName == "columbus" || teamName == "columbus blue jackets") {
            teamName = "CBJ";
        }
        if (teamName == "avalanche" || teamName == "colorado" || teamName == "colorado avalanche") {
            teamName = "COL";
        }
        if (teamName == "stars" || teamName == "dallas" || teamName == "dallas stars") {
            teamName = "DAL";
        }
        if (teamName == "red wings" || teamName == "detroit" || teamName == "detroit red wings") {
            teamName = "DET";
        }
        if (teamName == "oilers" || teamName == "edmonton" || teamName == "edmonton oilers") {
            teamName = "EDM";
        }
        if (teamName == "panthers" || teamName == "florida" || teamName == "florida panthers") {
            teamName = "FLA";
        }
        if (teamName == "kings" || teamName == "los angeles" || teamName == "los angeles kings") {
            teamName = "LAK";
        }
        if (teamName == "wild" || teamName == "minnesota" || teamName == "minnesota wild") {
            teamName = "MIN";
        }
        if (teamName == "canadiens" || teamName == "montreal" || teamName == "montreal canadiens") {
            teamName = "MTL";
        }
        if (teamName == "predators" || teamName == "nashville" || teamName == "nashville predators") {
            teamName = "NSH";
        }
        if (teamName == "devils" || teamName == "new jersey" || teamName == "new jersey devils") {
            teamName = "NJD";
        }
        if (teamName == "islanders" || teamName == "new york" || teamName == "new york islanders") {
            teamName = "NYI";
        }
        if (teamName == "rangers" || teamName == "new york rangers") {
            teamName = "NYR";
        }
        if (teamName == "senators" || teamName == "ottawa" || teamName == "ottawa senators") {
            teamName = "OTT";
        }
        if (teamName == "flyers" || teamName == "philadelphia" || teamName == "philadelphia flyers") {
            teamName = "PHI";
        }
        if (teamName == "penguins" || teamName == "pittsburgh" || teamName == "pittsburgh penguins") {
            teamName = "PIT";
        }
        if (teamName == "sharks" || teamName == "san jose" || teamName == "san jose sharks") {
            teamName = "SJS";
        }
        if (teamName == "blues" || teamName == "st. louis" || teamName == "st. louis blues") {
            teamName = "STL";
        }
        if (teamName == "lightning" || teamName == "tampa bay" || teamName == "tampa bay lightning") {
            teamName = "TBL";
        }
        if (teamName == "canucks" || teamName == "vancouver" || teamName == "vancouver canucks") {
            teamName = "VAN";
        }
        if (teamName == "golden knights" || teamName == "vegas" || teamName =="las vegas" || teamName == "vegas golden knights" || teamName == "las vegas golden knights") {
            teamName = "VGK";
        }
        if (teamName == "jets" || teamName == "winnipeg" || teamName == "winnipeg jets") {
            teamName = "WPG";
        }

        QDesktopServices::openUrl(QUrl("https://www.hockey-reference.com/teams/" + teamName + "/2020.html"));
    }


   }

/**
 * @brief displays upcoming games for league specified by user
 */
void sportsWindow::on_upcomingGamesButton_clicked()
{
    //Pulls up upcoming games for each respective league

    if (ui->sportsComboBox->currentText() == "Football") {
        QDesktopServices::openUrl(QUrl("https://www.google.com/search?q=upcoming+nfl+games&oq=upcoming+nfl+games&aqs=chrome.0.0i457j0l7.4569j1j9&sourceid=chrome&ie=UTF-8#sie=lg;/g/11h8z4k88l;6;/m/059yj;mt;fp;1;;"));
    }
    if (ui->sportsComboBox->currentText() == "Baseball") {
        QDesktopServices::openUrl(QUrl("https://www.mlb.com/schedule/2020-11-23"));
    }
    if (ui->sportsComboBox->currentText() == "Basketball") {
        QDesktopServices::openUrl(QUrl("https://www.espn.com/nba/schedule"));
    }
    if (ui->sportsComboBox->currentText() == "Hockey") {
        QDesktopServices::openUrl(QUrl("https://www.nhl.com/schedule"));
    }
}
