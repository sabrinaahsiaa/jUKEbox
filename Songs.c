#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chords.h"
#include "PWM.h"
#include "ServoTest.h"
#include "Songs.h"
#include "UART1.h"
#include <stdlib.h>
#include "UART.h"

// Riptide - Vance Joy
struct Song Riptide[] = {{"Am", {4, 10, 1, 1, 1, -1}}, {"G", {4, 10, 1, 1, 1, -1}}, {"C", {4, 10, 1, 1, 1, 4, 8, 1}}, {"C", {1, 1, -2}}};
	
// Somewhere Over The Rainbow - Israel Kamakawiwo'ole
struct Song SOTR[] = {{"C",{2,10,12,2,10,14,-1}}, {"Em",{2,10,12,2,10,14,-1}}, {"F",{2,10,12,2,10,14,-1}}, {"C",{2,10,12,2,10,14,-1}}, {"F",{2,10,12,2,10,14,-1}}, 
											{"C",{2,10,12,2,10,14,-1}}, {"G",{2,10,12,2,10,14,-1}}, {"Am",{2,10,12,2,10,14,-1}}, {"F",{2,10,12,2,10,14,-2}}};
									
// Adventure Time - Cartoon Network												
struct Song AT[] = {{"G",{30,-1}}, {"D",{30,-1}}, {"C",{30,-1}}, {"D",{30,-1}}, {"G",{4,2,4,2,2,2,-1}}, {"D",{4,2,4,2,2,2,-1}}, {"C",{4,2,4,2,2,2,-1}}, {"D",{4,2,4,2,2,2,-2}}};
	
// Can't Help Falling In Love - Elvis Presley
struct Song CHFIL[] = {{"C", {8,5,1,4,3,-1}}, {"Em", {8,5,1,4,3,-1}}, {"Am", {8,5,1,4,3,-1}}, {"Am", {8,5,1,4,3,-1}}, {"F", {8,5,1,4,3,-1}}, {"C", {8,5,1,4,3,-1}},
												{"G", {8,5,1,4,3,-1}}, {"G", {8,5,1,4,3,-1}}, {"F", {8,5,1,4,3,-1}}, {"G", {8,5,1,4,3,-1}}, {"Am", {8,5,1,4,3,-1}}, {"F", {8,5,1,4,3,-1}}, {"C", {8,5,1,4,3,-1}},
												{"G7", {8,5,1,4,3,-1}}, {"C", {8,5,1,4,3,-1}}, {"C", {8,5,1,4,3,-1}}, {"C", {8,5,1,4,3,-1}}, {"Em", {8,5,1,4,3,-1}}, {"Am", {8,5,1,4,3,-1}},
												{"Am", {8,5,1,4,3,-1}}, {"F", {8,5,1,4,3,-1}}, {"C", {8,5,1,4,3,-1}}, {"G", {8,5,1,4,3,-1}}, {"G", {8,5,1,4,3,-1}}, {"F", {8,5,1,4,3,-1}},
												{"G", {8,5,1,4,3,-1}}, {"Am", {8,5,1,4,3,-1}}, {"F", {8,5,1,4,3,-1}}, {"C", {8,5,1,4,3,-1}}, {"G7", {8,5,1,4,3,-1}}, {"C", {8,5,1,4,3,-1}},
												{"C", {8,5,1,4,3,-2}}};

// Looking Out For You - Joy Again
struct Song LOFY[] = {{"A", {5,6,2,2,2,-1}}, {"Gbm", {6,2,2,6,2,2,4,-1}}, {"Dbm", {5,6,2,2,2,6,2,2}}, {"Cm",{6,2,2,4,-1}},
											 {"Bm", {5,6,2,2,2,6,2,2}}, {"Bm", {6,2,2,-1}}, {"Dbm", {4,5,6,2,2,2,-1}}, {"Dbm", {6,2,2,6,2,2,4,-2}}};

// Will play songs from song structures
void Play_Song(struct Song *song) {
	int i = 0;
	while (i < 256){
		find_root(song[i].chord_name);
		for (int y = 0; y < 8; y++) {
			// If there is less than 8 strums for a single chord, it will break out of the loop
			if (song[i].servo_time[y] == -1) {
				break;
			}
			else if (song[i].servo_time[y] == -2){
				goto end;
			}
			// substitute for setting the strum time
			Strum(song[i].servo_time[y]);
		}
		i++;
	}
	end: i++;
}

// Takes inputs from freeplay mode
void Playback(void){
  // Sets the max length of the string
	int length = 10;
	// Used to store the string
	char input[10];
	// Used to store timing
	char time = 0; 
	
	// Will keep playing the chords until the exit string is received
	while (strcmp(input, "0") != 0){
		// Gets the new chord to play
		UART1_InString(input, length);
		
		// For debugging to show the chord it got
		UART0_OutString(input);
		
		// Finds the root string and positions the servos to the proper position to play the chord
		find_root(input);
		// Will receive time info
		UART1_InString(input, length);
		
		// For debugging to find the timing it got
		UART0_OutString(" ");
		UART0_OutString(input); 
		
		OutCRLF0();
		// Converts the string into an int
		time = atoi(input);
		if (time != 0){
			// Strums the chord
			Strum(time);
		}

	}
}
