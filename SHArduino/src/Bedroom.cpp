#include "Bedroom.h"
#include "Arduino.h"


static int k = 0;

void Bedroom::dimmingLed(){
    potentValue = analogRead(bedroomLightPotPin);
    
    if(abs(potentValue - oldAnalogValue) > 25)
    {
        potValueChanged = true;
        oldAnalogValue = potentValue;
        dutyCycle = potentValue*255/1023;
        k = 0;  
    }
    k++;

    if(k == 20){
        bedroomLightSetup(dutyCycle);
    }
    
}

void Bedroom::bedroomLightSetup(int dutyCycle){
    if(potValueChanged){
        analogWrite(bedroomLightdPin, dutyCycle);
        WriteSerialByte(2);

        byte publishValue = dutyCycle*100/255;
        WriteSerialByte(publishValue);

        Serial.println("PotLed publish value:");
        Serial.println(publishValue);
        potValueChanged = false;
    }
}

