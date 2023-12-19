#include <stdio.h>
#include <string.h>
#include "PLL.h"
#include "UART.h"
#include "UART1.h"
#include "chords.h"
#include "PWM.h"
#include "ServoTest.h"
#include "tm4c123gh6pm.h"
#include "Songs.h"
#include <stdlib.h>

// Caps the strings to be a max length of 50 characters 
#define MAX_STR_LEN 50
// Used to store the chord received from the Pi 
char message[MAX_STR_LEN]; 
extern void EnableInterrupts(void);
extern void WaitForInterrupt(void);
extern void DisableInterrupts(void);

int main(void){
	
	DisableInterrupts();
  PLL_Init();
	// initialize UART
  UART0_Init();
	UART1_Init();
	// initialize all the PWM for the motors 
	PWM_PA76_Init();
	PWM_PB47_Init();
	PWM_PC45_Init();
	PWM_PE4_Init();
	SysTick_Init();
	EnableInterrupts();
	Motor_Reset();
	
	char selection; 
	
	UART0_OutString("Enter something to output");
	OutCRLF0();  
	
  while(1) {
		UART1_InString(message, MAX_STR_LEN); 
		// For debugging
		UART0_OutString("The message I got was: ");
		UART0_OutString(message);
		OutCRLF0();
		// Converts message sent from Pi to int for switch case
		selection = atoi(message); 
		switch(selection){
			case 1:
				Play_Song(AT);
				break;
			case 2:
				Play_Song(Riptide);
				break;
			case 3:
				Play_Song(SOTR);
				break;
			case 4:
				Play_Song(CHFIL);
				break;
			case 5:
				Play_Song(LOFY);
				break;
			case 6:
				UART0_OutString("Freeplay Mode");
				OutCRLF0();
				Playback();
				break;
			default:
				break;
		}
		// For debugging
		UART0_OutString("Done playing");	
		OutCRLF0();
  }	
}
