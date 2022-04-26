
// Pin IDs for LEDs
const pin_t LEDRED = D4;
const pin_t LEDORANGE = D3;
const pin_t LEDGREEN = D2;


void setup() {
    
    // Set pin configuration to output
    pinMode(LEDRED, OUTPUT);
    pinMode(LEDORANGE, OUTPUT);
    pinMode(LEDGREEN, OUTPUT);
    
    // Particle cloud setup for led toggle function
    Particle.function("light", trafficLight);
    
    // All leds off when device turns on
    digitalWrite(LEDRED, LOW);
    digitalWrite(LEDORANGE, LOW);
    digitalWrite(LEDGREEN, LOW);

}

void loop() {


}


int trafficLight(String light)
{
    // All leds start in off position
    digitalWrite(LEDRED, LOW);
    digitalWrite(LEDORANGE, LOW);
    digitalWrite(LEDGREEN, LOW);
    
    if(light == "RED")
    {
        digitalWrite(LEDRED, HIGH);
        return 1;
    }
    else if(light == "ORANGE")
    {
        digitalWrite(LEDORANGE, HIGH);
        return 1;
    }
    else if(light == "GREEN")
    {
        digitalWrite(LEDGREEN, HIGH);
        return 1;
    }
    else
    {
        return -1;
    }
}
