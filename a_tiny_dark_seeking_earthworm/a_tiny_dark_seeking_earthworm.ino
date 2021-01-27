/*
 * "Earthworm"
 * Earthworms hate light, so this animal
 * simulates the behavior of an earthworm 
 * by avoiding all areas of high light. 
 */

int sensor, motor;

void setup() {
  /*
   * Setup basic I/O devices. 
   */
  sensor = A0;
  motor = 2;
  pinMode(motor, OUTPUT);
  pinMode(sensor, INPUT);
}

void loop() {
  /*
   * If the area is deemed as too bright,
   * we begin moving the earthworm and looking
   * for an area that is dim. The earthworm
   * will continue to move until such an area
   * is located, but will halt when an area
   * is found. 
   */
  if(tooBright()) {
    moveWorm();
  }
  else {
    halt();
  }
}

void moveWorm() {
  /*
   * Turns on the motor so movement can begin. 
   */
  analogWrite(motor, 100);
}

void halt() {
  /*
   * Halts the motor, thus stopping movement. 
   */
  analogWrite(motor, 0);
}

boolean tooBright() {
  /*
   * Determines if the direction the earthworm is
   * pointing is too bright. We look for a dim area,
   * which is lower than a 20% light level (200 or below). 
   * If the area is dim, return false, if not, return true. 
   */
  int val = detectLight();
  if (val >= 200) {
    return true;
  }
  else {
    return false;
  }
}

int detectLight() {
  /*
   * Returns the value being read by the light sensor,
   * which returns a number 0 - 1024. 
   */
  return analogRead(sensor);
}
