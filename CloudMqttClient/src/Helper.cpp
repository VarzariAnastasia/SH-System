#include "Helper.h"

HardwareSerial Serial2(2);

const char* topics[TOPICS_NR] = {
  "SD/light/kitchen",
  "SD/light/bedroom",
  "SD/light/living",
  "SD/light/outside",
  "SD/temperature/bedroom"
};

void callbackMethod(char* topic, byte* payload, unsigned int length) {
 
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  packet_t p;
  if((String)topic == "SD/light/bedroom"){
    
  }else
    if((String)topic == "SD/light/kitchen"){
        Serial.println("Kitchen message..");
        p.topicId = 0;
        for (int i = 0; i < length; i++) {
            Serial.print((char)payload[i]); 
        }
        p.clientId = payload[0] - '0';
        if(p.clientId != ESP_ID){
            p.data = (int)(payload[1]-'0');
            WriteSerialMsg((byte*)&p, sizeof(packet_t));
        }
    }
        
       
    
  
  Serial.println();
  Serial.println("-----------------------");
}

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
    Serial2.write(b, length);
}

int ReadMessage(){
    return Serial2.read();
}

void ReadSerialMsg(byte *b, int length){
    for(int i = 0 ; i < length ; ++i )
       b[i] =  Serial2.read();
}

void flush(){
    Serial2.flush();
}

