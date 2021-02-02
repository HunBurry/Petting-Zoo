/*
 * "Earthworm"
 * Earthworms hate light, so this animal
 * simulates the behavior of an earthworm 
 * by reacting to levels of light. 
 */

int sensor, red, blue, green;

void setup() {
  /*
   * Setup basic I/O devices. 
   */
  sensor = A3;
  red = 0;
  blue = 2;
  green = 1;
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(sensor, INPUT);
}

void loop() {
  /*
   * Initiates the process of determining light
   * level and setting the appropiate response. 
   */
  tooBright();
}

boolean tooBright() {
  /*
   * Determines if the direction the earthworm is
   * pointing is too bright. We look for a dim area,
   * which is lower than a 20% light level (200 or below). 
   * If the area is dim, we are happy. If slightly bright, 
   * we are slightly unsatisified, and if very bright, very
   * unsatisfied. 
   */
  int val = detectLight();
  if (val <= 10) {
    heartbeat(1);
  }
  else if (val <= 300) {
    heartbeat(2);
  }
  else {
    heartbeat(3);
  }
}

void heartbeat(int stat) {
  /*
   * Sets the "heartbeat" of the light. 
   * 1 is happy, and a slow blinking green light.
   * 2 is slightly unahappy, and a slightly faster
   * blinking yellow light. 3 in very unhappy, and a
   * fast blinking red light. 
   */
  if (stat == 1) {
    color(0, 255, 0);
    delay(1000);
    color(0, 0, 0);
    delay(500);
  }
  else if (stat == 2) {
    color(255, 255, 0);
    delay(200);
    color(0,0,0);
    delay(200);
  }
  else {
    color(255, 0, 0);
    delay(50);
    color(0, 0, 0);
    delay(50);
  }
}

void color(int r, int g, int b) {
  /*
   * Sets the pins of the RGB light to the 
   * appropriate values. 
   */
  analogWrite(red, r);
  analogWrite(blue, b);
  analogWrite(green, g);
}

int detectLight() {
  /*
   * Returns the value being read by the light sensor,
   * which returns a number 0 - 1024. 
   */
  return analogRead(sensor);
}
