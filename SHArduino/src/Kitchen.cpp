#include "Kitchen.h"
#include "Arduino.h"
#include "ArduinoHelper.h"

int Kitchen::debounce(int lightState)
{
  static int k = 0;
  int currentState = digitalRead(kitchenButtonLightPin);
  if(currentState != lightState)
  {
    k++;
  }
  else
  {
    k = 0;
  }

  if(k > 5){
    lightState = currentState;
    k = 0;
  }
  return lightState;
}

void Kitchen::setKitchenLightState()
{
    nextLightState = debounce(kitchenLightState);

    if(kitchenLightState == 0 && nextLightState == 1){
        buttonPressed = !buttonPressed;
    }
   
    kitchenLightState = nextLightState;

    if(buttonPressed == true)
    {
        digitalWrite(kitchenLightPin, HIGH);
        currLightState = 1;
    }else if(buttonPressed == false){ 
        digitalWrite(kitchenLightPin, LOW);
        currLightState = 0;
    }
    sendKitchenLightState();
}

void Kitchen::sendKitchenLightState(){
    if(currLightState != prevLightState){
        if(kitchenLightESP){
            kitchenLightESP = false;
        }else{
            packet_t newPacket;
            newPacket.clientId = ARDUINO_ID;
            newPacket.topicId = 0;
            newPacket.data = currLightState;
            WriteSerialMsg((byte*)&newPacket, sizeof(packet_t));
            Serial.println("Light state sent-");
            // Serial.println((int)newPacket.topicId);
            // Serial.println((int)newPacket.clientId);
            // Serial.println(newPacket.data);
        }
        prevLightState = currLightState;       
    } 
}