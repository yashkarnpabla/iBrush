# ToothBrushGUI

2 methods to run project on fresh raspberry pi:

1. 
- Navigate to the executable repo: https://github.com/TechbrushExc
- Create a new folder named(case sensitive) "toothBrushGUI" in path: /home/pi
- Extract the repo files into that new folder, then run the executable toothBrushGUI file

2.
Second method requires that you install QT creator. This can be done through the terminal through the commands:
sudo apt-get install qt5-default
sudo apt-get install qtcreator

To open qtcreator from the terminal execute the command: 
qtcreator

Once in qtcreator, create new project -> import project -> gitclone
enter the repository: https://github.com/SpencerRobert/ToothBrushGUI
enter the path: /home/pi
name the directory (case sensitive): toothBrushGUI
hit next and finish cloning, then select the desktop kit and configure project
build the project in qtcreator
then run within qt or through terminal command: /home/pi/build-toothBrushGUI-Desktop-Debug/toothBrushGUI
