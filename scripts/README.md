# README for Scripts

## VCAN 
The VCAN bash script is an executable to run the VCAN.py python3 script as root.
This script navigates to the scripts folder on the desktop and runs the VCAN.py.
This script needs to be located on the Desktop since the script changes directories from there.
If this script is not on the Desktop OR the VCAN.py is not in the scripts folder on the desktop it will not work.


### VCAN.py
This script should be located in a folder called scripts on the Desktop.
This script runs all aspects of the virtual environment from one location.
* cansniffer
* ICSim Controls
* ICSim
* UDSim
* Wireshark
> This script will open and execute all of these programs.
> However, this script does not save any captured data. So be sure to save before exiting.

### VCanCanDoTheCanCan.py
This script is a back up for VCAN.py and should be in a folder along with VCAN.py called scripts on the Desktop.
This script runs and executes the main menu of all aspects of the virtual environment from one location.
* Cansniffer
* ICSim Controls
* ICSim
* UDSim
* Wireshark
> This script will open and execute all of these programs
> Be sure to save before exiting


## CAN
The CAN bash script is an executable to run the CAN.py python3 script as root.
This script navagates to the scripts folder on the desktop and runs the CAN.py.
This script needs to be located on the Desktop since the script changes directories from there.
If this script is not on the Desktop OR the CAN.py is not in the scripts folder on the desktop it will not work.

### CAN.py
This script should be located in a folder called scripts on the Desktop.
This script runs the necessary programs when connected to a vehicle.
* cansniffer
* Wireshark
This script has the option to change the bitrate of a vehicle.
The default bitrate is 500,000.
However this variable is not currently used in our environment.
This is for future builds.
> This script will open and execute these programs.
> However, this script does not save any captured data. So be sure to save before exiting.
