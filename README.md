# CSUSB_CarHacking
Repository for creating CSUSB's Car Hacking and V2V environment distribution

## Installing the VM Distribution through Virtualbox
1. Create new Virtual Machine
	* Type: Linux
	* Version: Debian (32 or 64-bit depending on ISO file, 64-bit recommended)
	* RAM: 2 GB (minimum)/ 4-8 GB (recommended)
	* Hard disk file type: VDI
	* Hard disk file expanding: Dynamically allocated
	* Storage: 40-50 GB (minimum)/ 64 (recommended)
		Note: If interested in utilizing SDR, have at least 70-80 GB
2. Connect the ISO file
	* Right-click VM instance
	* Choose settings
	* Enter storage sub-menu
	* Connect your ISO by choosing the Virtual Optical Disk File under Controller: IDE
	
## Installing the VM Distribution through VMware
1. Create new Virtual Machine
	* Add a new machine
	* Drag Security Parrot ISO into appropriate box
	* Choose operating system as follows: Linux and then Debian 7.x 64 bit
	* Choose boot firmware as follows: UEFI
	* Click finish
	* Name it Parrot Security and save it

2. Once it loads in the vm, and you see parrot security scroll down and click on install
	* Then go through the process, pick appropriate language and region
	* Create a username and password
	* Choose time zone
	* Partitioning method: Guided – use entire disk
	* Select disk to partition: SCSI3 (0,0,0) (sda) – 21.5gb VMware, vmware virtuals
	* Selected for partitioning: Partitioning scheme – All files in one partition (recommended)
	* Do you want to return to the partitioning menu? Select NO
	* Write changes to disks? YES
	* Install the GRUB boot loader to the master boot record? YES
	* Device for boot loader install? /dev/sda
	* Install complete, press enter
	* Once completed, another pop up will come up. Pick appropriate languages
	* Check for updates? Yes, and install

## Initial Set-up of VM
1. Install Parrot OS in the VM (https://www.tecmint.com/parrot-security-os-penetration-testing-hacking-and-anonymity/)
2. Install Instrument Cluster Simulator (ICSim)
* Note: Make sure to take note of which directory you are in since it will install wherever you enter the commands
	```
	$ sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev
	$ sudo git clone https://github.com/zombieCraig/ICSim.git
	```
3. Open ICSim
* Note: Make sure you are in the ICSim directory before running these commands
	* The following commands set up a virtual can interface
	```
	$ sudo modprobe can
	$ sudo modprobe vcan
	$ sudo ip link add dev vcan0 type vcan
	$ sudo ip link set up vcan0
	```
* Note: Run the two commands together with " & " in-between them
	* The following commands start the ICSim and the controls
	```
	$ ./icsim vcan0
	$ ./controls vcan0
	```
3. Open Unified Diagnostic Services Simulator (UDSim)
* Go to udsim under the Automotive tools in Applications
	* Using the SocketCAN tools travel to the src folder and enter the following command to compile:
	```
	$ sudo make 
	```
	* Run UDSim from withing the src folder
	```
	$ ./udsim vcan0
	```
4. Install socketcand
* Note: Install in a suitable folder (home directory recommended alongside ICSim)
	```
	$ sudo git clone https://github.com/dschanoeh/socketcand.git
	```
    
## Installing PyBOMBS
	```
	$ pip install --upgrade git+https://github.com/gnuradio/pybombs.git
	$ pybombs auto-config
	$ pybombs recipes add-defaults
	$ export PATH=$PATH:$HOME/.local/bin
	$ mkdir ~/pybombs/
	$ pybombs prefix init pybombs/bladeRF -a bladeRF -R gnuradio-default
	$ pybombs -p bladeRF install bladeRF gr-iqbal gr-osmosdr gqrx
	$ pybombs -p bladeRF run bladeRF-cli -- -i
	$ pybombs -p bladeRF run gqrx
	```

## Setting up the Arduino Canbus Shield v2
1. Install Arduino IDE on Linux (https://www.arduino.cc/en/Guide/Linux)
2. Install CAN-BUS Shield V2 libraries
	* Travel to the library folder within extracted Arduino download file
	```
	$ sudo git clone https://github.com/Seeed-Studio/CAN_BUS_Shield.git
	```

## Setting up the BladeRF A9
1. Clone this repository (https://github.com/Nuand/bladeRF.git)
2. Fetch the latest pre-built bladeRF FPGA image. See the README.md in the hdl directory for more information. Google bladeRF FPGA for image.
3. Fetch the latest pre-built bladeRF firmware image. See the README.md in the fx3_firmware directory for more information.
    ```
    $ mkdir build
    $ cd build
    $ cmake -DFX3_INSTALL_PATH=/opt/cypress/fx3_sdk -DCMAKE_TOOLCHAIN_FILE=../cmake/fx3-toolchain.cmake ../
    $ make
    ```
4. Follow the instructions in the host directory to build and install libbladeRF and the bladeRF-cli utility.
5. Attach the bladeRF board to your fastest USB port.
6. You should now be able to see your device in the list output via bladeRF-cli -p
7. You can view additional information about the device via bladeRF-cli -e info -e version.
8. If any warnings indicate that a firmware update is needed, run:bladeRF-cli -f <firmware_file>.
	* If you ever find the device booting into the FX3 bootloader (e.g., if you unplug the device in the middle of a firmware upgrade), see the recovery command in bladeRF-cli for additional details.
9. See the overview of the bladeRF-cli for more information about loading the FPGA and using the command line interface tool

