const int numberOfReadings = 600;
int measurements[numberOfReadings];
const int ldrPin = A0;
 
void setup() {
  Serial.begin(9600);
}
 
 
void loop() {

  
 //Read ever 2nd # after 0 
  for (int evenReadings = 0; evenReadings < numberOfReadings; evenReadings+2) {
    measurements[evenReadings] = analogRead(ldrPin);
    delay(1);
  }
 
 
  // calculate the average
  int sum = 0;
 
  for (int evenReadings = 0; evenReadings < numberOfReadings; evenReadings+2) {
    sum = sum + measurements[evenReadings];
  }
 
  int average = sum / numberOfReadings;
 
  // what's the difference between print() and println()?
  Serial.print("the even readings are ");
  Serial.println(measurements[highestReading()]);
}
 
// return the index of the highest reading
// if there are multiple readings return one of them
int highestReading() {
 
  int latestHighestReading = 0;
 
  for (int evenReadings = 0; evenReadings < numberOfReadings; evenReadings+2) 
  { 
    if (measurements[evenReadings] > measurements[latestHighestReading]) 
    {
      latestHighestReading = evenReadings;
    }
  }
  return latestHighestReading;
 
}
