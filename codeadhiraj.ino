#define BLYNK_TEMPLATE_ID "TMPL387IICqSU"
#define BLYNK_TEMPLATE_NAME "dht sensor"
#define BLYNK_AUTH_TOKEN "bWS0EDZOnagNgveaM65YiovvFIEBZ0Ji"
#include <DHT.h>
#include <BlynkSimpleEsp8266.h>
#define DHTPIN 4
#define DHTTYPE DHT11

char auth[] = "bWS0EDZOnagNgveaM65YiovvFIEBZ0Ji";
char ssid[]  =  "Galaxy A33 5G C27D";
char pass[] = "xqip2610";
DHT dht(DHTPIN , DHTTYPE);
void setup() {
  Serial.begin(9600); 
  Blynk.begin(auth,ssid,pass);
  Serial.println("DHT test successful");
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
float h = dht.readHumidity();
float t = dht.readTemperature();
float f = dht.readTemperature(true);
if (isnan(h)|| isnan(t)|| isnan(f))
{
  Serial.println("something is not working as intended");
  return;
}
Serial.println("Humidity: ");
Serial.print(h);
Serial.println("temprature: ");
Serial.print(t);
Serial.print("degrees celcius");
Blynk.virtualWrite(V0,t);
Blynk.virtualWrite(V1,h);
delay (1000);
}