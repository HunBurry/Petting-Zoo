/*
 * "Purring Cat"
 * This "animal" responds to someone touching the captive touch sensor by purring, 
 * showing their affection for the user, as long as they are being slow and not 
 * being too fast/rough. 
 */

int motor, sensor, lastTime;
int purrTime;

void setup() {
  /*
   * Basic I/O device setup, and initilize 
   * the timing systems. 
   */
  motor = 3;
  sensor = 2;
  lastTime = 0;
  pinMode(motor, OUTPUT);
  pinMode(sensor, INPUT);
}

void loop() {
  /*
   * Determines if the "cat's" sensor is being
   * touched. If so, we determine if the petting
   * is too rough. If so, we stop purring, but if 
   * not, we can begin/keep purring. 
   */
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
  /*
   * Determine if the touch sensor is being
   * interacted with. If so, return true, 
   * if not, return false. 
   */
  if(digitalRead(sensor) == HIGH) {
    delay(500);
    return true;
  }
  else {
    return false;
  }
}

boolean isRough() {
  /*
   * Determine if the "petting" is too rough.
   * Rough means the user is touching the sensor
   * too fast (i.e. two touches within a two second
   * period. If too rough, return true, else, return
   * false. 
   */
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
  /*
   * Turns on/off the "purring" motor in response
   * to the roughness being passed in. 
   */
  digitalWrite(motor, stat);
}
