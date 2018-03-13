const int piezoOne = 0;
const int ledPin = 13;
const int threshold = 600;

void setup() {
  // put your setup code here, to run once:

  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  int val = analogRead(piezoOne);
  Serial.println(val);

  if (val > threshold) {

    if (val > 601 && val <= 700) {
      Serial.println("S1 ALERT!");
      Serial.println(val);
    }

    else if (val > 701 && val <= 800) {
      Serial.println("S2 ALERT!");
      Serial.println(val);
    }

    else if (val > 801 && val <= 900) {
      Serial.println("FINAL ALERT!");
      Serial.println(val);
    }

    else if (val > 900) {
      Serial.println("ALARM");
      digitalWrite(ledPin, HIGH);
      Serial.println(val);
    } 
  }

  /*
  if (val < threshold) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, LOW);
  }
  */

}
