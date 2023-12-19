// System clock is 50MHz. PWM Divider is 16, making it 3.125MHz
#define TOTAL_PERIOD 31250 //  3.125MHz / 100Hz

// Servo angle definitions
#define Both 		2344  	// 90
#define String2	4200		// 45
#define Open 		6000		// -22.5
#define String1 7800		// -90

	
// Initialize Port A 6-7 to be used for PWM signal for chord servos
void PWM_PA76_Init(void);

// Changes the duty cycle for PA 6
void PWM_PA6_Duty(unsigned long duty_arm);

// Changes the duty cycle for PA 7
void PWM_PA7_Duty(unsigned long duty_pivot);

// Initialize Port B 4-7 to be used for PWM signal for chord servos
void PWM_PB47_Init(void);

// Change the Duty for PB 4
void PWM_PB4_Duty(unsigned long duty);
// Change the Duty for PB 5
void PWM_PB5_Duty(unsigned long duty);
// Change the Duty for PB 6
void PWM_PB6_Duty(unsigned long duty);
// Change the Duty for PB 7
void PWM_PB7_Duty(unsigned long duty);

// Initiaize Port C 4-5 to be used for PWM signal for chord servos
void PWM_PC45_Init(void);

// Change the Duty for PC 4
void PWM_PC4_Duty(unsigned long duty);
// Change the Duty for PC 5
void PWM_PC5_Duty(unsigned long duty);

// Initialize Port E 4 to be used for PWM signal for chord servos 
void PWM_PE4_Init(void);

// Change the Duty for PE 4
void PWM_PE4_Duty(unsigned long duty);
	
// Sets up SysTick Timer
void SysTick_Init(void);

// Single SysTick tick has occurred
void SysTick_Wait(void);
	
// Used to create a user delay
void Timer(int num);
