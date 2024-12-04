
#include <Servo.h>

// pin for sensor
const int ultrasonicPin = 7;

// pin for speaker
const int speakerPin = 6;

// Variables for distance measurement
long duration;
int distance;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set up the ultrasonic sensor pin
  pinMode(ultrasonicPin, OUTPUT);

  // Set up the speaker pin
  pinMode(speakerPin, OUTPUT)
}

void loop() {
  // Trigger the ultrasonic sensor
  pinMode(ultrasonicPin, OUTPUT); 
  digitalWrite(ultrasonicPin, LOW);
  delayMicroseconds(2);
  digitalWrite(ultrasonicPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonicPin, LOW);

  // Measure the echo time
  pinMode(ultrasonicPin, INPUT); 
  duration = pulseIn(ultrasonicPin, HIGH);

  // distance in cm
  distance = duration * 0.035 / 2;

  // distance to the Serial Monitor
  Serial.println(distance);

  // sound if the object is closer than 1 metre
  if (distance > 0 && distance < 150) { // Ignore 0 distance
    tone(speakerPin, 1000, 100); 
  } else {
    noTone(speakerPin); 
  }

  delay(1000); 
}
