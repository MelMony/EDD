// Declaration of variables
const pin_t ONBOARDLED = D7; 
const pin_t REDLED = D6;


// Run code immediately at startup
SYSTEM_THREAD(ENABLED);

void setup() {

    //Setting LEDs to output
    pinMode(ONBOARDLED, OUTPUT);
    pinMode(REDLED, OUTPUT);
    
}


void loop() {
    
    
    //M
    morse('-');
    morse('-');
    
    morse(' ');
    
    
    //E
    morse('.');
    
    morse(' ');
    
    //L
    morse('.');
    morse('-');
    morse('.');
    morse('.');
    
    morse(' ');
    
    //I
    morse('.');
    morse('.');
    
    morse(' ');    
    
    
    //S
    
    morse('.');
    morse('.');
    morse('.');
    
    morse(' ');
    
    //S
    morse('.');
    morse('.');
    morse('.');
    
    morse(' ');
    
    //A
    morse('.');
    morse('-');
    
    morse(' ');
    
    
    delay(5000); //End of cycle

    
}

 void morse(char length) 
{
    //Precondition: A string corresponding to the desired morse code length
    //Postcondition: Changes the output of the led on and off

    if (length == '.')
    {
        digitalWrite(ONBOARDLED, HIGH);
        digitalWrite(REDLED, HIGH);
        delay(150);
        digitalWrite(ONBOARDLED, LOW);
        digitalWrite(REDLED, LOW);
        delay(500);
    }
    else if (length == '-')
    {
        digitalWrite(ONBOARDLED, HIGH);
        digitalWrite(REDLED, HIGH);
        delay(1000);
        digitalWrite(ONBOARDLED, LOW);
        digitalWrite(REDLED, LOW);
        delay(500);
    }
    else
    {
    digitalWrite(ONBOARDLED, LOW);
    digitalWrite(REDLED, LOW);
    delay(500); //space
    }
}
