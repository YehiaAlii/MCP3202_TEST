#include <Arduino.h>
#include <MCP3202_TEST.h>

const int chipSel = 10;   // Chip select pin for MCP3202
const int Vdd = 5;        // Set according to your Vdd value
MCP3202_TEST adc(chipSel, Vdd); // Create an instance of MCP3202

void setup() {
    adc.begin();         // Initialize the MCP3202
    Serial.begin(9600);  // Start Serial communication
}

void loop() {
    // Single-ended mode for each channel
    int channel1 = adc.readSingleEnded(0);  // Read from Channel 0 in single-ended mode
    int channel2 = adc.readSingleEnded(1);  // Read from Channel 1 in single-ended mode

    // Convert single-ended ADC values to voltage
    float voltage1 = (channel1 * Vdd) / 4096.0;
    float voltage2 = (channel2 * Vdd) / 4096.0;

    // Print single-ended ADC values and corresponding voltages
    Serial.print("Single-ended Mode - Channel 0 Raw: ");
    Serial.print(channel1);
    Serial.print(" \tVoltage: ");
    Serial.print(voltage1);
    Serial.print(" V \t");

    Serial.print("Channel 1 Raw: ");
    Serial.print(channel2);
    Serial.print(" \tVoltage: ");
    Serial.print(voltage2);
    Serial.println(" V");

    // Differential mode (CH0 - CH1)
    int diffChannel = adc.readDifferential();  // Determine configuration and read differential mode
    
    // Convert differential ADC value to voltage difference
    float differentialVoltage = (diffChannel * Vdd) / 4096.0;

    // Print differential ADC value and corresponding voltage difference, always as (CH0 - CH1)
    Serial.print("Differential Mode - (CH0 - CH1) Raw: ");
    Serial.print(diffChannel);
    Serial.print(" \tVoltage Difference: ");
    Serial.print(differentialVoltage);
    Serial.println(" V");

    delay(1000);
}
