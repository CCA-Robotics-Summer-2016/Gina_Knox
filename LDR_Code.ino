/*
   Gina Knox's Code
   Two light sensors added to the H-bridge to make a light seeking robot
 
   This program corresponds to the schematics here:
   Arduino Tutorial: How to use an H-Bridge with Arduino to control a permanent magnet DC motor
   and here:
   Arduino Tutorial: How to use an H-Bridge with Arduino to control a permanent magnet DC motor
*/
 
// The "const" keyword prevents these variables from changing
const int enable1 = 6; // PWM pin for speed control
const int in1 = 4;
const int in2 = 2;

// Control pins for the right half of the H-bridge
const int enable2 = 3; // PWM pin for speed control
const int in3 = 8;
const int in4 = 7;
 
// light sensors
const int leftLDR = A0;
const int rightLDR = A1;
 
void setup () {
  pinMode( enable1, OUTPUT);
  pinMode( in1, OUTPUT);
  pinMode( in2, OUTPUT);
 
  pinMode( enable2, OUTPUT);
  pinMode( in3, OUTPUT);
  pinMode( in4, OUTPUT);
  Serial.begin(9600);
  
  analogWrite (enable1, 200);
  analogWrite (enable2, 200);
}
 
void loop () {
 
  if (analogRead (leftLDR) > analogRead (rightLDR) ) {
    // Turn left for 1 second - the time may need to be adjusted
    goLeft(1000);
    Serial.println("I am turning right");
    
  } else {
    // Turn Right for 1 second - the time may need to be adjusted
    goRight(2000);
    Serial.println("I am turning left");
  }
}

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
