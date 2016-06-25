/*
   Gina Knox's Code
  3 IR Receivers are connected to a robot, an anklet of IR LED's are connected to a human
  the robot determines goes in the direction of the direction of the light
  The anklet is going to use a Gemma board. 
*/

// The "const" keyword prevents these variables from changing
const int enable1 = 6; // PWM pin for speed control
const int in1 = 4;
const int in2 = 2;

// Control pins for the right half of the H-bridge
const int enable2 = 3; // PWM pin for speed control
const int in3 = 8;
const int in4 = 7;

// IR Receivers THESE ARE NOT DEFIEND YET BECAUSE IDK HOW TO USE THEM!
const int rightReceiver =
  const int frontReceiver =
    const int leftReceiver =

void setup () {
  //Setting up the motors as outputs
  pinMode( enable1, OUTPUT);
  pinMode( in1, OUTPUT);
  pinMode( in2, OUTPUT);

  pinMode( enable2, OUTPUT);
  pinMode( in3, OUTPUT);
  pinMode( in4, OUTPUT);
  Serial.begin(9600);

  //Setting speed for motors
  analogWrite (enable1, 200);
  analogWrite (enable2, 200);
}

void loop () {

  if (digitalRead (rightReceiver) == HIGH ) {
    // Turn right for 1 second - the time may need to be adjusted
    goRight(1000);
    Serial.println("I am going right!");

  } else {

  }

  if (digitalRead (forwardReceiver) == HIGH ) {
    // Go forward for 1 second - the time may need to be adjusted
    goForward(1000);
    Serial.println("I am going forward!");

  } else {

  }

  if (digitalRead (leftReceiver) == HIGH ) {
    // Turn left for 1 second - the time may need to be adjusted
    goLeft(1000);
    Serial.println("I am going left!");

  } else {

  }
}//end loop

// go forward for a certain amount of time
void goForward(int timeToMove) {

  // right motor
  digitalWrite (in1, HIGH);
  digitalWrite (in2, LOW);
  // left motor
  digitalWrite (in3, LOW);
  digitalWrite (in4, HIGH);

  delay (timeToMove);
}

// turn left for a certain amount of time
void goLeft(int timeToMove) {

  // right motor 
  digitalWrite (in1, LOW);
  digitalWrite (in2, HIGH);
  // left motor
  digitalWrite (in3, LOW);
  digitalWrite (in4, HIGH);

  delay (timeToMove);
}

// turn right for a certain amount of time
void goRight(int timeToMove) {

  // right motor
  digitalWrite (in1, HIGH);
  digitalWrite (in2, LOW);
  //left motor
  digitalWrite (in3, HIGH);
  digitalWrite (in4, LOW);

  delay (timeToMove);
}
