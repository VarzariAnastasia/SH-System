#include <Arduino.h>
#include "Kitchen.h"
#include "ArduinoHelper.h"
#include "Bedroom.h"

long baudRate = 115200;
int kitchenButtonLightPin = 12;
int kitchenLightPin = 13;
int bedroomLightPotPin = A1;
int bedroomLightdPin = 9;
//int bedroomSHTDataPin = 7;
//int bedroomSHTClockPin = 6; 
//int ultrasonicEcho = 4;
//int ultrasonicTrig = 3;

Kitchen kitchen =  Kitchen(kitchenLightPin, kitchenButtonLightPin); 
Bedroom bedroom = Bedroom(bedroomLightPotPin, bedroomLightdPin);
void setup() {
    // put your setup code here, to run once:
    pinMode(kitchenButtonLightPin, INPUT);
    pinMode(kitchenLightPin, OUTPUT);

    pinMode(bedroomLightdPin, OUTPUT);
    pinMode(bedroomLightPotPin, INPUT);
    
    Serial.begin(baudRate);
    //while(!Serial){;}  // wait for serial port to connect

    instantiate(baudRate);
    flush();
    
}


void bedroomLight()
{
    int length = ReadMessage();
    for(int i=0; i<=length; i++){
        Serial.println("Received byte for bedroom light");
        Serial.println(ReadMessage());
    }
    //dutyCycle = (dutyCycle-'0') * 256 + ReadMessage() - '0'; //+ *256
   // Serial.println("dutyCycle received:");
   // Serial.println(dutyCycle);
   // analogWrite(bedroomLightdPin, dutyCycle);
}

void loop() {
    
    kitchen.setKitchenLightState(); 
    //bedroom.dimmingLed();
    Serial.println("after");
    if(serialAvailable() == true)
    {
        Serial.println("Reading......");
        packet_t p;
        ReadSerialMsg((byte *)&p, sizeof(packet_t));
        int sensor = p.topicId; //ReadMessage();
        Serial.println(p.clientId);
        Serial.println(p.data);
        Serial.println(sensor);
        switch(sensor){
            case 0: { if(p.data == 1){
                        kitchen.buttonPressed = true;
                        kitchen.kitchenLightESP = true;
                        Serial.println("light on");
                    }else if(p.data ==0){
                        kitchen.buttonPressed = false;
                        kitchen.kitchenLightESP = false;
                        Serial.println("light off");
                    }
            }   break;
            //case 2: bedroomLight();   break;
            //default: Serial.println("Received");
        }    
    }else{Serial.println("serial not available");}
    delay(20);
    //flush();
}