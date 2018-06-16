#include <Arduino.h>
#include <Wifi.h>
#include <PubSubClient.h>
#include "WifiConnect.h"
#include "CloudMqttConnect.h"
#include "Helper.h"

//TP-LINK_9418    67516926
//DIGI-BDAD    tJquRxvs
const char* ssid = "HUAWEI_P9lite_047E";
const char* password = "1200ba48";
const char* mqttServer = "m14.cloudmqtt.com";
const int mqttPort = 13567;
const char* mqttUser = "pspdvyar"; //ESP32
const char* mqttPassword = "JA21PLhGdpnu"; //asdfqwer

 WiFiClient espClient;
 static PubSubClient client(espClient);

CloudMqttConnection cloudMqttConnection = CloudMqttConnection(client, mqttServer, mqttPort, mqttUser, mqttPassword);


void intToChar(int a, char buf[10]){
  itoa(a, buf, 10);
  Serial.println("itoa..");
  Serial.println(buf);
}

void kitchenLight(packet_t p){
  
  Serial.println("publish message..1");
   // const char* message = strcat((char*)p.clientId, (char*)p.data);
    //cloudMqttConnection.publish(topics[p.topicId], message);
    //Serial.println("publish message..");
    //Serial.println(message);
}

void bedroomLight(){
  int msg = ReadMessage();
  Serial.println("Received from 2:"); 
  char buf[12];
  itoa(msg, buf, 10);
  cloudMqttConnection.publish("SH/light/bedroom", buf);
  //Serial.println("Published bedroom light");
  Serial.println(buf);
}

long baudRate = 115200;
void setup() {
  Serial.begin(baudRate);
  instantiate(baudRate);
  flush();
  WifiConnection wifiConnection = WifiConnection(ssid, password);
  wifiConnection.connectToWifi();
  client = cloudMqttConnection.connectToMqttServer();
}

void loop() {
  if(client.loop()){
    if(serialAvailable())
    {
      Serial.println("Reading..");
      packet_t p;
      ReadSerialMsg((byte *)&p, sizeof(packet_t));
      int sensor = p.topicId;
      Serial.println(p.clientId);
      Serial.println(p.data);
      Serial.println(sensor);
      char dataBuf[12];
      char clientIdBuf[10];
      char message[20];
      itoa(p.data, dataBuf, 10);
      itoa(p.clientId, clientIdBuf, 10);
      strcpy(message, clientIdBuf);
      //message[strlen(message)] = ' ';
      //message[strlen(message)+1] = '\0';
      strcat(message, dataBuf);
      Serial.println("Buffers..");
      Serial.println(clientIdBuf);
      Serial.println(dataBuf);
      Serial.println(message);
      Serial.println(topics[p.topicId]);
      switch(sensor){
        case 0: {
          Serial.println("Publish..");
          cloudMqttConnection.publish(topics[p.topicId], message);  
          //cloudMqttConnection.publish("dada", "da");
        }  break;
        //case 2: bedroomLight();   break;
        default: Serial.println("Received");
      }
    }
  }else cloudMqttConnection.connectToMqttServer();
}