/* created by Joydip Dutta, http://cybotians.com
 Organization: CYBOTIANS
    IR sensor Pins:
        VCC: +3.3VDC
        OUT: pin D7 or GPIO 13
        GND: GND
 */

#include <ESP8266WiFi.h>
#include "FirebaseESP8266.h"



#define FIREBASE_HOST "yourdatabaselink"
#define FIREBASE_AUTH "##################" //Database Secret K ey

FirebaseData firebaseData;

int inputPin = 13; //D7 choose input pin (for Infrared sensor) 
int val = 0; // variable for reading the pin status

void setup() 
{ 
  Serial.begin(115200); 
  WiFi.begin("****", "****");//Enter WiFi (SSID, Password)
  Serial.print("Connecting to Wi-Fi");

   while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  
   pinMode(LED_BUILTIN, OUTPUT); // declare LED as output 
   pinMode(inputPin, INPUT); // declare Infrared sensor as input

   Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  //Set database read timeout to 1 minute (max 15 minutes)
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
}

void loop()
{ 
   val = digitalRead(inputPin); // read input value 
   if (val == HIGH)
   { 
        if (Firebase.setInt(firebaseData,"/value",1))
        {
          Serial.println("PASSED Reading");
        }
        delay(1000);
   } 
   else 
   { 
      if (Firebase.setInt(firebaseData,"/value",0))
        {
          Serial.println("PASSED no Reading");
        }
        delay(1000);
      
   } 
}
