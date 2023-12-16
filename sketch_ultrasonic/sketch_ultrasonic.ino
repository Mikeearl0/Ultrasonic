// defines pins numbers
// ground and earth for the Ultrasonic sensor
// pin 11 and ground for buzzer
// pin 5, 6 and 3 for LED into 220ohm recievers and ground from longest pin
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int redPin = 5;
const int greenPin = 6;
const int bluePin = 3;
float new_delay; 


// defines variables
long duration;
int distance;
int safetyDistance;


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}

void setColour(int red, int green, int blue) {
  analogWrite(redPin,red);
  analogWrite(greenPin,green);
  analogWrite(bluePin,blue);
}


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
new_delay= (distance *3) +30;

// Calculating the distance
distance = (duration/2) / 29.1;

safetyDistance = distance;

if (safetyDistance <= 76 && safetyDistance > 75){
  digitalWrite(buzzer, LOW);
  delay(new_delay);
  digitalWrite(buzzer, LOW);

  
}

 else if (safetyDistance <= 75 && safetyDistance > 50){
  digitalWrite(buzzer, HIGH);
  delay(new_delay);
  digitalWrite(buzzer, LOW);
  setColour(49, 61, 232);
  delay(new_delay);
  setColour(49, 61, 232);
  
}

 else if (safetyDistance <= 50 && safetyDistance > 25){
  digitalWrite(buzzer, HIGH);
  delay(new_delay);
  digitalWrite(buzzer, LOW);
  setColour(128, 0, 128);
  delay(new_delay);
  setColour(128, 0, 128);
  
}
else if (safetyDistance <= 25 && safetyDistance > 15) {
  digitalWrite(buzzer, HIGH);
  delay(new_delay);
  digitalWrite(buzzer, LOW);
  setColour(0, 255, 0);
  delay(new_delay);
  setColour(0, 255, 0);

}
else if(safetyDistance <= 15 && safetyDistance > 7.5) {
  digitalWrite(buzzer, HIGH);
  delay(new_delay);
  digitalWrite(buzzer, LOW);
  setColour(255, 100, 0);
  delay(new_delay);
  setColour(255, 100, 0);

}

else if(safetyDistance <= 7.5) {
  digitalWrite(buzzer, HIGH);
  delay(new_delay);
  digitalWrite(buzzer, LOW);
  setColour(255, 0, 0);
  delay(new_delay);
  setColour(255, 0, 0);

}
else{
  digitalWrite(buzzer, LOW);
  setColour(0, 0, 0);
  
}

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}
