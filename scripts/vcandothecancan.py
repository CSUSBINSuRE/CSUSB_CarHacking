# VCanCanDoTheCanCan
# CAN / Virtual CAN
import os
import subprocess

# importing system processes so we can call the terminal
done = False
# bitrate = input('Please enter the bitrate of the vehicle ')
bitrate = str(500000)


#Main Program
def main():
    choice = ""
    while choice != "quit":
        print("Hello! Welcome to CSUSB Insure "
              "\n Press 1 to Open Cansniffer"
              "\n Press 2 to OPen ICSim Controls"
              "\n Press 3 to Open ICSimulator"
              "\n Press 4 to Open UDSimulator"
              "\n Press 5 to Perform CanDump"
              "\n Press 6 to Open All Above Programs"
              "\n Press 7 to start capture with WIRESHARK"
              "\n Press 8 to Change default bitrate"
              "\n Or type 'quit' to quit.")
        choice = input("Enter an option: ")

        if choice == "1":
            os.system("gnome-terminal -- cansniffer -c vcan0")   # opening cansniffer in new terminal
            os.system("clear")                                   # cleans up the terminal

        elif choice == "2":
            os.system("gnome-terminal --working-directory='/home/parrot/ICSim' -- ./controls vcan0")   # opening controls from ICSim directory
            os.system("clear")

        elif choice == "3":
            os.system("gnome-terminal --working-directory='/home/parrot/ICSim' -- ./icsim vcan0")      # opening ICSim from ICSim directory
            os.system("clear")

        elif choice == "4":
            os.system("gnome-terminal --working-directory='/opt/car-hacking/UDSim/src' -- ./udsim vcan0") # opening UDsim
            os.system("clear")

        elif choice == "5":
            # os.system("gnome-terminal --working-directory='/home/parrot/can-utils' -- ./candump vcan0")
            os.system("clear")

        elif choice == "6":     # open all
            os.system("gnome-terminal -- cansniffer -c vcan0")
            os.system("gnome-terminal --working-directory='/home/parrot/ICSim' -- ./controls vcan0")
            os.system("gnome-terminal --working-directory='/home/parrot/ICSim' -- ./icsim vcan0")
            os.system("gnome-terminal --working-directory='/opt/car-hacking/UDSim/src' -- ./udsim vcan0")
            # os.system("gnome-terminal --working-directory='/home/parrot/can-utils' -- ./candump vcan0")
            os.system("clear")

        elif choice == "7":
            os.system("wireshark -i vcan0 -k")
            # Starting wireshark and immediately start capturing via vcan0 (can change wear it is capturing)
            os.system("clear")

        elif choice == "8":
            bitrate = input('What would you like to set the bitrate to: ')
            os.system("clear")

        else:
            os.system("clear")
            print('Sorry, That was not one of the options, Please be sure to read through the options available')

main()
