void setup() {
  // Set the pin connected to the LED as an output
  pinMode(13, OUTPUT);
}

void loop() {
  // Turn the LED on
  digitalWrite(13, HIGH);
  // Wait for 1 second
  delay(1000);
  // Turn the LED off
  digitalWrite(13, LOW);
  // Wait for 1 second
  delay(100);
}
