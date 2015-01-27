/*
  iBeacon Demo

  References
  * http://www.aplix.co.jp/?page_id=9351
 
  Components
  * A MyBeacon Fun module
  * An Arduno shield (e.g. https://www.switch-science.com/catalog/991/)
  * An Arduino Uno board
  * A 2.2k Ohm and a 3.3k Ohm resistors for a voltage divider

  Connections
  A MyBeacon Fun module | An Arduino Uno board
  -----------------------------------------------------------------
  VDD                   | 3.3V
  GND                   | GND
  MODE1 and WAKE        | 7 (via a voltage divider from 5V to 3.3V)

  Created 2014 by Shigeru Kobayashi

  This example code is in the public domain
*/

#include <SPI.h>
#include <SRM20SPIRemote.h>

#define COVER_BIT 0x00020000
#define SPINDLE_BIT 0x00010000

SRM20SPIRemote srm20;

// the pin that the MODE1 and the WAKE pins are connected to
const int beaconPin = 7;

void setup() {
  srm20.begin(9,6);

  pinMode(beaconPin, OUTPUT);
}

void loop() {
  unsigned long system,remote;

  if (srm20.isReady()) {
    srm20.getStatus(system, remote);

    if (system & COVER_BIT) {
      digitalWrite(beaconPin, HIGH);
    } 
    else {
      digitalWrite(beaconPin, LOW);
    }
  }

  delay(1000);
}
