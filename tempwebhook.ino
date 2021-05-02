// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT_Particle.h>

// This example assumes the sensor to be plugged into CONN2
#define DHTPIN D6     // what pin we're connected to

// Here we define the type of sensor used
#define DHTTYPE DHT11        // DHT 11 

DHT dht(DHTPIN, DHTTYPE);

int led = D7;  // The on-board LED

void setup() {
    pinMode(led, OUTPUT);
    Serial.begin(9600); 
    dht.begin();
}

void loop() {
  digitalWrite(led, HIGH);   // Turn ON the LED
  String hum = String(dht.getHumidity());
  // Read temperature as Celsius
  String temp = String(dht.getTempCelcius());
  
  // Read temperature as Farenheit
  //float f = dht.getTempFarenheit();
  Serial.print(dht.getHumidity());
  Serial.println("hum");
  Serial.print(dht.getTempFarenheit());
  Serial.println("temp");
  
  delay(1000);

  Particle.publish("temp", temp, PRIVATE);
  Particle.publish("hum", hum, PRIVATE);
  delay(30000);               // Wait for 30 seconds

  digitalWrite(led, LOW);    // Turn OFF the LED
  delay(30000);               // Wait for 30 seconds
}
