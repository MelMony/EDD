from smbus import SMBus
import time

ADDRESS = 0x8  # Communication address
CHANNEL = SMBus(1)  # Connect device using channel

try:
    while(True):
        print("~~~I2C Messaging App~~~")
        message = input("Please enter a message to send to the arduino UNO: ")
    
        for c in message:
            convert = ord(c)
            CHANNEL.write_byte(ADDRESS, convert) # Send message via I2C
        print("Message sent!")
        
        time.sleep(len(message)/2) # Wait for receipt from slave
        confirmation = CHANNEL.read_byte(ADDRESS)
        if confirmation == 1:
            print("Message received by Arduino")
        else:
            print("Message not received - Try again...")
        
except KeyboardInterrupt:
    print("Program exit")
