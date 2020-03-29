/*********
    Rui Santos
    Complete project details at https://RandomNerdTutorials.com
*********/

#include "FS.h"
#include <ArduinoJson.h>

void setup() {
    Serial.begin(9600);

    DynamicJsonDocument json = fetchData();
    writeData(json);
}

void writeData (DynamicJsonDocument doc) {
    SPIFFS.remove("/config.json");
    
    serializeJsonPretty(doc, Serial);

    doc["relays"][0]["temp"] = 78;
    
    File configFile = SPIFFS.open("/config.json", "w");

    if (configFile) {
        serializeJson(doc, configFile);
        configFile.close();
    }
    serializeJsonPretty(doc, Serial);

}

DynamicJsonDocument fetchData () {
    if (SPIFFS.begin()) {
        if (SPIFFS.exists("/config.json")) {
            File configFile = SPIFFS.open("/config.json", "r");

            DynamicJsonDocument doc(1024);

            if (configFile) {

                auto error = deserializeJson(doc, configFile);

                if (error) {
                    Serial.println(error.c_str());
                    configFile.close();
                }
                else {    
                    return doc;
                }
            }
        }
    }
}
void loop() {

}

