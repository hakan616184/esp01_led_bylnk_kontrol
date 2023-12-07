#define BLYNK_TEMPLATE_ID "TMPL6IrEGzOl8"
#define BLYNK_TEMPLATE_NAME "ROLELER"
#define BLYNK_AUTH_TOKEN "LVtI3yRhCPbBCvvoBuqfArRR1f0VGj4r"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "LVtI3yRhCPbBCvvoBuqfArRR1f0VGj4r";

// Your WiFi credentials. PIN NUMARALARINA GORE DUZENLE ORNEK V1 yada V2 gibi
// Set password to "" for open networks.
char ssid[] = "zeynohome";
char pass[] = "zeynohome!";

void setup()
{
  // Debug console
  Serial.begin(115200);



  Blynk.begin(auth, ssid, pass);
}

BLYNK_WRITE(V2)
{
  int pinValue = param.asInt();
  if(pinValue == 1)
  {
    Serial.write(0xA0);
    Serial.write(0x01);
    Serial.write(0x01);
    Serial.write(0xA2);
  }
  else
  {
    Serial.write(0xA0);
    Serial.write(0x01);
    Serial.write(0x00);
    Serial.write(0xA1);    
  }
}

void loop()
{
  Blynk.run();
}

