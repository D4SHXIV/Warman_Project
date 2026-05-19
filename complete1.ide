
#include <Servo.h>

// ===== SERVO =====
Servo leftArm
Servo rightArm


// ===== MOTOR PINS =====
#define M1_PWM 6
#define M1_DIR 7

#define M2_PWM 3
#define M2_DIR 8

#define M3_PWM 5
#define M3_DIR 12

#define M4_PWM 11
#define M4_DIR 13

// ===== ROD RELAY =====
#define RELAY1 2    //rod
#define RELAY1 4    

// ===== BUTTONS =====
const int BUTTON_PIN = 24;
const int LED_PIN = 28;

bool ledState = false;
int lastButtonState = HIGH;

// ===== MOTOR SPEED =====
int speedMotor = 180;   // 0 - 255
int pos = 0; 

// =====================================
// SETUP
// =====================================
void setup() {

  //servo
  rod.attach(9);
  leftArm.attach(10)

  //relay
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);    //setting outputs

  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, LOW);    

  //motor Pins
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

    //move forward
    forward(speedMotor);
    delay(750);
    //at pick up point

    //stop
    stopMotors();

    //deploy arms
    for (pos = 0; pos <= 180; pos += 1) {             // goes from 0 degrees to 180 degrees in steps of 1 degree
      leftArm.write(pos);                             // tell servo to go to position in variable 'pos'
      rightArm.write(pos)
      delay(20);                       // waits 20ms for the servo to reach the position
    }

    //rotate rod to close door
    digitalWrite(RELAY1, HIGH);
    delay(5200);

    //bring arms back
    for (pos = 180; pos >= 0; pos -= 1) { 
      leftArm.write(pos);                             
      rightArm.write(pos)
      delay(20);                       // waits 20ms for the servo to reach the position
    }

    delay(1000); 


    backward(speedMotor);
    delay(750);

    stopMotors();
    delay(1000);
    
    rotate(speedMotor);
    delay(1085);

    // at base of ramp
    stopMotors();
    delay(1000);

    forward(speedMotor);
    delay(3700);

    // at top of ramp
    stopMotors();

    //
    //partially deploy arms
    for (pos = 0; pos <= 140; pos += 1) {             // goes from 0 degrees to 180 degrees in steps of 1 degree
      leftArm.write(pos);                             // tell servo to go to position in variable 'pos'
      rightArm.write(pos)
      delay(20);                       // waits 20ms for the servo to reach the position
    }

    //rotate rod to open door
    digitalWrite(RELAY2, HIGH);
    delay(1600);

    //bring arms back
    for (pos = 140; pos >= 0; pos -= 1) { 
      leftArm.write(pos);                             
      rightArm.write(pos)
      delay(20);                       // waits 20ms for the servo to reach the position
    }
    
    //roll down ramp
    backward(speedMotor);
    delay(3700);

    //at end point
    stopMotors();
    digitalWrite(LED_PIN, LOW);

  }
}

// =====================================
// FORWARD
// =====================================
void forward(int speedVal) {

  // Left side forward
  digitalWrite(M1_DIR, LOW);
  digitalWrite(M3_DIR, HIGH);

  // Right side backward
  digitalWrite(M2_DIR, LOW);
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
// ROTATE
// =====================================

void rotate(int speedVal) {
  digitalWrite(M1_DIR, HIGH);
  digitalWrite(M2_DIR, HIGH);
  digitalWrite(M3_DIR, HIGH);
  digitalWrite(M4_DIR, HIGH);

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

// =====================================
// STOP ALL MOTORS
// =====================================
void stopMotors() {

  analogWrite(M1_PWM, 0);
  analogWrite(M2_PWM, 0);
  analogWrite(M3_PWM, 0);
  analogWrite(M4_PWM, 0);
}

// =====================================
// DROP ARMS
// =====================================

void dropArm() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(40);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(40);                       // waits 15ms for the servo to reach the position
  }
}




