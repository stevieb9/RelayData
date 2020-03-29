#include <RelayData.h>

void setup() {
    Serial.begin(9600);

    // Retrieve the stored data file

    DynamicJsonDocument doc = fetchData();

    /* Make some changes */
    // doc["relays"][0]["temp"] = 90;

    // Write the file back to flash

    writeData(doc);

    // Print the data to the serial monitor

    serializeJsonPretty(doc, Serial);
}

void loop() {

}

