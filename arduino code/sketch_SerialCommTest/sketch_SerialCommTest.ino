int data = 0;

void setup() {
    Serial.begin(9600); // Start serial communication
    while (!Serial) {}  // Wait for serial connection (only necessary for some boards)
    pinMode(13, OUTPUT);
}

void loop() {
    if (Serial.available() > 0) {
        String data = Serial.readStringUntil('\n');  // Read incoming data until newline
        int commaIndex = data.indexOf(',');
        
        if (commaIndex > 0) {  // Ensure valid data
            int x = data.substring(0, commaIndex).toInt();
            int y = data.substring(commaIndex + 1).toInt();

            Serial.print("Received X: ");
            Serial.print(x);
            Serial.print(", Y: ");
            Serial.println(y);

            for (int i = 0; i < x; i++) {
                digitalWrite(13, HIGH);
                delay(500);
                digitalWrite(13, LOW);
                delay(500);
            }

        }

    }
}