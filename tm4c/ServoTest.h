// Change the Duty for all chord servos
void Motor_Test(void);

// Tests each motor 1 at a time
void Motor_Individual_Test(void);

// Turn all motors off
void Motor_Off(void);

// Change the Duty to full right for all chord servos
void Motor_Reset(void);

// See if the camshafts work
void Cam_Test(void);

// Creates steps for the strumming motor to go through for the range of motion
void Strum(char speed);

// Sets all the motors to "both" position
void Motor_Both(void);

// Can pass which mode you want all motors to be set to
void Motor_Mode(int mode);
