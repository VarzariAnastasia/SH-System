#ifndef HELPER_H
#define HELPER_H

#include "HardwareSerial.h"

#define TOPICS_NR 5
#define ESP_ID 1

typedef uint8_t byte;
extern const char* topics[];

typedef struct{
    byte clientId;
    byte topicId;
    uint16_t data;
}packet_t;

void callbackMethod(char* topic, byte* payload, unsigned int length);
bool serialAvailable();
void instantiate(long baudRate);
void WriteSerialByte(byte msg);
void WriteSerialMsg(byte *b, int length);
int ReadMessage();
void ReadSerialMsg(byte *b, int length);
void flush();


#endif

