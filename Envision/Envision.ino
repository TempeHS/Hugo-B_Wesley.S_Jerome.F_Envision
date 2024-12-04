  long duration;
  int distance;

  void setup() {
    Serial.begin(9600);
    us_setup();
    speaker_setup();
  }

  void loop() {
    

    
    if (distance > 3 && distance < 100) { 
      int beepDelay = map(distance, 5, 25, 50, 100);
    
      tone(speakerPin, 1000, 100); 
      delay(beepDelay); 
    } else {
      noTone(speakerPin); 
    }

    delay(50); 
  }