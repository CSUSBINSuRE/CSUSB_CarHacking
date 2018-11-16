The temporary home of CSUSB's "Car-Hacking" project documentation

VM Distribution Installation of Parrot OS Instructions


Installing the VM Distribution through Virtualbox
	1. Create new Virtual Machine
		a. Type: Linux
		b. Version: Debian
		c. RAM:  2 GB (min.), 4-8 GB (recommended)
		d. Hard disk file type: VDI
		e. Hard disk file expanding: Dynamically allocated
		f. Storage: 40-50 GB (min.), 64 (recommended)
	2. Connect the ISO file
		a. Right-click VM instance
		b. Choose settings
		c. Enter storage sub-menu
		d. Connect your ISO by choosing the Virtual Optical Disk File under Controller: IDE

Initial Set-up of VM
	1. Install the OS in the VM
		a. https://www.tecmint.com/parrot-security-os-penetration-testing-hacking-and-anonymity/
		b. *note: name, parrot, root
	2. Install ICSim
		a. Enter the following command: 
			i. sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev
	3. Open UDSim
		a. Go to udsim under the Automotive tools in Applications
		b. Use the console to enter the following commands:
			i. sudo make 
			ii. ./udsim vcan0
			iii. sudo git clone https://github.com/dschanoeh/socketcand.git
	4. Setup virtual can interface
		a. Enter the following commands:
			i. sudo modprobe can
			ii. sudo modprobe vcan
			iii. sudo ip link add dev vcan0 type vcan
      iv. sudo ip link set up vcan0
