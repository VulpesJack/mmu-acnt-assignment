/*
 * UnoHC05Test.ino
 * by Jack Noble
 *
 * Created: 14-02-2018
 * Updated: xx-xx-xxxx
 *
 * Function: Sends data over Bluetooth using the HC-05
 * module. Using a terminal emulator, a LED can be
 * toggled on and off via Bluetooth.
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
		
		// Sets btData var to bluetooth communication data
		btData = hc05Link.read();
		
		// Checks if the PC/Android sends a '1' character
		if (btData == '1') {
			
			// Sets the LED to on and prints a message
			digitalWrite(ledPin, HIGH);
			hc05Link.println("LED = ON");
		}
		
		// Checks if the PC/Android sends a '0' character
		if (btData == '0') {
			
			// Sets the LED to off and prints a message
			digitalWrite(ledPin, LOW);
			hc05Link.println("LED = OFF");
		}
	}
	
	// Delays for 0.1 seconds to prevent backlog and congestion
	delay(100);
}
