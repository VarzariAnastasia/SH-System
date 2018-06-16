#include "ArduinoHelper.h"
 

SoftwareSerial Serial2(10, 11); //Rx, Tx
SHT1x sht1x(7, 6); //dataPin, clockPin

const char* topics[TOPICSNR] = {
  "SD/light/kitchen",
  "SD/light/bedroom",
  "SD/light/living",
  "SD/light/outside",
  "SD/temperature/bedroom"
};

bool serialAvailable(){
    return Serial2.available();
}

void instantiate(long baudRate){
    Serial2.begin(baudRate);
}

void WriteSerialByte(byte msg){
    Serial2.write(msg);
}

void WriteSerialMsg(byte *b, int length){
    //Serial2.write(b, length);
    for(int i = 0 ; i < length ; ++i )
        Serial2.write(b[i]);
}

void ReadSerialMsg(byte *b, int length){
    //Serial2.write(b, length);
    for(int i = 0 ; i < length ; ++i )
       b[i] =  Serial2.read();
}

int ReadMessage(){
    return Serial2.read();
}

void flush(){
    Serial2.flush();
}

int getLivingTemperature(){    
   return (int)sht1x.readTemperatureC();
}

int getLivingHumidity(){
     return (int)sht1x.readHumidity();
}