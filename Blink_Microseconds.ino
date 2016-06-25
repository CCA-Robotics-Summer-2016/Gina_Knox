long var = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  // initialize digital pin 13 as an output.
  pinMode(3, OUTPUT);

}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delayMicroseconds(4);              // wait for a second
  digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
  delayMicroseconds(4);  // wait for a second

  if (millis() < 1000) {
    var ++;
  } else {
    Serial.println(var); //Test again when done with everything else.
  }
  
}
