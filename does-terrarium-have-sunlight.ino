const pin_t LED = D7;
const pin_t LIGHT_SENSOR = A0;


void setup() {
    pinMode(LED, OUTPUT);
    pinMode(LIGHT_SENSOR,  INPUT);
}

bool sunlightHitting = false;

void loop() {
    
    auto hasUpdated = false;
    
    auto reading = analogRead(LIGHT_SENSOR);
    
    if (reading > 50) {
        if (!sunlightHitting) {
            sunlightHitting = true;
            hasUpdated = true;
        }
    } else {
        if (sunlightHitting) {
            sunlightHitting = false;
            hasUpdated = true;
        }
    }
    
    if (hasUpdated) {
        Particle.publish("sunlightHittingStateChange", sunlightHitting ? "true" : "false");
    }
    
    
    delay(30 * 1000);
} 