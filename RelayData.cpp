#define DEBUG true

void writeData (DynamicJsonDocument doc) {
    SPIFFS.remove("/config.json");
    
    File configFile = SPIFFS.open("/config.json", "w");

    if (configFile) {
        serializeJson(doc, configFile);
        configFile.close();
    }

    if (DEBUG) {
        serializeJsonPretty(doc, Serial);
    }
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
