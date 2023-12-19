#include "ServoTest.h"
#include "PWM.h"

// Iterates through combinations of duty cycle for all chord servos
void Motor_Test(void){
		// 32000 = 2ms
		// 24000 = 1.5ms
		// 9600 = 0.6ms
		
		// They all move in unison
		// Left bank
		PWM_PA6_Duty(String1);
		PWM_PA7_Duty(String1);
		PWM_PB4_Duty(String1);
		PWM_PB5_Duty(String1);
		
		// Right bank
		PWM_PB6_Duty(String1);
		PWM_PB7_Duty(String1);
		PWM_PC4_Duty(String1);
		PWM_PC5_Duty(String1);
		for(int i = 0; i< 10; i++)
		Strum(3);
		Timer(100);
		
		// Left bank
		PWM_PA6_Duty(Open);
		PWM_PA7_Duty(Open);
		PWM_PB4_Duty(Open);
		PWM_PB5_Duty(Open);
		
		// Right bank
		PWM_PB6_Duty(Open);
		PWM_PB7_Duty(Open);
		PWM_PC4_Duty(Open);
		PWM_PC5_Duty(Open);
		for(int i = 0; i< 10; i++)
			Strum(3);
			Timer(100);	
		
		// They move in opposite direction
		// Left bank
		PWM_PA6_Duty(String2);
		PWM_PA7_Duty(String2);
		PWM_PB4_Duty(String2);
		PWM_PB5_Duty(String2);
		
		// Right bank
		PWM_PB6_Duty(String2);
		PWM_PB7_Duty(String2);
		PWM_PC4_Duty(String2);
		PWM_PC5_Duty(String2);
		for(int i = 0; i< 10; i++)
			Strum(3);
			Timer(100);
		
		// Left bank
		PWM_PA6_Duty(Both);
		PWM_PA7_Duty(Both);
		PWM_PB4_Duty(Both);
		PWM_PB5_Duty(Both);
		
		// Right bank
		PWM_PB6_Duty(Both);
		PWM_PB7_Duty(Both);
		PWM_PC4_Duty(Both);
		PWM_PC5_Duty(Both);
		for(int i = 0; i< 10; i++)
			Strum(3);
			Timer(100);	
}

void Motor_Individual_Test(void){
	// PA6 Test
	PWM_PA6_Duty(String1);
	for(int i = 0; i< 10; i++)
			Timer(100);
	PWM_PA6_Duty(Open);
	for(int i = 0; i< 10; i++)
			Timer(100);
	PWM_PA6_Duty(String2);
	for(int i = 0; i< 10; i++)
			Timer(100);
	PWM_PA6_Duty(Both);
	for(int i = 0; i< 10; i++)
			Timer(100);
	PWM_PA6_Duty(Open);
	Timer(100);
	
	// PA7 Test
	PWM_PA7_Duty(String1);
	for(int i = 0; i< 10; i++)
			Timer(100);
	PWM_PA7_Duty(Open);
	for(int i = 0; i< 10; i++)
			Timer(100);
	PWM_PA7_Duty(String2);
	for(int i = 0; i< 10; i++)
			Timer(100);
	PWM_PA7_Duty(Both);
	for(int i = 0; i< 10; i++)
			Timer(100);
	PWM_PA7_Duty(Open);
	Timer(100);
	
	// PB6 Test
	PWM_PB6_Duty(String1);
	for(int i = 0; i< 10; i++)
			Timer(100);
	PWM_PB6_Duty(Open);
	for(int i = 0; i< 10; i++)
			Timer(100);
	PWM_PB6_Duty(String2);
	for(int i = 0; i< 10; i++)
			Timer(100);
	PWM_PB6_Duty(Both);
	for(int i = 0; i< 10; i++)
			Timer(100);
	PWM_PB6_Duty(Open);
	Timer(100);
	
	// PB7 Test
	PWM_PB7_Duty(String1);
	for(int i = 0; i< 10; i++)
			Timer(100);
	PWM_PB7_Duty(Open);
	for(int i = 0; i< 10; i++)
			Timer(100);
	PWM_PB7_Duty(String2);
	for(int i = 0; i< 10; i++)
			Timer(100);
	PWM_PB7_Duty(Both);
	for(int i = 0; i< 10; i++)
			Timer(100);
	PWM_PB7_Duty(Open);
	Timer(100);
}

// Sets all motors to open position
void Motor_Reset(void){
	
		// Left bank
		PWM_PA6_Duty(Open);
		PWM_PA7_Duty(Open);
		PWM_PB4_Duty(Open);
		PWM_PB5_Duty(Open);
		
		// Right bank
		PWM_PB6_Duty(Open);
		PWM_PB7_Duty(Open);
		PWM_PC4_Duty(Open);
		PWM_PC5_Duty(Open);
		
		// Strum
		PWM_PE4_Duty(5250);
	
		// 1s delay
		Timer(100);
		Timer(100);
}

void Motor_Off(void){
		// Left bank
		PWM_PA6_Duty(0);
		PWM_PA7_Duty(0);
		PWM_PB4_Duty(0);
		PWM_PB5_Duty(0);
		
		// Right bank
		PWM_PB6_Duty(0);
		PWM_PB7_Duty(0);
		PWM_PC4_Duty(0);
		PWM_PC5_Duty(0);
}

// Test PA6-7 and PB6-7
void Cam_Test(void){
	// Left bank
	PWM_PA6_Duty(4000);
	PWM_PA7_Duty(4000);
	
	// Right bank
	PWM_PB6_Duty(Open);
	PWM_PB7_Duty(Open);
	
	Timer(100); 
	Timer(100);
	Timer(100);
	
	// Play A 10 00 010101010101
	// Left bank
	PWM_PA6_Duty(String2);
	PWM_PA7_Duty(String1);
	
	// Right bank
	PWM_PB6_Duty(Open);
	PWM_PB7_Duty(Open);
	
	Timer(100);
	Timer(100);
	Timer(100);
	Timer(100);
	Timer(100);
	
	// Play D 01 11 010101 10 0101
	// Left bank
	PWM_PA6_Duty(Open);
	PWM_PA7_Duty(Both);
	
	// Right bank
	PWM_PB6_Duty(Open);
	PWM_PB7_Duty(String2);
	
	Timer(100);
	Timer(100);
	Timer(100);
	Timer(100);
	Timer(100);
	
	// Play F 01 00 0101 10 010101
	// Left bank
	PWM_PA6_Duty(Open);
	PWM_PA7_Duty(String1);
	
	// Right bank
	PWM_PB6_Duty(String2);
	PWM_PB7_Duty(Open);
	
	Timer(100);
	Timer(100);
	Timer(100);
	Timer(100);
	Timer(100);
}

int current_step = 5250;
// Creates steps for the strumming motor to go through for the range of motion
void Strum(char speed){
	// PWM for +90 Degree 7687
	//int max = 5700;
	// PWM for -90 Degree 2344
	//int min = 3000;
	
	int max = 5250;
	int min = 3450;
	
	if (current_step == min){
		current_step = max;
	}
	else if (current_step == max){
		current_step = min;
	}
	PWM_PE4_Duty(current_step);
	Timer(20 + speed*5);
	
}

// Sets all the motors to "both" position
void Motor_Both(void){
	  // Left bank
		PWM_PA6_Duty(Both);
		PWM_PA7_Duty(Both);
		PWM_PB4_Duty(Both);
		PWM_PB5_Duty(Both);
		
		// Right bank
		PWM_PB6_Duty(Both);
		PWM_PB7_Duty(Both);
		PWM_PC4_Duty(Both);
		PWM_PC5_Duty(Both);
		
		Timer(100);
}
// Can pass in which mode you want all motors to be set to
void Motor_Mode(int mode){
		// Left bank
		PWM_PA6_Duty(mode);
		PWM_PA7_Duty(mode);
		PWM_PB4_Duty(mode);
		PWM_PB5_Duty(mode);
		
		// Right bank
		PWM_PB6_Duty(mode);
		PWM_PB7_Duty(mode);
		PWM_PC4_Duty(mode);
		PWM_PC5_Duty(mode);
		
		Timer(100);
}
