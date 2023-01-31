// Constants for the pin numbers
const int IN1 = 6;
const int IN2 = 7;
const int IN3 = 8;
const int IN4 = 9;
const int ENA = 5;
const int ENB = 10;

// Constants for the infrared sensor pins
const int IR_LEFT_1 = A3;
const int IR_LEFT_2 = A4;
const int IR_RIGHT_1 = A0;
const int IR_RIGHT_2 = A1;

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

  // Set all the infrared sensor pins as inputs
  pinMode(IR_LEFT_1, INPUT);
  pinMode(IR_LEFT_2, INPUT);
  pinMode(IR_RIGHT_1, INPUT);
  pinMode(IR_RIGHT_2, INPUT);
}

void loop() {
  // Read the values of the infrared sensors
  int left1 = digitalRead(IR_LEFT_1);
  int left2 = digitalRead(IR_LEFT_2);
  int right1 = digitalRead(IR_RIGHT_1);
  int right2 = digitalRead(IR_RIGHT_2);

  // Check if the robot is over the line
  if (left1 == HIGH && left2 == HIGH && right1 == HIGH && right2 == HIGH) {
    driveForward();
  } else {
    // Check if the left side of the robot is over the line
    if (left1 == LOW || left2 == LOW)
    {
      // If one or both of the left sensors are off the line, turn left
      turnLeft();
    } else if (right1 == LOW || right2 == LOW) {
      // If one or both of the right sensors are off the line, turn right
      turnRight();
    } else {
      // If the robot is not over the line, stop
      stop();
    }
  }
}

void driveForward() {
  // Set both motors to drive forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  // Set the drive speed for both motors
  analogWrite(ENA, DRIVE_SPEED);
  analogWrite(ENB, DRIVE_SPEED);
}

void turnLeft() {
  // Set the left motor to stop
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  // Set the right motor to drive forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  // Set the drive speed for both motors
  analogWrite(ENA, 0);
  analogWrite(ENB, DRIVE_SPEED);
}

void turnRight() {
  // Set the left motor to drive forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // Set the right motor to stop
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  // Set the drive speed for both motors
  analogWrite(ENA, DRIVE_SPEED);
  analogWrite(ENB, 0);
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
