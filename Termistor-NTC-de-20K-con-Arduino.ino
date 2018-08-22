/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  Google Plus https://goo.gl/gBnUdh
  WEB https://goo.gl/jtiYJy
*/

int thermistorPinT = A0;
int thermistorValueT;
float resistanceValueT = 20000.00;
float logarithmT, conversionT, temperatureT;
float coefficientAT = 1.299632551e-03, coefficientBT = 1.914753579e-04, coefficientCT = 1.627777429e-07;
String resultSerialT;

void setup() {
  Serial.begin(9600);
}

void loop() {
  thermistorValueT = analogRead(thermistorPinT);
  conversionT = resistanceValueT * (1023.0 / (float)thermistorValueT - 1.0);
  logarithmT = log(conversionT);
  temperatureT = (1.0 / (coefficientAT + coefficientBT * logarithmT + coefficientCT * logarithmT * logarithmT * logarithmT));
  temperatureT =  temperatureT - 273.15;
  resultSerialT = "Temperatura: " + String(temperatureT) + "°C";
  Serial.println(resultSerialT);
  delay(10);
}
