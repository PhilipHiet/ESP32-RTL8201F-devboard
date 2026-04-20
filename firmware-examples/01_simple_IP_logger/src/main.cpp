#include <Arduino.h>
#include <ETH.h>
#include <WiFi.h>

void setup() {
    Serial.begin(CONFIG_MONITOR_BAUD);
    WiFi.mode(WIFI_OFF);

    ETH.begin();
    ETH.enableIpV6();
}
void loop() {
    if (ETH.linkUp()) {
        Serial.println("ETH link up");
        Serial.print("Speed:");
        Serial.println(ETH.linkSpeed());
        Serial.print("IP:");
        Serial.print(ETH.localIP());
        Serial.print("    ");
        Serial.println(ETH.localIPv6());
    } else {
        Serial.println("ETH link down");
    }
    delay(1000);
}