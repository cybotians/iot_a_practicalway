/* created by Joydip Dutta, http://cybotians.com
 Organization: CYBOTIANS
    IR sensor Pins:
        VCC: +5VDC
        OUT: pin 12
        GND: GND
 */

int inputPin = 12; //D7 choose input pin (for Infrared sensor) 
int val = 0; // variable for reading the pin status

void setup() 
{ 
   Serial.begin(9600); 
   pinMode(LED_BUILTIN, OUTPUT); // declare LED as output 
   pinMode(inputPin, INPUT); // declare Infrared sensor as input
}

void loop()
{ 
   val = digitalRead(inputPin); // read input value 
   // check if the input is HIGH
   if (val == HIGH)
   { 
      digitalWrite(LED_BUILTIN, HIGH); // turn LED OFF   
      Serial.println("Reading");
   } 
   else 
   { 
      digitalWrite(LED_BUILTIN, LOW); // turn LED ON 
      Serial.println("No Reading");
   } 
}
