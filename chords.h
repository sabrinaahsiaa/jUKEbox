#include <stdio.h>
#include <stdlib.h>
#include "UART.h"
#include "PWM.h"

// PWM time with signals 
// 32000 = 2ms
// 24000 = 1.5ms
// 9600 = 0.6ms
		
// 40000 = 90 clockwise
// 24000 = 0 middle
// 9600 = 90 counter-clockwise

// Creates the base structrue that will store the chord name and its corresponding servo positions 
struct chord_positions {
    char chord_name[8];
    int servo_pos;
};
extern const struct chord_positions chords[100];

extern char chord_roots[12][3];

/* Passes in which root library to search though and the chord that is being searched for
   location - input that contains which root note libary to look though 0 = A, 11 = Ab/G#
   Chord_Name - the chord that needs to be played from that libary
*/ 
void chord_select(int location, char *Chord_Name);

/* Will iterate from chord A-G# 12 chords to find the family
    From there, it will search for the matching chord 
    Compares up to the first two char to see if it matches a chord family
    Returns which root note library it is in
*/
void find_root(char *chord);

// Sets the positions of servos based on their time info given to it. 
void set_servos(int pos, int servo);																		

// Does math to find the servo postions 																		
void find_servo(int posInfo);

// Takes servo position info and returns the PWM signal that corresponds to it
int servo_decoder(int pos, int servo_x);

// Creates a menu that will present the user with chord options
void Menu(void);
