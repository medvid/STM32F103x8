# Ex01-Blinky

This project blinks a LED on STM32F103C8T6 development board

## Setup

PC13: LED1

## Details

PC13 GPIO is configured as output push-pull.
SysTick Timer is used to delay for 1000 milliseconds.
Each second LED toggles its state.