#include <Arduino.h>
#include <FS.h>
#include <ArduinoJson.h>

#define JSON_SIZE 1024

const char dataFile[] = "/config.json";

DynamicJsonDocument fetchData ();
void writeData (DynamicJsonDocument doc);
