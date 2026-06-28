#ifndef DEBUG_H
#define DEBUG_H

#include <Arduino.h>

// If you want to enable debug output, uncomment the following line:
#define DEBUG

class Debug {
public:
    static void init(unsigned long timeoutMs = 1000);
    static void waitForSerial(unsigned long timeoutMs = 1000);
    static void printTimestamp();
    static void printString(const char* str);
    static void printNameValuePair(const char* name, int value);
    static void printNameValuePair(const char* name, const char* value);
};

#endif