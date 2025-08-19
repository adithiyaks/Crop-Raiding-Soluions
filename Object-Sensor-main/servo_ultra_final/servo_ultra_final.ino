// Includes the Servo library
#include <Servo.h>
// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin = 3;
const int echoPin = 2;
// Variables for the duration and the distance
const int buzzerPin = 9;

long duration;
Servo myServo;
 // Creates a servo object for controlling the servo motor
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  myServo.attach(4); // Defi
int distance;nes on which pin is the servo motor attached
}

// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
void Buzzer(){
       if (Serial.available() > 0) {
           char receivedChar = Serial.read();
           if (receivedChar == 'D') {
               // Code to emit deer sound
               tone(buzzerPin, 1000);  // Example tone for deer
               delay(1000);  // Duration
               noTone(buzzerPin);  // Turn off the buzzer
           } else if (receivedChar == 'E') {
               // Code to emit elephant sound
               tone(buzzerPin, 2000);  // Example tone for elephant
               delay(1000);  // Duration
               noTone(buzzerPin);  // Turn off the buzzer
           }
       }
     }
void loop() {
  // rotates the servo motor from 15 to 165 degrees
  for(int i=0;i<=180;i++){  
  myServo.write(i);
  delay(5);
  distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree

  //checkin for animal

  if(distance<20 && distance !=0){
  if (Serial.available() > 0) {
           char receivedChar = Serial.read();
           Serial.print(receivedChar);
           if (receivedChar == 'D') {
               // Code to emit deer sound
               tone(buzzerPin, 1000);  // Example tone for deer
               delay(1000);  // Duration
               noTone(buzzerPin);  // Turn off the buzzer
           } else if (receivedChar == 'E') {
               // Code to emit elephant sound
               tone(buzzerPin, 2000);  // Example tone for elephant
               delay(1000);  // Duration
               noTone(buzzerPin);  // Turn off the buzzer
           }
       }
    myServo.write(i);   
               // tell servo to go to position in variable 'pos'
    delay(2000);
  }
  }
  // Repeats the previous lines from 165 to 15 degrees
  for(int i=180;i>0;i--){  
  myServo.write(i);
  delay(5);
  distance = calculateDistance();
  //checkin for animal on next rotation

  if(distance<20 && distance !=0){
  if (Serial.available() > 0) {
           char receivedChar = Serial.read();
           Serial.print(receivedChar);
           if (receivedChar == 'D') {
               // Code to emit deer sound
               tone(buzzerPin, 1000);  // Example tone for deer
               delay(1000);  // Duration
               noTone(buzzerPin);  // Turn off the buzzer
           } else if (receivedChar == 'E') {
               // Code to emit elephant sound
               tone(buzzerPin, 2000);  // Example tone for elephant
               delay(1000);  // Duration
               noTone(buzzerPin);  // Turn off the buzzer
           }
       }
    myServo.write(i);  
                // tell servo to go to position in variable 'pos'
    delay(2000);
  }
  }
}
