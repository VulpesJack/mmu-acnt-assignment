/*
 * UnoLDRTesting_WithCal.ino
 * by Jack Noble
 *
 * Created: 13-03-2018
 * Revised: 14-03-2018
 *
 * Function: Reads ambient light from LDR pressed against skin
 * if light increases past a calibrated threshold, an alarm
 * sounds. Part of a Live Project for Advanced Computer and
 * Network Technology at Manchester Metropolitan University.
 *
 */

// Define LDR pins for face mask
const unsigned int ldr0Pin = 0;
const unsigned int ldr1Pin = 1;
const unsigned int ldr2Pin = 2;

// Define LED pin for UX
const unsigned int ledPin = 13;

// Define base threshold value to fall back to should calibration
// fail. This value will change during development based on the
// characteristics of the LDRs we use.
int baseThreshold = 512;

// Define calibrated threshold
int calThreshold = 0;

// TODO: Add some serial bluetooth

void setup() {
	// Code here will only run once, when the Uno is powered up.
	
	// Set LED pin to output
	pinMode(ledPin, OUTPUT);
	
	// Set LDR pins to input
	pinMode(ldr0Pin, INPUT);
	pinMode(ldr1Pin, INPUT);
	pinMode(ldr2Pin, INPUT);
	
	// Start serial monitor
	Serial.begin(9600);
	
	// Print boot message to serial
	Serial.println("UNO OK");
	
	// Start calibration
	ldrCal();
	
}

void loop() {
	// Code here will run over and over, unless there is a 
	// break condition.
	
	// Print message to serial denoting that the loop has started
	Serial.println("UNO GO");
	
	// Take readings from LDR sensors
	int ldr0Val = analogRead(ldr0Pin);
	int ldr1Val = analogRead(ldr1Pin);
	int ldr2Val = analogRead(ldr2Pin);
	
	// Print readings to Serial
	Serial.print("LDR0 = ");
	Serial.println(ldr0Val);
	Serial.print("LDR1 = ");
	Serial.println(ldr1Val);
	Serial.print("LDR2 = ");
	Serial.println(ldr2Val);
	
	// Get average reading
	int ldrAvg = ((ldr0Val + ldr1Val + ldr2Val) / 3);
	
	// Print average reading
	Serial.print("LDR AVG = ");
	Serial.println(ldrAvg);
	
	/*
	// Test LDR against base threshold
	if (ldrAvg > baseThreshold) {
		digitalWrite(ledPin, HIGH);
		Serial.println("ALARM");
	} else {
		digitalWrite(ledPin, LOW);
	}
	*/
	
	//Test LDR against calibrated threshold
	if (ldrAvg > calThreshold) {
		digitalWrite(ledPin, HIGH);
		Serial.println("ALARM");
	} else {
		digitalWrite(ledPin, LOW);
	}
}

void ldrCal() {
	// This void runs once to calibrate the LDR sensors to
	// the skin of the person wearing the face mask.
	
	// Define a counter
	unsigned int counter = 0;
	
	// Print message to serial denoting that calibration is underway
	Serial.println("LDR CAL");
	
	// Take 50 readings from LDRs and average them
	while(counter < 50){
		
		int ldr0CalVal = analogRead(ldr0Pin);
		int ldr1CalVal = analogRead(ldr1Pin);
		int ldr2CalVal = analogRead(ldr2Pin);
		
		int ldrAvgCal = ((ldr0CalVal + ldr1CalVal + ldr2CalVal) / 3);
		
		// Add average to global variable
		calThreshold = (calThreshold + ldrAvgCal);
		
		// Increment counter
		counter++;
	}
	
	if (counter == 50) {
		Serial.println("CAL OK");
		Serial.print("CAL VAL = ");
		Serial.println(calThreshold);
		loop();
	}
}
