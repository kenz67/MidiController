#include "Debug.h"

#ifdef DEBUG

void Debug::init(unsigned long timeoutMs) {
    waitForSerial(timeoutMs);
}

void Debug::waitForSerial(unsigned long timeoutMs) {
    unsigned long startTime = millis();
    while (!Serial && (millis() - startTime) < timeoutMs) {
        ;
    }
}

void Debug::printTimestamp() {
    unsigned long t = millis();
    unsigned int ms = t % 1000;
    unsigned long totalSeconds = t / 1000;
    unsigned int seconds = totalSeconds % 60;
    unsigned int minutes = (totalSeconds / 60) % 60;
    unsigned int hours = totalSeconds / 3600;

    Serial.print("[");
    if (hours < 10) Serial.print('0');
    Serial.print(hours);
    Serial.print(':');
    if (minutes < 10) Serial.print('0');
    Serial.print(minutes);
    Serial.print(':');
    if (seconds < 10) Serial.print('0');
    Serial.print(seconds);
    Serial.print('.');
    if (ms < 100) Serial.print('0');
    if (ms < 10) Serial.print('0');
    Serial.print(ms);
    Serial.print("] ");
}

void Debug::printString(const char* str) {
    printTimestamp();
    Serial.println(str);
}

void Debug::printNameValuePair(const char* name, int value) {
    printTimestamp();
    Serial.print(name);
    Serial.print(": ");
    Serial.println(value);
}

void Debug::printNameValuePair(const char* name, const char* value) {
    printTimestamp();
    Serial.print(name);
    Serial.print(": ");
    Serial.println(value);
}

#else

void Debug::init(unsigned long timeoutMs) {
    (void)timeoutMs;
}

void Debug::waitForSerial(unsigned long timeoutMs) {
    (void)timeoutMs;
}

void Debug::printTimestamp() {
}

void Debug::printString(const char* str) {
    (void)str;
}

void Debug::printNameValuePair(const char* name, int value) {
    (void)name;
    (void)value;
}

void Debug::printNameValuePair(const char* name, const char* value) {
    (void)name;
    (void)value;
}

#endif
