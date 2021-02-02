#include <Adafruit_NeoPixel.h>
#include <CapacitiveSensor.h>

/*
 * "Purring Cat"
 * This "animal" responds to someone touching the captive touch sensor by purring, 
 * showing their affection for the user, as long as they are being slow and not 
 * being too fast/rough. 
 */

CapacitiveSensor sensor = CapacitiveSensor(3,4);
int curPin;
Adafruit_NeoPixel strip(3, 2, NEO_GRB + NEO_KHZ800);

void setup() {
  /*
   * Basic I/O device setup, and initilize 
   * the timing systems. 
   */
  curPin = 0;
  strip.begin();
  strip.show();
  ///pinMode(2, OUTPUT);
  sensor.set_CS_AutocaL_Millis(0xFFFFFFFF);
  ///pinMode(motor, OUTPUT);
  ///pinMode(sensor, INPUT);
}

void loop() {
  /*
   * Determines if the "cat's" sensor is being
   * touched. If so, we determine if the petting
   * is too rough. If so, we stop purring, but if 
   * not, we can begin/keep purring. 
   */
  detectTouch();
}

void detectTouch() {
  /*
   * Determine if the touch sensor is being
   * interacted with. If so, return true, 
   * if not, return false. 
   */
  long total = sensor.capacitiveSensor(30);
  if(total > 100) {
    long start = millis();
    long endTime;
    while (sensor.capacitiveSensor(30) > 100) {
      endTime = millis();
      determineHappiness(endTime - start);
    }
  }
  else {
    allOff();
  }
}

void allOff() {
  for (int i = 0; i < 4; i++) {
    strip.setPixelColor(i, 0, 0, 0);
  }
  strip.show();
}

void turnOn(int loc, int r, int g, int b) {
  for (int i = 0; i < loc; i++) {
    strip.setPixelColor(i, r, g, b);
  }
}

void determineHappiness(int timePassed) {
  if (timePassed >= 1000 && timePassed < 2000) {
     turnOn(1, 0, 255, 0);
  }
  else if (timePassed >= 2000 && timePassed < 3000) {
    turnOn(2, 0, 255, 0);
  }
  else if (timePassed >= 3000 && timePassed < 4000) {
    turnOn(3, 0, 255, 0);
  }
  else if (timePassed >= 4000 && timePassed < 5000) {
    allOff();
    turnOn(1, 255, 0, 0);
  }
  else if (timePassed > 1000 && timePassed < 6000) {
    turnOn(2, 255, 0, 0);
  }
  else if (timePassed > 1000 && timePassed < 7000) {
    turnOn(3, 255, 0, 0);
  }
  else if (timePassed >= 7000) {
    allOff();
    delay(100);
    turnOn(3, 255, 0, 0);
    strip.show();
    delay(100);
  }
  strip.show();
}
