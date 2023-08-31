# Project description

This project is intended for calibrating a clock source to a pps signal from a GPS module.

The operating principle:
* Use the clock signal as clock source for the MCU
* Run a 16bit timer directly from CPU clock
* Set timer overflow to 62500 so it loops 16 times every 1MHz and count these
* Use PPS interrupt to read the timer position, calculate frequency and print it out on serial

This way we will get a steady number if the clock is a exact multiple of 1MHz.<br>

# Installation and use

To make this work you will need to build the project with the correct F_CPU so the serial timer gives a corrrect baudrate.<br>
It should be programmed on the default 8MHz or 16MHz clock as the bootloader will not work with the incorrect baud from a odd clock frequency.<br>
Another option would be to adjust the serial baud to match the external clock, flashing for 8MHz and running at 10MHz would result in 9600/8*10=12000baud.

Testing this was performed on a Arduino pro mini 8MHz.<br>
Connected the external clock source up to XTAL1/PB6 after desoldering the on board crystal.

Outputs freuency in herz and raw timer for long time stability testing.

The project is in beta.