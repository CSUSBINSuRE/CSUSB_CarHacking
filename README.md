# CSUSB_CarHacking
Repository for creating CSUSB's Car Hacking and V2V environment Distribution

## Installing the VM Distribution through Virtualbox
	1. Create new Virtual Machine
		* Type: Linux
		* Version: Debian (32 or 64-bit depending on ISO file, 64-bit recommended)
		* RAM: 2 GB (minimum)/ 4-8 GB (recommended)
		* Hard disk file type: VDI
		* Hard disk file expanding: Dynamically allocated
		* Storage: 40-50 GB (minimum)/ 64 (recommended)
	2. Connect the ISO file
		* Right-click VM instance
		* Choose settings
		* Enter storage sub-menu
    * Connect your ISO by choosing the Virtual Optical Disk File under Controller: IDE

## Initial Set-up of VM
	1. Install Parrot OS in the VM (https://www.tecmint.com/parrot-security-os-penetration-testing-hacking-and-anonymity/)
	2. Install ICSim
		```
		$ sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev
		$ sudo git clone https://github.com/zombieCraig/ICSim
		```
	3. Open ICSim
 		```
		$ sudo modprobe can
 		$ sudo modprobe vcan
 		$ sudo ip link add dev vcan0 type vcan
		$ sudo ip link set up vcan0
		$ ./icsim vcan0
		$ ./controls vcan0
		```
	3. Open UDSim
		* Go to udsim under the Automotive tools in Applications
		```
		$ sudo make 
		```
		* Run UDSim
		```
		$ ./udsim vcan0
		$ sudo git clone https://github.com/dschanoeh/socketcand.git
		```
	4. Setup virtual can interface
		```
		$ sudo modprobe can
		$ sudo modprobe vcan
		$ sudo ip link add dev vcan0 type vcan
    $ sudo ip link set up vcan0
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

##	Setting up the BladeRF A9
    * Clone this repository (https://github.com/Nuand/bladeRF.git)
    * Fetch the latest pre-built bladeRF FPGA image. See the README.md in the hdl directory for more information. Google bladeRF FPGA for image.
    * Fetch the latest pre-built bladeRF firmware image. See the README.md in the fx3_firmware directory for more information.
    ```
    $ mkdir build
    $ cd build
    $ cmake -DFX3_INSTALL_PATH=/opt/cypress/fx3_sdk -DCMAKE_TOOLCHAIN_FILE=../cmake/fx3-toolchain.cmake ../
    $ make
    ```
    * Follow the instructions in the host directory to build and install libbladeRF and the bladeRF-cli utility.
    * Attach the bladeRF board to your fastest USB port.
    * You should now be able to see your device in the list output via bladeRF-cli -p
    * You can view additional information about the device via bladeRF-cli -e info -e version.
    * If any warnings indicate that a firmware update is needed, run:bladeRF-cli -f <firmware_file>.
      ○	If you ever find the device booting into the FX3 bootloader (e.g., if you unplug the device in the middle of a firmware upgrade), see the recovery command in bladeRF-cli for additional details.
    * See the overview of the bladeRF-cli for more information about loading the FPGA and using the command line interface tool
