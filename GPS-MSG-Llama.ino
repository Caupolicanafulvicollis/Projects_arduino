//GPS+MSG+sensor llama
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

SoftwareSerial mySerial(10, 11); // RX, TX for GSM module
SoftwareSerial GPSSerial(2, 3); // RX, TX for GPS module

TinyGPSPlus gps;

const int flamePin = A0;

void setup() {
  mySerial.begin(9600);
  GPSSerial.begin(9600);
  Serial.begin(9600);
  delay(1000);
  mySerial.println("AT");
  delay(1000);
  mySerial.println("AT+CMGF=1");
  delay(1000);
  mySerial.println("AT+CMGS=\"YOUR_PHONE_NUMBER\"");
  delay(1000);
}

void loop() {
  while (GPSSerial.available() > 0) {
    gps.encode(GPSSerial.read());
  }
  int flameValue = analogRead(flamePin);
  if (flameValue > 500) {
    String message = "Fire detected, evacuate the building! ";
    if (gps.location.isValid()) {
      message += "Location: ";
      message += gps.location.lat(), 6;
      message += ", ";
      message += gps.location.lng(), 6;
    }
    mySerial.println(message);
    mySerial.println((char)26);
    delay(1000);
    Serial.println("SMS Sent!");
  }
}