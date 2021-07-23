from gpiozero import DistanceSensor
from gpiozero import Buzzer
import RPi.GPIO as GPIO
from time import sleep

GPIO.setmode(GPIO.BCM)
GPIO.setup(17, GPIO.OUT, initial = GPIO.LOW)
GPIO.setwarnings(False)

sensor = DistanceSensor(trigger = 18, echo = 24)
buzzer = GPIO.PWM(17, 440)

count = 0

sleep(2)

buzzer.start(50)

try:
    
    while 1:
        
        distance = sensor.distance * 100
        distance = round(sensor.distance, 2)
        print("Distance: {} cm".format(sensor.distance))

        
        if distance < 0.1:
            buzzer.ChangeFrequency(100)
            print("Distance lower than 0.1")
                        
        elif distance > 0.1 and distance < 0.3:
            buzzer.ChangeFrequency(200)
            print("Distance between 0.1 - 0.3")
            
        elif distance > 0.3 and distance < 0.5:
            buzzer.ChangeFrequency(300)
            print("Distance between 0.3 - 0.5")
            
        elif distance > 0.5 and distance < 0.7:
            buzzer.ChangeFrequency(400)
            print("Distance between 0.5 - 0.7")
            
        sleep(1)
            
except KeyboardInterrupt:
    print("Keyboard interupt")
    buzzer.stop()
    GPIO.cleanup()
        
