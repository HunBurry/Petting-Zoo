/*
 * "Watch Dog"
 * This animal reacts to loud sounds by "barking",
 * acting as a guard dog or watch dog. 
 */

int sensor, buzzer;

void setup() {
  sensor = 2;
  buzzer = 3;
  pinMode(sensor, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  if (detectSound()) {
    bark();
  }
}

boolean detectSound() {
  if (digitalRead(sensor) == HIGH) {
    return true;
  }
  else {
    return false;
  }
}

void bark() {
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
