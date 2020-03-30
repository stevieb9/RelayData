#include <Arduino.h>
#include <FS.h>
#include <ArduinoJson.h>
#include <stdint.h>

#define JSON_SIZE 1024

const char dataFile[] = "/config.json";

DynamicJsonDocument fetchData ();
void setRelay (uint8_t relayType);
void writeData (DynamicJsonDocument doc);
