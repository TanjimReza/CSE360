// Define pin numbers
const int LED_PIN = 6;
const int MAGNETIC_REED_PIN = 7;
const int LDR_PIN = 8;
const int PIR_PIN = 9;

// Declare variables to store sensor states
int LDR_STATE = 0;
int PIR_STATE = 0;
int REED_STATE = 0;

void setup() {
    // Begin serial communication
    Serial.begin(9600);
    // Set pin modes
    pinMode(MAGNETIC_REED_PIN, INPUT);
    pinMode(LDR_PIN, INPUT);
    pinMode(PIR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    // Read state of magnetic reed switch
    REED_STATE = digitalRead(MAGNETIC_REED_PIN);

    // If magnetic reed switch is closed
    if (REED_STATE > 0) {
        // Read state of LDR
        LDR_STATE = digitalRead(LDR_PIN);

        // If LDR detects low light
        if (LDR_STATE != 0) {
            // Read state of PIR sensor
            PIR_STATE = digitalRead(PIR_PIN);

            // If PIR sensor detects movement
            if (PIR_STATE > 0) {
                // Turn on LED
                digitalWrite(LED_PIN, HIGH);

                // Send notification via serial communication
                Serial.write("1");

                // Wait 2 seconds
                delay(2000);
            }
            // If PIR sensor doesn't detect movement
            else {
                // Turn off LED
                digitalWrite(LED_PIN, LOW);
            }
        }
        // If LDR doesn't detect low light
        else {
            // Turn off LED
            digitalWrite(LED_PIN, LOW);
        }
    }
    // If magnetic reed switch is open
    else {
        // Turn off LED
        digitalWrite(LED_PIN, LOW);
    }
}