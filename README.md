# clock_pps_calibrator

This project is intended for calibrating a clock source to a pps signal from a GPS module.

The operating principle:
* Use the clock signal as clock source for the MCU
* Run a 16bit timer directly from CPU clock
* Set timer overflow to 62500 so it loops 16 times every 1MHz and count these
* Use PPS interrupt to read the timer position, calculate frequency and print it out on serial

This way we will get a steady number if the clock is a exact multiple of 1MHz

To make this work you will need to build the project with the correct F_CPU so the serial timer gives a corrrect baudrate. It should be programmed on the default 8MHz or 16MHz clock as the bootloader will not work with the incorrect baud from a odd clock frequency.

Outputs freuency in herz and raw timer for long time stability testing

The project is in beta.