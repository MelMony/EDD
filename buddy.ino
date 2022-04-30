const pin_t REDLED = D6;

void setup() 
{
    pinMode(REDLED, OUTPUT);
    
    Particle.subscribe("motionStatus", motionHandler);
}

void loop() 
{

    //Randomly trigger different events - nothing, wave or pat
    int random = rand() % 3;
    if (random == 1)
    {
        Particle.publish("motionStatus", "wave");
    }
    else if (random = 2)
    {
        Particle.publish("motionStatus", "pat");
    }
    
    delay(10000);
}

//Precondition: Cloud data for the published event in char form
//Postcondition: Handles motion event data responding with LED blinks
void motionHandler(const char *event, const char *data)
{
    // strcmp inbuilt functions compares string character by character returning 0 if equal
    if (strcmp(data, "wave") == 0)
    {
        toggleLED(300, 3); // 3 short blinks for a wave
    }
    else if (strcmp(data, "pat") == 0)
    {
        toggleLED(1000, 5); // 5 long blinks for a pat
    }
}

//Precondition: An integer duration for how long the led is lit and integer frequency for repetition of the procedure
//Postcondition: Blinks led on and off according to input specifications
void toggleLED(int duration, int frequency)
{
    for(int i = 0; i < frequency; i++)
    {
        digitalWrite(REDLED, HIGH);
        delay(duration);
        digitalWrite(REDLED, LOW);
        delay(duration);
    }
}
