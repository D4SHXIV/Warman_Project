// Version 3.0
// 20.05.2026
// Authors: Sandy, Oscar, Nicole, Jess, Dash
// Controls the movement if the robot
// Moves up the ramp ghen opens the arms and rotates
// servo to contorl the curtain arm


#include <Servo.h>

// initialise servos
Servo leftArm
Servo rightArm


// initialise motor pins
#define M1_PWM 6
#define M1_DIR 7

#define M2_PWM 3
#define M2_DIR 8

#define M3_PWM 5
#define M3_DIR 12

#define M4_PWM 11
#define M4_DIR 13


// button
#define BUTTON_PIN = 24;
#define  LED_PIN = 28;

bool ledState = false;
int lastButtonState = HIGH;

// motor speed
int speedMotor = 180;   // 0 - 255
int pos = 0; 

//functions

void forward(int speedVal)
void backward(int speedVal) 
void rotate(int speedVal)
void left(int speedVal) 
void right(int speedVal)
void stopMotors()

// 
//setup

void setup() {

  //servo
  rod.attach(9);
  leftArm.attach(10)


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

// 
// main loop
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

//
// forward
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

// 
// backward
// 
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

//
// rotate

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

// 
// LEFT TURN
// Left wheels backward
// Right wheels forward

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

// RIGHT TURN
// Left wheels forward
// Right wheels backward

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

// 
// stop wheels moving
// 
void stopMotors() {

  analogWrite(M1_PWM, 0);
  analogWrite(M2_PWM, 0);
  analogWrite(M3_PWM, 0);
  analogWrite(M4_PWM, 0);
}

// 



