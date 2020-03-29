#include <Arduino.h>
#include <FS.h>
#include <ArduinoJson.h>

DynamicJsonDocument fetchData ();
void writeData (DynamicJsonDocument doc);
