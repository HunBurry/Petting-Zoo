/*
 * "Watch Dog"
 * This animal reacts to loud sounds by "barking",
 * acting as a guard dog or watch dog. 
 */

int sensor, buzzer;

void setup() {
  /*
   * Basic I/O device setup. 
   */
  sensor = 2;
  buzzer = 3;
  pinMode(sensor, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  /*
   * If we detect a sound loud enough
   * to trigger the sound sensor, we 
   * begin to bark for a time period. 
   */
  if (detectSound()) {
    bark();
  }
}

boolean detectSound() {
  /*
   * Determines if the sound sensor is
   * picking up noise. If so, return true,
   * if not, return false. 
   */
  if (digitalRead(sensor) == HIGH) {
    return true;
  }
  else {
    return false;
  }
}

void bark() {
  /*
   * Pick a random number to determine what
   * type of bark is generated. We have either
   * two short barks with a pause between them, 
   * three quick yips/barks, and one longer, higher
   * pitched howl. 
   */
  int choice = random(1, 4);
  if (choice == 1) { //bark, pause, bark
    tone(buzzer, 2000, 500);
    delay(500);
    tone(buzzer, 2000, 500); 
  }
  else if (choice == 2) { ///bark, bark, bark
    tone(buzzer, 2000, 300);
    tone(buzzer, 2000, 300);
    tone(buzzer, 2000, 300);
  }
  else { //howl
    tone(buzzer, 3500, 1500);
  }
}
