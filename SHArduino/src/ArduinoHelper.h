
#ifndef ARDUINOHELPER_H
#define ARDUINOHELPER_H

#include <SoftwareSerial.h>
#include <SHT1x.h>

#define TOPICSNR 5
#define ARDUINO_ID 1
extern const char* topics[];

typedef uint8_t byte;

typedef struct{
    byte clientId;
    byte topicId;
    uint16_t data;
}packet_t;

bool serialAvailable();
void instantiate(long baudRate);
void WriteSerialByte(byte msg);
void WriteSerialMsg(byte *b, int length);
int ReadMessage();
void ReadSerialMsg(byte *b, int length);
void flush();

 int getLivingTemperature();
 int getLivingHumidity();
#endif