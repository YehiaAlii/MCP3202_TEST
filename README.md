# MCP3202_TEST Library

This Arduino library provides an easy interface for the **MCP3202** 12-bit Analog-to-Digital Converter (ADC) via SPI. It allows for precise analog voltage readings from connected sensors or potentiometers, supporting both single-ended and differential input modes.

## Features

- Supports **single-ended** mode (independent readings from CH0 and CH1).
- Supports **differential mode** (CH0 - CH1), with automatic configuration based on channel values.
- Compatible with Arduino Nano and other boards with SPI support.

## Circuit Setup

To use this library, set up the MCP3202 with your Arduino as shown below:

- **CS (Chip Select)**: Connect to a digital pin on the Arduino (e.g., D10).
- **DIN (Data In)**, **DOUT (Data Out)**, and **CLK (Clock)**: Connect to the corresponding SPI pins on the Arduino.
- **VDD and VSS**: Connect to 5V and GND, respectively.
- **CH0 and CH1**: Connect to analog inputs, such as potentiometers or sensors.

Refer to the circuit diagram included in this repository: `Arduino_Nano_MCP3202_Interface.png`.

## Installation

1. **Download** or **clone** this repository.
2. Copy the `MCP3202_TEST` folder into your Arduino `libraries` folder.
   - On Windows, this is usually `Documents/Arduino/libraries`.
   - On macOS, it’s usually `~/Documents/Arduino/libraries`.
3. Restart the Arduino IDE.

Alternatively, you can install the library as a ZIP:
- Go to **Sketch > Include Library > Add .ZIP Library...** in the Arduino IDE and select the downloaded ZIP file.

# Usage

After installing the `MCP3202_TEST` library, you can begin using it in your Arduino projects. This library allows you to easily read analog values from the MCP3202 ADC in both single-ended and differential modes.

### Single-Ended Mode

In single-ended mode, the MCP3202 reads the voltage on each input channel (CH0 and CH1) relative to ground. This means you can connect two independent analog sensors or potentiometers to CH0 and CH1, and the library will read each channel separately.

- **CH0** and **CH1** readings are treated independently.
- Each channel can measure a voltage range from 0V to the reference voltage (Vdd), typically 5V.
- This mode is suitable when you want to read the exact voltage from individual sensors.

### Differential Mode

In differential mode, the MCP3202 reads the difference between the two input channels (CH0 and CH1).

- **CH0 - CH1**: Measures the voltage difference, where CH0 is treated as the positive input and CH1 as the negative.
- This mode is useful for applications requiring precise measurement of the difference between two signals, such as differential sensors.

## Example Sketch

To get started with the `MCP3202_TEST` library, open the example sketch included in the `examples` folder:

1. Open the Arduino IDE and go to **File > Examples > MCP3202_TEST > MCP3202_TEST_example**.
2. This example demonstrates how to:
   - Initialize the MCP3202 ADC.
   - Read from channels in both single-ended and differential modes.
   - Print the raw and converted voltage values to the Serial Monitor.

The example also includes comments explaining each step, making it easy to modify for your own projects.
