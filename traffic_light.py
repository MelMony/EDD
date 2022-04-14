import RPi.GPIO as GPIO
from gpiozero import LED
import time
from tkinter import *
import tkinter.font
from functools import partial 

# Setup 
GPIO.setmode(GPIO.BCM)

# GUI Definitions
win = Tk()
win.title("LED Controller")
ledFont = tkinter.font.Font(family="Times New Roman", size=32, weight="bold")
exitFont = tkinter.font.Font(family="Times New Roman", size=20, weight="bold")
v = tkinter.StringVar()
v.set(1)
        
red = LED(21)
yellow = LED(20)
green = LED(16)

# Exit procedure for application
def close():
    GPIO.cleanup()
    win.destroy()

# Toggle procedure when button clicked
def toggle(light):
    # Turn all lights off
    red.off()
    yellow.off()
    green.off()
    # Return selection colours to neutral
    r["fg"] = "black"
    y["fg"] = "black"
    g["fg"] = "black"

    # Based on the light colour turn LED on and selection on in GUI
    if light == "red":
        red.on()
        r["fg"] = "white"
    elif light == "yellow":
        yellow.on()
        y["fg"] = "white"
    elif light == "green":
        green.on()
        g["fg"] = "white"

# Creation of buttons
r = Button(win, text="Red", font=ledFont, command=partial(toggle, "red"), bg="red3",activebackground="red", activeforeground="white", height=3, width=40)
r.pack()
y = Button(win, text="Yellow", font=ledFont, command=partial(toggle,"yellow"), bg="gold", activebackground="yellow2", activeforeground="white", height=3, width=40)
y.pack()
g = Button(win, text="Green", font=ledFont, command=partial(toggle,"green"), bg="green",activebackground="green2", activeforeground="white", height=3, width=40)
g.pack()
exit_button = Button(win, text="Exit", font=exitFont, command=close, bg="black", fg="white", height=1, width=24)
exit_button.pack()

win.protocol("WM_DELETE_WINDOW", close)

win.mainloop()

    
