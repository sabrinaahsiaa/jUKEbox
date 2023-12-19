#include "tm4c123gh6pm.h"
#include "PWM.h"

// Initialize Port A 6-7 to be used for PWM signal for arm
void PWM_PA76_Init(void){
	// Initialize PWM Settings
	// enables PWM Module 1
	SYSCTL_RCGCPWM_R |= 0x02;
	// activate port A clock
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOA;
	// waits for the clock to be active 
	while ((SYSCTL_RCGC2_R&SYSCTL_RCGC2_GPIOA)==0){}; 
	// enable alt functions for PA 6-7
	GPIO_PORTA_AFSEL_R |= 0xC0;
	// Clear the PCTL for PA 6-7
	GPIO_PORTA_PCTL_R &= ~0xFF000000;
	// sets PCTL for PA 6-7 to use PWM
	GPIO_PORTA_PCTL_R |= 0x55000000;
	// enable digital output for PA 6-7
	GPIO_PORTA_DEN_R |= 0xC0; 
		
	// Clear any previous PWM divider  
	SYSCTL_RCC_R = (SYSCTL_RCC_R & (~0x001E0000)) | 0x00160000; 
	// Enables PWM 1 Gen 1 in count down mode
	
	PWM1_1_CTL_R |= 0x00000001;
	// Set up PWM module 1 G2-3 for use
	PWM1_1_GENA_R |= 0xC8;
	PWM1_1_GENB_R |= 0xC08;
		
	PWM1_1_LOAD_R = TOTAL_PERIOD - 1;
	PWM1_1_CMPA_R = 0;
	PWM1_1_CMPB_R = 0;

	// Enable PA6 M1PWM2, PA7 M1PWM3
	PWM1_ENABLE_R |= 0x0000000C;
}

// Changes the duty cycle for PA 6 
void PWM_PA6_Duty(unsigned long duty_arm){
	// PA6 count value when output rises
	PWM1_1_CMPA_R = duty_arm - 1;	
}

// Changes the duty cycle for PA 7
void PWM_PA7_Duty(unsigned long duty_pivot){
	// PA7 count value when output rises
	PWM1_1_CMPB_R = duty_pivot - 1;
}

void PWM_PB47_Init(void){
	// Initialize PWM Settings
	// enables PWM Module 0
	SYSCTL_RCGCPWM_R |= 0x01;
	// activate port B clock
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOB;
	// waits for the clock to be active 
	while ((SYSCTL_RCGC2_R&SYSCTL_RCGC2_GPIOB)==0){}; 
	// enable alt functions for PB 4-7
	GPIO_PORTB_AFSEL_R |= 0xF0;
	// Clear the PCTL for PB 4-7
	GPIO_PORTB_PCTL_R &= ~0xFFFF0000;
	// sets PCTL for PB 4-7 to use PWM
	GPIO_PORTB_PCTL_R |= 0x44440000;
	// disable analog function on PB 4-7
	GPIO_PORTB_AMSEL_R &= ~0xF0;
	// enable digital output for PB 4-7
	GPIO_PORTB_DEN_R |= 0xF0;
	// enable 8mA drive on PB 4-7
	GPIO_PORTB_DR8R_R |= 0xF0;
		
	// Clear any previous PWM divider values
	// Divided by 16
	// PWM Clock is 3.125MHz
	SYSCTL_RCC_R |= (SYSCTL_RCC_R & (~0x001E0000)) | 0x00160000; 		
		
	// Set up PWM module 0 G1-2 for use in count down mode
	// M0 G1A (PB4)
	PWM0_1_GENA_R |= 0xC8;
	// M0 G1B (PB5)
	PWM0_1_GENB_R |= 0xC08;
	// M0 G0A (PB6)
	PWM0_0_GENA_R |= 0xC8;
	// M0 G0B (PB7)
	PWM0_0_GENB_R |= 0xC08;
	
	// Sets the initial count down value for the PWM signal 
	PWM0_0_LOAD_R = TOTAL_PERIOD - 1;
	PWM0_1_LOAD_R = TOTAL_PERIOD - 1;
	
	// Sets the PWM Signal to be triggered at 0 initially
	
	PWM0_0_CMPA_R = 0;
	PWM0_0_CMPB_R = 0;
	PWM0_1_CMPA_R = 0;
	PWM0_1_CMPB_R = 0;
	
	// Sets PWM M0 Gen 0 in count down mode
	PWM0_0_CTL_R &= ~0x00000002;
	// Enables PWM M0 Gen 0 
	PWM0_0_CTL_R |= 0x00000001;
	// Sets PWM M0 Gen 0 in count down mode
	PWM0_1_CTL_R &= ~0x00000002;
	// Enables PWM M0 Gen 1 
	PWM0_1_CTL_R |= 0x00000001;
	
	// Enable PB 4-7
	PWM0_ENABLE_R |= 0x0000000F;
}

// Changes the duty cycle for PB 4
void PWM_PB4_Duty(unsigned long duty){
	PWM0_1_CMPA_R = duty - 1;	
}
// Changes the duty cycle for PB 5
void PWM_PB5_Duty(unsigned long duty){
	PWM0_1_CMPB_R = duty - 1;	
}
// Changes the duty cycle for PB 6
void PWM_PB6_Duty(unsigned long duty){
	PWM0_0_CMPA_R = duty - 1;	
}
// Changes the duty cycle for PB 7
void PWM_PB7_Duty(unsigned long duty){
	PWM0_0_CMPB_R = duty - 1;	
}


// Initiaize Port C Pin 4-5 to be used for PWM signal for chord servos
void PWM_PC45_Init(void){
	// activate port C clock
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOC;
	// waits for the clock to be active 
	while ((SYSCTL_RCGC2_R&SYSCTL_RCGC2_GPIOC)==0){}; 
	// enable alt functions for PC 4-5
	GPIO_PORTC_AFSEL_R |= 0xF0;
	// Clear the PCTL for PC 4-5
	GPIO_PORTC_PCTL_R &= ~0x00FF0000;
	// sets PCTL for PC 4-5 to use PWM
	GPIO_PORTC_PCTL_R |= 0x00440000;
	// enable digital output for PC 4-5
	GPIO_PORTC_DEN_R |= 0x30;
	
	// Set up PWM module 0 G3 for use in count down mode
	// M0 G1A (PC4)
	PWM0_3_GENA_R |= 0xC8;
	// M0 G1B (PC5)
	PWM0_3_GENB_R |= 0xC08;
	
	// Sets the initial count down value for the PWM signal 
	PWM0_3_LOAD_R = TOTAL_PERIOD - 1;
	
	// Sets the PWM Signal to be triggered at 0 initially
	PWM0_3_CMPA_R = 0;
	PWM0_3_CMPB_R = 0;
	
	// Enables PWM M0 Gen 0 in count down mode
	PWM0_3_CTL_R |= 0x00000001;
	
	// Enable PC 4-5
	PWM0_ENABLE_R |= 0x000000C0;
}

// Change the Duty for PC 4
void PWM_PC4_Duty(unsigned long duty){
	PWM0_3_CMPA_R = duty - 1;	
}

// Change the Duty for PC 5
void PWM_PC5_Duty(unsigned long duty){
	PWM0_3_CMPB_R = duty - 1;	
}

// Initialize Port E Pin 4 to be used for PWM signal for chord servos 
void PWM_PE4_Init(void){
	// activate port E clock
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOE;
	// waits for the clock to be active 
	while ((SYSCTL_RCGC2_R&SYSCTL_RCGC2_GPIOE)==0){}; 
	// enable alt functions for PE 4
	GPIO_PORTE_AFSEL_R |= 0x10;
	// Clear the PCTL for PE 4
	GPIO_PORTE_PCTL_R &= ~0x000F0000;
	// sets PCTL for PE 4 to use PWM
	GPIO_PORTE_PCTL_R |= 0x00040000;
	// enable digital output for PE 4
	GPIO_PORTE_DEN_R |= 0x10;
	
	// Set up PWM module 0 G3 for use in count down mode
	// M0 G2_A (PE4)
	PWM0_2_GENA_R |= 0xC8;
	
	// Sets the initial count down value for the PWM signal 
	PWM0_2_LOAD_R = TOTAL_PERIOD - 1;
	
	// Sets the PWM Signal to be triggered at 0 initially
	PWM0_2_CMPA_R = 0;
		
	// Enables PWM M0 Gen 2
	PWM0_2_CTL_R |= 0x00000001;
	
	// Enable PE 4
	PWM0_ENABLE_R |= 0x00000010;
}
// Change the Duty for PE 4
void PWM_PE4_Duty(unsigned long duty){
	PWM0_2_CMPA_R = duty;
}

// Initialize SysTick timer 
void SysTick_Init(void) {
	// disable the SysTick tmer 
	NVIC_ST_CTRL_R = 0x00; 
	// used to generate a 0.01 sec delay;
	NVIC_ST_RELOAD_R = 500000 - 1;
	//clear the value 
	NVIC_ST_CURRENT_R = 0; 
	// enables Systick with system clock
	NVIC_ST_CTRL_R = NVIC_ST_CTRL_CLK_SRC + NVIC_ST_CTRL_ENABLE; 
}

// Waits for SysTick to go off 
void SysTick_Wait(void){
	// clears the current values
	NVIC_ST_CURRENT_R = 0;
	// waits for time
	while ((NVIC_ST_CTRL_R & 0x00010000) == 0){};		
}

void Timer(int num){
	for( int i = 0; i < num; i++){
		SysTick_Wait();
	}			
}
