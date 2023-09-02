# Project description

This project is intended for calibrating a clock source to a pps signal from a GPS module.

The operating principle:
* Use the clock signal as clock source for the MCU
* Run a 16bit timer directly from MCU clock
* Set timer overflow to 62500 so it loops 16 times every 1MHz and count these
* Use PPS interrupt to read the timer position, calculate frequency and print it out on serial

This way we will get a steady timer value if the clock is a exact multiple of 1MHz.<br>

# Installation and use

1. Flash the original board with the appropriate .hex or .elf
2. Remove the MCU crystal
3. Connect the oscillator/generator/reference to PB6/XTAL1
4. Connect PPS to PB0 (Arduino pin 8)
5. Power everything up, preferably at the same time
6. Hook it up to the computer and fire up serial terminal at 9600
7. If the MCU does not start, press reset

The baudrate is depending on the MCU clock, which is specified with F_CPU (board_build.f_cpu).<br>
Either use this to get a proper 9k6 baud, OR using a usb-serial that is capable of arbitrary baudrate like 12k.<br>
If the board is a 8MHz and you want to run it on 10MHz, use 9600/8*10=12000baud.

Outputs freuency in herz and raw timer ticks for long time stability testing.<br>
When used on a source that is capable of better than 0.1ppm the Hz measurement stops being relevant.<br>
Adjust to exactly 10 MHz, then use the raw timer value to determine the long time average.<br>
Note down the raw timer value and what time this was, let it run for 100s and note the difference.<br>
The exact frequency can be determined by how many steps the timer has changed and over what time.<br>
For example timer went from 4500 to 4512 over 100s, the fraction is (4512-4500)/100=0.12Hz, so the exact frequency becomes 10000000.12Hz<br>
The clock source can then be adjusted and do a longer run to get even better accuracy, leave it for hours or even longer.

Testing this was performed on a Arduino pro mini 8MHz.<br>
The project is in beta.