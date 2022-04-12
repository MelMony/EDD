#include <queue>
using namespace std;

#define LIGHTSENSOR A1 //Pin the ambient light sensor is connected to
#define SUNLIGHT_THRESOLD 1000 // Threshold LUX we consider sunny
#define MEASUREMENT_FREQ 60000 // How often a measurement is taken from the sensor (currently 1x per minute)
#define SIZE 30 // How big to make the measurement archive before testing the trigger (Currently 30 reading or 30 mins before triggering event)

float measurement; // Measurement variable for light reading
bool sunny; // 
float averageMeasurement;
queue<float> measurementArchive;
int measurementCount;

void setup() {
    pinMode(LIGHTSENSOR, INPUT); // Set light sensor to input mode
    Serial.begin(9600); // For serial monitoring
    Particle.variable("sunny", sunny); // Monitored by IFTTT
    measurementCount = 0; // Initialise archive count 
    sunny = false;
}

void loop() {
    
    measurement = analogRead(LIGHTSENSOR); // Take reading from sensor
    Serial.println(measurement);
    
    measurementArchive.push(measurement); // Add new reading to archive

    delay(MEASUREMENT_FREQ);
    measurementCount++; 
    
    if (measurementCount == SIZE)
    {
        // Total the measurments from the archive
        while (measurementCount > 0)
        {
            averageMeasurement += measurementArchive.front(); // Add to total
            measurementArchive.pop(); // Remove from archive
            measurementCount--;
        }
        
        averageMeasurement /= SIZE; // Calculate the average reading 
        
        // Check if avaerage reading from the archive correlates to sunny or shady conditions
        sunny = averageMeasurement >= SUNLIGHT_THRESOLD ? true : false;
        Serial.println(sunny ? "Terrarium has reached sunlight thresold" : "Terrarium has fallen below sunlight thresold"); 
        Particle.publish("sunny", String(sunny));
        
        measurementCount = 0; // Reset archive count

    }
}
