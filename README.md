# jUKEbox

This repository contains resources related to a self-playing ukulele project.
[Jordan Maynard](https://github.com/j0rban), [Sabrina Hsia](https://github.com/sabrinaahsiaa) & [Jackie Huang](http://www.jackiehuanghasnogithubaccount.com) </br>


# Contents

* `pi3/` : contains code for Raspberry Pi 3b, used for UI
  * `chordProcessing.c` : algorithm for sorting chords returned by Essentia
  * `uart_v2` : initializes and sends UART messages
  * `ui.c` : initializes buttons and creates actions for user interface
  * `ui.glade` : specifies visual properties for user interface buttons

* `tm4c/` : contains code for TM4C123GH6PM, used for servo motor controls
  * `PLL` : sets phase lock loop for system clock
  * `PWM` : initializes and controls pulse width modulation signals
  * `ServoTest` : test code to verify servo operation
  * `Songs` : song structures and play mechanism
  * `UART` : UART0 initialization and control
  * `UART1` : UART1 initialization and control
  * `UARTTestMain` : Main code
  * `chords` : contains servo positioning information and control for all possible chords


# Demo Video
[Click here](https://www.youtube.com/watch?v=Rjar8DbBoU8)