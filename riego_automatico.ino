int Bomba = 10;
int SensorPin = A0;
void setup() 
{  
  pinMode(Bomba, OUTPUT);
  pinMode(SensorPin, INPUT);
  Serial.begin(9600);
}
void loop() 
{
  //map(value, fromLow, fromHigh, toLow, toHigh)
  int humedad = analogRead(SensorPin);
  Serial.print("Humedad: ");
  Serial.print(humedad);
  //Serial.println(" %");
  Serial.println(" ");
  delay(1000);
 
  if(humedad >= 1000)
  { 
    Serial.println("La tierra está seca, comienza el riego:");
    digitalWrite(Bomba, 0);
    delay(2000);
  }
  if(humedad <= 1000)
  {
    Serial.println("La tierra está humeda");
    digitalWrite(Bomba, 1);
    delay(2000);
  }
}