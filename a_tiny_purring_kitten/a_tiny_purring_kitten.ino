/*
 * "Purring Cat"
 * This "animal" responds to someone touching the captive touch sensor by purring, 
 * showing their affection for the user, as long as they are being slow and not 
 * being too fast/rough. 
 */

int motor, sensor, lastTime;
int purrTime;

void setup() {
  motor = 3;
  sensor = 2;
  lastTime = 0;
  pinMode(motor, OUTPUT);
  pinMode(sensor, INPUT);
}

void loop() {
  if (detectTouch()) {
    if (isRough()) {
      purr(false);
    }
    else {
      purr(true);
    }
  }
}

boolean detectTouch() {
  if(digitalRead(sensor) == HIGH) {
    delay(500);
    return true;
  }
  else {
    return false;
  }
}

boolean isRough() {
  int curTime = millis();
  if (lastTime - curTime >= 2000) {
    return true;
  }
  else {
    return false;
  }
  lastTime = curTime;
}

void purr(boolean stat) {
  digitalWrite(motor, stat);
}
