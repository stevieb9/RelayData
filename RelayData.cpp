#include <RelayData.h>

void setRelay (uint8_t relayType) {
    DynamicJsonDocument doc = fetchData();
    serializeJsonPretty(doc["relays"][relayType], Serial);
}

DynamicJsonDocument fetchData () {

    if (SPIFFS.begin()) {
        if (SPIFFS.exists(dataFile)) {
            File configFile = SPIFFS.open(dataFile, "r");

            DynamicJsonDocument doc(JSON_SIZE);

            if (configFile) {

                auto error = deserializeJson(doc, configFile);

                if (error) {
                    Serial.println(error.c_str());
                    configFile.close();
                }

            }
            return doc;
        }
    }
}

void writeData (DynamicJsonDocument doc) {
    SPIFFS.remove(dataFile);

    File configFile = SPIFFS.open(dataFile, "w");

    if (configFile) {
        serializeJson(doc, configFile);
        configFile.close();
    }
}

