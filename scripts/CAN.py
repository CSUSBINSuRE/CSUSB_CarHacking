#CAN / Virtual CAN
import os
import subprocess
#importing system processes so we can call the terminal
done = False
#bitrate = input('Please enter the bitrate of the vehicle ')
bitrate = str(500000)

while not done:
	
	
	mainmenu = input('Press 1 to Open Cansniffer\nPress 2 to Open Candump\nPress 3 to start capture with WIRESHARK\nPress 4 to Open All\nPress 5 to Change default bitrate\nPress 6 to Close BE SURE to save any captured data with Wireshark before closing\n')
	main_num = int(mainmenu)
	if main_num == 1:
		os.system("gnome-terminal --hide-menubar --geometry 80x10+0-0 -- cansniffer -c can0")
		#opening cansniffer in new terminal
		os.system("clear")
		#cleans up the terminal 
	#elif main_num == 2:
		#os.system("gnome-terminal --hide-menubar --geometry 40x5-0-0 --working-directory='/home/parrot/ICSim' -- ./controls vcan0")
		#opening controls from ICSim directory
		#os.system("clear")
	#elif main_num == 3:
		#os.system("gnome-terminal --hide-menubar --geometry 25x5-0+0 --working-directory='/home/parrot/ICSim' -- ./icsim vcan0")
		#opening ICSim from ICSim directory 
		#os.system("clear")
	#elif main_num == 4:
		#os.system("gnome-terminal --hide-menubar --geometry 25x5+0+0 --working-directory='/opt/car-hacking/UDSim/src' -- ./udsim vcan0")
		#opening UDsim
		#os.system("clear")
	elif main_num == 2:
		os.system("gnome-terminal --working-directory='/home/parrot/can-utils' -- candump can0")
		os.system("clear")
	elif main_num == 4: #open all 
		os.system("gnome-terminal --hide-menubar --geometry 80x10+0-0 -- cansniffer -c can0")
		#os.system("gnome-terminal --hide-menubar --geometry 40x5-0-0 --working-directory='/home/parrot/ICSim' -- ./controls vcan0")
		#os.system("gnome-terminal --hide-menubar --geometry 25x5-0+0 --working-directory='/home/parrot/ICSim' -- ./icsim vcan0")
		#os.system("gnome-terminal --hide-menubar --geometry 25x5+0+0 --working-directory='/opt/car-hacking/UDSim/src' -- ./udsim vcan0")
		os.system("gnome-terminal --working-directory='/home/parrot/can-utils' -- candump can0")
		os.system("gnome-terminal -- wireshark -i can0 -k")
		os.system("clear")
	elif main_num == 3:
		os.system("gnome-terminal -- wireshark -i can0 -k")
		#Starting wireshark and immediately start capturing via vcan0 (can change wear it is capturing) 
		os.system("clear")
	elif main_num == 5:
		bitrate = input('What would you like to set the bitrate to: ')
		os.system("clear")
	elif main_num == 6:
		done = True
	else:
		os.system("clear")
		print('That was not one of the options, Please be sure to read through the options available')
os.system("killall -KILL mate-terminal")
os.system("killall wireshark")
