#include <Adafruit_DHT.h>

#define DHTPIN 2

#define DHTTYPE DHT22

String outputData;

DHT dht(DHTPIN, DHTTYPE);

void setup() {

    dht.begin();

}

void loop() {

    delay(60000);//delay readings by 1 minute
    
    float humidity = dht.getHumidity();

    float temperature = dht.getTempCelcius(); //get the temperature in celcius

    outputData = String::format ("%.1f  %,%.1f C", humidity,temperature);

    Particle.publish("temperature", outputData);

}