# Ex03-Button

This project configures GPIO input to toggle LED1 at PC13

## Setup

PB0: connect mechanical button to connect to GND

## Details

PB0 GPIO configured as pull-up input.
Input glitches are filtered out by debounce counter controlled by systick timer.