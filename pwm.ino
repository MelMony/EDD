import RPi.GPIO as GPIO
from time import sleep, time

SPEED = 17150
TONE = 10000
CYCLE = 10

# Setup pins
TRIGGER = 20
ECHO = 21
BUZZER = 18

GPIO.setmode(GPIO.BCM)
GPIO.setup(TRIGGER, GPIO.OUT)
GPIO.setup(ECHO, GPIO.IN)
GPIO.setup(BUZZER, GPIO.OUT)


# Calibrate sensor
GPIO.setup(TRIGGER, False)  # Set to low on start-up
sleep(2)

"""
  
"""
def measure_distance():
    # Time measurements
    start, end = 0, 0

    # Start sensing range with pulse signal
    GPIO.output(TRIGGER, True)
    sleep(0.00001)
    GPIO.output(TRIGGER, False)

    # Measure response
    while GPIO.input(ECHO) == 0:
        start = time()
    while GPIO.input(ECHO) == 1:
        end = time()

    # Calculate distance
    result = (end - start) * SPEED

    return result


def sound_buzzer(frequency):
    buzz.ChangeFrequency(frequency)


# Program
print("Program Start")
buzz = GPIO.PWM(BUZZER, CYCLE) # Set-up buzzer
buzz.start(CYCLE)
try:
    while True:
        distance = measure_distance()
        print(f'The current distance is {round(distance, 2)} cm')
        sound_buzzer(TONE / distance) # Pitch decreases as distance increases
        sleep(0.1)  # Measurement interval

except KeyboardInterrupt:
    buzz.stop()
    GPIO.cleanup()
    print("Program exit")

