
#include <Servo.h>

const int ultrasonicPin = 7;
const int speakerPin = 6;

long duration;
int distance;


void setup() {

  Serial.begin(9600);
  pinMode(ultrasonicPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
}

void loop() {

  pinMode(ultrasonicPin, OUTPUT); 
  digitalWrite(ultrasonicPin, LOW);
  delayMicroseconds(2);
  digitalWrite(ultrasonicPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonicPin, LOW);

  pinMode(ultrasonicPin, INPUT); 
  duration = pulseIn(ultrasonicPin, HIGH);

  distance = duration * 0.035 / 2;

  Serial.println(distance);

  if (distance > 30 && distance < 150) { 
    tone(speakerPin, 1000, 100); 
  } else {
    noTone(speakerPin); 
  }

  delay(1000); 
}