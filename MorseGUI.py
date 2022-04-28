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
win.title("Morse code messenger")
button_font = tkinter.font.Font(family="Helvetica", size=32, weight="bold")
message_font = tkinter.font.Font(family="Helvetica", size=16, slant="italic")
v = tkinter.StringVar()
v.set(1)


def close():
    """
    Exit procedure for GUI application
    """
    GPIO.cleanup()
    window.destroy()


def morse_code(user_input):
    """
    A utility for converting user input to morse code language of dots and dashes.
    English alphabet characters only.
    :param : User input object to be converted into morse code
    :return: Integer indicating success (1) or failure(-1) of the conversion
    """
    try:
        word = user_input.get()
        if(len(word) >= 12):
            raise Exception("Message must be 12 characters or less")
        if(word.isalpha() == False):
            raise Exception("Message contains characters outside the alphabet")
    except Exception:
        message.config(text = "Message must be 12 alphabet characters or less", fg="red")
        input_user.delete(0,END) # Reset user input box
        return -1

    for letter in word:
        result = ''
        match letter:
            case 'a':
                result += '.-'
            case 'b':
                result += '-..'
            case 'c':
                result += '-.-.'
            case 'd':
                result += '-..'
            case 'e':
                result += '.'
            case 'f':
                result += '..-.'
            case 'g':
                result += '--.'
            case 'h':
                result += '....'
            case 'i':
                result += '..'
            case 'j':
                result += '.---'
            case 'k':
                result += '-.-'
            case 'l':
                result += '.-..'
            case 'm':
                result += '--'
            case 'n':
                result += '-.'
            case 'o':
                result += '---'
            case 'p':
                result += '.--.'
            case 'q':
                result += '--.-'
            case 'r':
                result += '.-.'
            case 's':
                result += '...'
            case 't':
                result += '-'
            case 'u':
                result += '..-'
            case 'v':
                result += '...-'
            case 'w':
                result += '.--'
            case 'x':
                result += '-..-'
            case 'y':
                result += '-.--'
            case 'z':
                result += '--..'
            case _:
                result += ' '
                
        blink_led(result, light) # Output letter using led
        time.sleep(1) # Rest to differentiate between letters
        
    message.config(text = "Communicate in morse code... ", fg="black") # Reset message
    input_user.delete(0,END) # Reset user input box
    return 1


def blink_led(code, light):
    """
    A utility function to output morse code to the specified led.
    :param code: The morse letter to be performed by the embedded system
    :param light: The light to control blink output
    """
    for morse in code:
        if morse == '.':
            light.on()
            time.sleep(0.15)
            light.off()
            time.sleep(0.5)
        elif morse == '-':
            light.on()
            time.sleep(1)
            light.off()
            time.sleep(0.5)
        else:
            light.off()
            time.sleep(0.5)

"""
--------------
|Main program|
--------------
"""
# Setup LED
light = LED(21)

# Create text input field
input_label = Label(win, text="Enter message: ", font=button_font)
input_label.pack()
input_user = Entry(win, font=button_font)
input_user.pack()
message = Label(win, text="Communicate in morse code... ", font=message_font)
message.pack()

# Create submit button
submit = Button(win, text="Submit", font=button_font, command=partial(morse_code, input_user), bg="green",activebackground="green2", activeforeground="white", height=1, width=24)
submit.pack()

# Create exit button
exit_button = Button(win, text="Exit", font=button_font, command=close, bg="red3",activebackground="red", activeforeground="white", height=1, width=24)
exit_button.pack()
win.protocol("WM_DELETE_WINDOW", close)

win.mainloop()

