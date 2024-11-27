
#include <Servo.h>

// pins
const int ultrasonicPin = 7;
const int speakerPin = 6;

// distance measurement
long duration;
int distance;

void setup() {

  Serial.begin(9600);
  pinMode(ultrasonicPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  // trigger the ultrasonic sensor
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
  if (distance > 0 && distance < 150) { 
    tone(speakerPin, 1000, 100); 
  } else {
    noTone(speakerPin); 
  }

  delay(1000); 
}