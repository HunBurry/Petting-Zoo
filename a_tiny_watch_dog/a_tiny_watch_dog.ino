/*
 * "Watch Dog"
 * This animal reacts to loud sounds by "barking",
 * acting as a guard dog or watch dog. 
 */

int echo, trig, buzzer;
boolean runn;

void setup() {
  /*
   * Basic I/O device setup. 
   */
  echo = 3;
  trig = 4;
  buzzer = 2;
  ///pinMode(sensor, INPUT);
  pinMode(buzzer, OUTPUT);
  runn = true;
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
}

void loop() {
  /*
   * If we detect a sound loud enough
   * to trigger the sound sensor, we 
   * begin to bark for a time period. 
   */
   bark(detectMovement());
}

int detectMovement() {
  /*
   * Determines if the sound sensor is
   * picking up noise. If so, return true,
   * if not, return false. 
   */
   long durat, inches, cm;
   ///pinMode(trig, OUTPUT);
   digitalWrite(trig, LOW);
   delayMicroseconds(2);
   digitalWrite(trig, HIGH);
   delayMicroseconds(10);
   digitalWrite(trig, LOW);
   ///pinMode(echo, INPUT);
   durat = pulseIn(echo, HIGH);
   inches = durat / 74 / 2;

   
  if (inches <= 1) {
    return 1;
  }
  else if (inches <= 6) {
    return 2;
  }
  else if (inches <= 12) {
    return 3;
  }
  else {
    return 0;
  }
}

void bark(int choice) {
  /*
   * Pick a random number to determine what
   * type of bark is generated. We have either
   * two short barks with a pause between them, 
   * three quick yips/barks, and one longer, higher
   * pitched howl. 
   */
  if (choice == 1) { //bark, pause, bark
    tone(buzzer, 1000, 500);
    delay(1000);
    tone(buzzer, 1000, 500); 
  }
  else if (choice == 2) { ///bark, bark, bark
    tone(buzzer, 2000, 300);
    delay(500);
    tone(buzzer, 2000, 300);
    delay(500);
    tone(buzzer, 2000, 300);
  }
  else if (choice == 3) { //howl
    tone(buzzer, 3500, 1500);
    delay(2000);
  }
}
