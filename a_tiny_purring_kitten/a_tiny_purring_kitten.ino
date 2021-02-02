#include <Adafruit_NeoPixel.h>
#include <CapacitiveSensor.h>

/*
 * "Purring Cat"
 * This "animal" responds to someone touching the captive touch sensor by purring, 
 * showing their affection for the user, as long as they are being slow and not 
 * being too fast/rough. 
 */

CapacitiveSensor sensor = CapacitiveSensor(3,4);
Adafruit_NeoPixel strip(3, 2, NEO_GRB + NEO_KHZ800);

void setup() {
  /*
   * Basic I/O device setup, and initilize 
   * the timing systems. 
   */
  strip.begin();
  strip.show();
  sensor.set_CS_AutocaL_Millis(0xFFFFFFFF);
}

void loop() {
  /*
   * Determines if the "cat's" sensor is being
   * touched. If so, we determine if the petting/holding
   * is too rough/long. We use this to determine output
   * happiness. 
   */
  detectTouch();
}

void detectTouch() {
  /*
   * Determine if the touch sensor is being
   * interacted with. If so, we begin the happiness 
   * determination process using the current time and 
   * the time that they started touching the sensor. If 
   * the user is not touching the sensor, ensure the lights
   * are all off. 
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
  /*
   * Turn all Neopixel lights off. 
   */
  for (int i = 0; i < 4; i++) {
    strip.setPixelColor(i, 0, 0, 0);
  }
  strip.show();
}

void turnOn(int loc, int r, int g, int b) {
  /*
   * Turn on X amount of lights to the given
   * RGB value. 
   */
  for (int i = 0; i < loc; i++) {
    strip.setPixelColor(i, r, g, b);
  }
}

void determineHappiness(int timePassed) {
  /*
   * Set the "happiness" level on the Neopixel strip. 
   * Every second until 4 seconds have passed, we go up
   * one green light to show more happiness. 4000 is the "best"
   * time. After this, we start going to red every second for three
   * seconds, until 7 seconds is reached. At that point, lights start
   * blinking to show extreme unhappiness. 
   */
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
