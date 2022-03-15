// Set Analogue pin 1 to the ambient light sensor 
#define LIGHTSENSOR A1

// Measurement variable for light reading
int measurement;


void setup() {
    pinMode(LIGHTSENSOR, INPUT); // Set light sensor to input mode
}

void loop() {
    measurement = analogRead(LIGHTSENSOR); // Take reading from sensor
    String light = String(measurement);     // Convert the data coming from the sensor into a string format
    Particle.publish("Light", light, PRIVATE); // Sends data to particle console
    delay(30000); // Take a reading every 30 seconds
}
