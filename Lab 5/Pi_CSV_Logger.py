import os
import RPi.GPIO as GPIO
import time
from datetime import datetime


logfile = open("/home/pi/Desktop/Lab6/log.csv","a")
logfile.write(datetime.now().strftime("Program Starting,%Y/%m/%d,%H:%M \n"))
logfile.close()
print(datetime.now().strftime("Program Starting -- %Y/%m/%d -- %H:%M  -- Hello! \n"))

print (" Control + C to exit Program")

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

GPIO.setup(17, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)   # Green LED
GPIO.setup(27, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)   # Yellow LED
GPIO.setup(22, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)   # Red LED
time.sleep(1)

try:
        while 1 >= 0:
         time.sleep(1)

         if GPIO.input(17) == GPIO.LOW and GPIO.input(27) == GPIO.HIGH and GPIO.input(22) == GPIO.LOW:  # Door Closing/Opening
           logfile = open("/home/pi/Desktop/Lab6/log.csv","a")
           logfile.write(datetime.now().strftime("Opening/Closing,%Y/%m/%d,%H:%M:%S \n"))
           logfile.close()
           print(datetime.now().strftime("%Y/%m/%d -- %H:%M:%S  -- Door Opening/Closing \n"))  # Used for debugging
         
         if GPIO.input(17) == GPIO.LOW and GPIO.input(27) == GPIO.LOW and GPIO.input(22) == GPIO.HIGH:  # Door is Closed
           logfile = open("/home/pi/Desktop/Lab6/log.csv","a")
           logfile.write(datetime.now().strftime("Closed,%Y/%m/%d,%H:%M:%S \n"))
           logfile.close()
           print(datetime.now().strftime("%Y/%m/%d -- %H:%M:%S  -- Door Closed \n"))  # Used for debugging
         
         if GPIO.input(17) == GPIO.HIGH and GPIO.input(27) == GPIO.LOW and GPIO.input(22) == GPIO.LOW:  #Door is Open
           logfile = open("/home/pi/Desktop/Lab6/log.csv","a")
           logfile.write(datetime.now().strftime("Opened,%Y/%m/%d,%H:%M:%S \n"))
           logfile.close()
           print(datetime.now().strftime("%Y/%m/%d -- %H:%M:%S  -- Door Open \n"))  # Used for debugging

except KeyboardInterrupt:
        logfile = open("/home/pi/Desktop/Lab6/log.csv","a")
        logfile.write(datetime.now().strftime("Log Program Shutdown,%Y/%m/%d,%H:%M \n"))
        logfile.close()
        print(datetime.now().strftime("Log Program Shutdown -- %Y/%m/%d -- %H:%M  -- Goodbye! \n"))
        GPIO.cleanup()