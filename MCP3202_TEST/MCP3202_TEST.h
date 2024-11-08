#ifndef MCP3202_TEST_H
#define MCP3202_TEST_H

#include <Arduino.h>
#include <SPI.h>

class MCP3202_TEST {
public:
    MCP3202_TEST(int csPin, int vdd);     // Constructor to set up CS pin and Vdd
    void begin();                    // Initializes the MCP3202
    unsigned int readSingleEnded(byte channel); // Reads a single-ended channel (0 or 1)
    int readDifferential();          // Reads differential mode with automatic configuration selection

private:
    int _csPin;
    int _vdd;
    unsigned int readChannel(byte dataOut); // Helper function for SPI communication
};

#endif