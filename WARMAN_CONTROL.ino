#include <Servo.h>

// ===== SERVO =====
Servo servo1;

// ===== MOTOR PINS =====
#define M1_PWM 6
#define M1_DIR 7

#define M2_PWM 3
#define M2_DIR 8

#define M3_PWM 5
#define M3_DIR 12

#define M4_PWM 11
#define M4_DIR 13

#define SERVO1 9

// ===== BUTTONS =====
const int BUTTON_PIN = 24;
const int LED_PIN = 28;

bool ledState = false;
int lastButtonState = HIGH;

// ===== MOTOR SPEED =====
int speedMotor = 180;   // 0 - 255

// =====================================
// SETUP
// =====================================
void setup() {

  // Servo
  servo1.attach(SERVO1);

  // Motor Pins
  pinMode(M1_PWM, OUTPUT);
  pinMode(M1_DIR, OUTPUT);

  pinMode(M2_PWM, OUTPUT);
  pinMode(M2_DIR, OUTPUT);

  pinMode(M3_PWM, OUTPUT);
  pinMode(M3_DIR, OUTPUT);

  pinMode(M4_PWM, OUTPUT);
  pinMode(M4_DIR, OUTPUT);

  //Button Setup
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  digitalWrite(LED_PIN, LOW);
}

// =====================================
// MAIN LOOP
// =====================================
void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  
   // Button was just pressed
  if (buttonState == LOW) {
    // control LED according to the state of button
    digitalWrite(LED_PIN, HIGH);

    // ===== FORWARD =====
    forward(speedMotor);
    delay(1000);

    backward(speedMotor);
    delay(1000);

    rotateRight(speedMotor);
    delay(1600);

    left(speedMotor);
    delay(500);

    backward(speedMotor);
    delay(4100);

    // ===== STOP =====
    stopMotors();
    delay(1000);
  } 
}

// =====================================
// FORWARD
// =====================================
void forward(int speedVal) {

  digitalWrite(M1_DIR, LOW);
  digitalWrite(M2_DIR, LOW);
  digitalWrite(M3_DIR, HIGH);
  digitalWrite(M4_DIR, HIGH);

  analogWrite(M1_PWM, speedVal);
  analogWrite(M2_PWM, speedVal);
  analogWrite(M3_PWM, speedVal);
  analogWrite(M4_PWM, speedVal);
}

// =====================================
// BACKWARD
// =====================================
void backward(int speedVal) {

  digitalWrite(M1_DIR, HIGH);
  digitalWrite(M2_DIR, HIGH);
  digitalWrite(M3_DIR, LOW);
  digitalWrite(M4_DIR, LOW);

  analogWrite(M1_PWM, speedVal);
  analogWrite(M2_PWM, speedVal);
  analogWrite(M3_PWM, speedVal);
  analogWrite(M4_PWM, speedVal);
}

// =====================================
// LEFT TURN
// Left wheels backward
// Right wheels forward
// =====================================
void left(int speedVal) {

  // Left side backward
  digitalWrite(M1_DIR, HIGH);
  digitalWrite(M3_DIR, HIGH);

  // Right side forward
  digitalWrite(M2_DIR, LOW);
  digitalWrite(M4_DIR, LOW);

  analogWrite(M1_PWM, speedVal);
  analogWrite(M2_PWM, speedVal);
  analogWrite(M3_PWM, speedVal);
  analogWrite(M4_PWM, speedVal);
}

// =====================================
// RIGHT TURN
// Left wheels forward
// Right wheels backward
// =====================================
void right(int speedVal) {

  // Left side forward
  digitalWrite(M1_DIR, HIGH);
  digitalWrite(M3_DIR, LOW);

  // Right side backward
  digitalWrite(M2_DIR, HIGH);
  digitalWrite(M4_DIR, LOW);

  analogWrite(M1_PWM, speedVal);
  analogWrite(M2_PWM, speedVal);
  analogWrite(M3_PWM, speedVal);
  analogWrite(M4_PWM, speedVal);
}

void rotateRight(int speedVal) {
  // Left side forward
  digitalWrite(M1_DIR, LOW);
  digitalWrite(M3_DIR, HIGH);

  // Right side backward
  digitalWrite(M2_DIR, HIGH);
  digitalWrite(M4_DIR, HIGH);

  analogWrite(M1_PWM, speedVal);
  analogWrite(M2_PWM, speedVal);
  analogWrite(M3_PWM, speedVal);
  analogWrite(M4_PWM, speedVal);
}

// =====================================
// STOP ALL MOTORS
// =====================================
void stopMotors() {

  analogWrite(M1_PWM, 0);
  analogWrite(M2_PWM, 0);
  analogWrite(M3_PWM, 0);
  analogWrite(M4_PWM, 0);
}
