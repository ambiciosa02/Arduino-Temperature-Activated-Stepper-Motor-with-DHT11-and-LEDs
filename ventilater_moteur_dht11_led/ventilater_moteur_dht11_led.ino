#include <Stepper.h>
#include <DHT.h>

// Configuration du capteur DHT11
#define DHTPIN 2       
#define DHTTYPE DHT11  

DHT dht(DHTPIN, DHTTYPE);

// Moteur pas à pas
const int stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

// Définir les pins des 4 LED
const int led1 = 3;
const int led2 = 4;
const int led3 = 5;
const int led4 = 6;

void setup() {
  Serial.begin(9600);
  dht.begin();
  myStepper.setSpeed(8); // RPM moteur

  // Initialisation des LEDs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  // Allumer toutes les LEDs en permanence
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
}

void loop() {
  float temperature = dht.readTemperature();

  if (isnan(temperature)) {
    Serial.println("Erreur de lecture du capteur DHT11 !");
    delay(2000);
    return;
  }

  Serial.print("Température : ");
  Serial.print(temperature);
  Serial.println(" °C");

  if (temperature > 24) {
    myStepper.step(10); // Le moteur tourne
  }
  // Sinon, le moteur reste à l’arrêt

  delay(100);
}
