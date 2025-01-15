#define RELAY_PIN 5   // Pin connected to the relay
#define BUTTON_PIN 6  // Pin connected to the button

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(38400);
  while (!Serial);  // Wait for Serial monitor to connect (useful for boards like ESP32)

  // Set up the relay pin
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);  // Ensure the relay is off at startup
  Serial.println("Relay initialized to OFF.");

  // Set up the button pin
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.println("Button initialized with INPUT_PULLUP.");
}

void loop() {
  // Read the button state
  int buttonState = digitalRead(BUTTON_PIN);

  // Debug the button state
  if (buttonState == LOW) {
    Serial.println("Button pressed. Activating relay...");
    
    // Activate the relay
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Relay ON.");
    
    delay(1000);  // Keep relay on for 1 second
    
    // Deactivate the relay
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Relay OFF.");

    // Debounce delay
    delay(200);  
  } else {
    // Print debug info for button release (optional)
    Serial.println("Button not pressed.");
    delay(100);  // Reduce Serial flooding when the button isn't pressed
  }
}
