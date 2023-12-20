# jUKEbox

This repository contains resources related to the jUKEbox. The jUKEbox is a self-playing ukulele project that consists of two modes: a mode that plays pre-programmed songs and a mode that takes in audio input to convert into playable chords on the ukulele.

[Jordan Maynard](https://github.com/j0rban), [Sabrina Hsia](https://github.com/sabrinaahsiaa) & [Jackie Huang](http://www.jackiehuanghasnogithubaccount.com) </br>

# Development Tools

* Keil uVision5 for tm4c123gh6pm microcontroller
* Glade/GTK for custom GUI on Raspberry Pi 3 Model B
* TinkerCad for custom 3D printed camshafts
* Essentia for chord extraction algorithm


# Contents

* `report.pdf` : final report for project

* `camshafts` : contains each iteration of the camshaft design

* `pi3` : contains code for Raspberry Pi 3b, used for UI
  * `chordProcessing.c` : algorithm for sorting chords returned by Essentia
  * `uart_v2` : initializes and sends UART messages
  * `ui.c` : initializes buttons and creates actions for user interface
  * `ui.glade` : specifies visual properties for user interface buttons

* `tm4c` : contains code for TM4C123GH6PM, used for servo motor controls
  * `PLL` : sets phase lock loop for system clock
  * `PWM` : initializes and controls pulse width modulation signals
  * `ServoTest` : test code to verify servo operation
  * `Songs` : song structures and play mechanism
  * `UART` : UART0 initialization and control
  * `UART1` : UART1 initialization and control
  * `UARTTestMain` : Main code
  * `chords` : contains servo positioning information and control for all possible chords


# Demo Video

https://www.youtube.com/watch?v=Rjar8DbBoU8
