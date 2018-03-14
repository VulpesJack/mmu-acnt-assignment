/*
 * UnoHC05RNGTest.ino
 * by Jack Noble
 *
 * Created: 14-02-2018
 * Updated: xx-xx-xxxx
 *
 * Function: Sends data over Bluetooth using the HC-05
 * module. This code sends a random number ever 0.1
 * seconds, this is to simulate the stream of data
 * that could be sent from a series of sensors.
 *
 */
 
// Import Software Serial library
#include <SoftwareSerial.h>

// Define software serial for Bluetooth comms
SoftwareSerial hc05Link(2, 3);

// Define LED pins
const unsigned int ledPin = 13;

// Define variable for Bluetooth data
int btData;

void setup() {
	// Code here will only run once, when the Uno boots
	
	// Enable software serial and print status message
	hc05Link.begin(9600);
	hc05Link.println("BT OK");
	
	// Set LED pin as an output
	pinMode(ledPin, OUTPUT);
}

void loop() {
	// Code here will run forever unless breaks are introduced
	
	// Checks for the bluetooth link
	if (hc05Link.available()) {
		
		// Sends a more constant stream of random numbers
		int rngVar = random(1024);
		hc05Link.print("DATA = ");
		hc05Link.println(rngVar);
		
	}
	
	// Delays for 0.1 seconds to prevent backlog and congestion
	delay(100);
}
