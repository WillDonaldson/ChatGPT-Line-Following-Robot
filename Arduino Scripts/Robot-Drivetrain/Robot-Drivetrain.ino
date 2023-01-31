// Constants for the pin numbers
const int IN1 = 6;
const int IN2 = 7;
const int IN3 = 8;
const int IN4 = 9;
const int ENA = 5;
const int ENB = 10;

// Constants for the PWM drive speed
const int DRIVE_SPEED = 255;

void setup() {
  // Set all the pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  // Drive forward
  driveForward();
  delay(2000);

  // Reverse
  reverse();
  delay(2000);

  // Turn left
  left();
  delay(2000);

  // Turn right
  right();
  delay(2000);

  // Stop
  stop();
  delay(2000);
}

void driveForward() {
  // Set the left motor to drive forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // Set the right motor to drive forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  // Set the drive speed for both motors
  analogWrite(ENA, DRIVE_SPEED);
  analogWrite(ENB, DRIVE_SPEED);
}

void reverse() {
  // Set the left motor to reverse
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  // Set the right motor to reverse
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  // Set the drive speed for both motors
  analogWrite(ENA, DRIVE_SPEED);
  analogWrite(ENB, DRIVE_SPEED);
}

void left() {
  // Set the left motor to reverse
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  // Set the right motor to drive forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  // Set the drive speed for both motors
  analogWrite(ENA, DRIVE_SPEED);
  analogWrite(ENB, DRIVE_SPEED);
}

void right() {
  // Set the left motor to drive forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // Set the right motor to reverse
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  // Set the drive speed for both motors
  analogWrite(ENA, DRIVE_SPEED);
  analogWrite(ENB, DRIVE_SPEED);
}

void stop() {
  // Set both motors to stop
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  // Set the drive speed for both motors to 0
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
