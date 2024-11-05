#include "MCP3202_TEST.h"

// Constructor to set CS pin and Vdd
MCP3202_TEST::MCP3202_TEST(int csPin, int vdd) : _csPin(csPin), _vdd(vdd) {}

// Initialize the MCP3202
void MCP3202_TEST::begin() {
    pinMode(_csPin, OUTPUT);
    digitalWrite(_csPin, HIGH);
    SPI.begin();
}

// Read a single-ended channel (0 or 1)
unsigned int MCP3202_TEST::readSingleEnded(byte channel) {
    byte dataOut = (channel == 0) ? 0b10100000 : 0b11100000;
    return readChannel(dataOut);
}

// Read differential mode 
int MCP3202_TEST::readDifferential() {
    // Read channels 0 and 1 to decide configuration
    int channel1 = readSingleEnded(0);
    int channel2 = readSingleEnded(1);

    bool useConfig1 = (channel1 >= channel2);  // Choose configuration based on channel comparison
    byte dataOut = useConfig1 ? 0b00000000 : 0b01000000;
    
    int result = readChannel(dataOut);

    // If using the second configuration (CH1+ - CH0-), return the result as a negative value
    if (!useConfig1) {
        result = -result;
    }

    return result;
}

// Private helper function to handle SPI communication
unsigned int MCP3202_TEST::readChannel(byte dataOut) {
    SPI.beginTransaction(SPISettings(500000, MSBFIRST, SPI_MODE0));  // 500 kHz clock, MSB first, SPI Mode 0
    digitalWrite(_csPin, LOW);

    SPI.transfer(0b00000001); // Start bit
    unsigned int result = (SPI.transfer(dataOut) & 0x0F) << 8;
    result |= SPI.transfer(0x00);

    digitalWrite(_csPin, HIGH);
    SPI.endTransaction();

    return result;
}
