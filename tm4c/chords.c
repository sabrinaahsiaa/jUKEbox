#include "chords.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UART.h"
#include "PWM.h"

// Creates all the root chord positons 
const struct chord_positions chords[] = {{"A", 0x5552}, {"Bb", 0x5749}, {"B", 0x5D25}, {"C", 0x4555}, {"Db", 0x1657}, {"D", 0x595D}, 
                                    {"Eb", 0x6465}, {"E", 0x5194}, {"F", 0x5651}, {"Gb", 0x5846}, {"G", 0x6159}, {"Ab", 0x6119}, {"N", 0x5555}}; 

// All the chords for A
const struct chord_positions chords_A[] = {{"A", 0x5552}, {"Am", 0x5551}, {"Aaug", 0x1652}, {"Adim", 0x9158}, 
                                            {"A7", 0x5556}, {"Am7", 0x5555}, {"Amaj7", 0x5557}, {"Aaug7", 0x5656}, {"Admin7", 0x4961}, {"Am7b5", 0x7561} ,{"AmMaj7", 0x5554},
                                            {"Asus2", 0x9462}, {"Asus4", 0x555D}, {"A7sus2", 0x65D5}, {"A7sus4", 0x5559}, 
                                            {"A9", 0x6152}, {"Am9", 0x6154}, {"Amaj9", 0x9516}, {"A11", 0x255D}, {"Am11", 0xD555}, {"A13", 0x5956}, {"Am13", 0x5955},
                                            {"A5", 0x5591}, {"A6", 0x1911}, {"Am6", 0x4991}, {"Aadd9", 0x5152}, {"Amadd9", 0x5151}};

// All the chords for A#/Bb excluding Bb11 as it requires a fret past the fourth fret
const struct chord_positions chords_Bb[] = {{"Bb", 0x5749}, {"Bbm", 0x5746}, {"Bbaug", 0x5849}, {"Bbdim", 0x5446}, 
                                            {"Bb7", 0x5758}, {"Bbm7", 0x5757}, {"Bbmaj7", 0x5649}, {"Bbaug7", 0x5858}, {"Bbdim7", 0x5456} ,{"Bbm7b5", 0x5457}, {"BbMaj7", 0x5646},
                                            {"Bbsus2", 0x5745}, {"Bbsus4", 0x5775}, {"Bb7sus2", 0x5754}, {"Bb7sus4", 0x5764}, 
                                            {"Bb9", 0x8549}, {"Bbm9", 0x8546}, {"Bbmaj9", 0xD551}, {"Bbm11", 0x5D91}, {"Bb13", 0x9459}, {"Bbm13", 0x6457},
                                            {"Bb5", 0x5745}, {"Bb6", 0x5759}, {"Bbm6", 0x5756}, {"Bbadd9", 0x4649}, {"Bbmadd9", 0x4646}};

// All the chords for B
const struct chord_positions chords_B[] = {{"B", 0x5D25}, {"Bm", 0x5D19}, {"Baug", 0x6125}, {"Bdim", 0x5219},
                                            {"B7", 0x5D61}, {"Bm7", 0x5D5D}, {"Bmaj7", 0x5825}, {"Baug7", 0x6161}, {"Bdim7", 0x5258}, {"Bm7b5", 0x525D} ,{"BmMaj7", 0x5D49},
                                            {"Bsus2", 0x5D12}, {"Bsus4", 0x5DD5}, {"B7sus2", 0x5D52}, {"B7sus4", 0x5D91},
                                            {"B9", 0x8549}, {"Bm9", 0x8546}, {"Bmaj9", 0x1975}, {"B11", 0x5525}, {"Bm11", 0x5519}, {"B13", 0x9161}, {"Bm13", 0x9519},
                                            {"B5", 0x5D55}, {"B6", 0x5D64}, {"Bm6", 0x5D58}, {"Badd9", 0x1925}, {"Bmadd9", 0x1919}};

// All the chords for C
const struct chord_positions chords_C[] = {{"C", 0x4555}, {"Cm", 0x7565}, {"Caug", 0x4554}, {"Cdim", 0x4965},
                                            {"C7", 0x5455}, {"Cm7", 0x7575}, {"Cmaj7", 0x5155}, {"Caug7", 0x5454}, {"Cdim7", 0x4961}, {"Cm7b5", 0x4975} ,{"CmMaj7", 0x7525},
                                            {"Csus2", 0x7559}, {"Csus4", 0x4655}, {"C7sus2", 0x7549}, {"C7sus4", 0x5755},
                                            {"C9", 0x4549}, {"Cm9", 0x8546}, {"Cmaj9", 0x1545}, {"C11", 0x5191}, {"Cm11", 0x4675}, {"C13", 0x5545}, {"Cm13", 0x915D},
                                            {"C5", 0x7555}, {"C6", 0x5555}, {"Cm6", 0x7561}, {"Cadd9", 0x4559}, {"Cmadd9", 0x1919}};

// All the chords for C#/Db
const struct chord_positions chords_Db[] = {{"Db", 0x1657}, {"Dbm", 0xD594}, {"Dbaug", 0x5652}, {"Dbdim", 0x1556},
                                            {"Db7", 0x5257}, {"Dbm7", 0x5157}, {"Dbmaj7", 0x4657}, {"Dbaug7", 0x5252}, {"Dbdim7", 0x5456}, {"Dbm7b5", 0x5156} ,{"DbmMaj7", 0x1554},
                                            {"Dbsus2", 0xD564}, {"Dbsus4", 0x1957}, {"Db7sus2", 0xD525}, {"Db7sus4", 0x5D57},
                                            {"Db9", 0x5264}, {"Dbm9", 0x1525}, {"Dbmaj9", 0x4664}, {"Db11", 0x255D}, {"Dbm11", 0x19D5}, {"Db13", 0x5716}, {"Dbm13", 0x5146},
                                            {"Db5", 0xD557}, {"Db6", 0x5757}, {"Dbm6", 0x5657}, {"Dbadd9", 0x1664}, {"Dbmadd9", 0x1564}};

// All the chords for D
const struct chord_positions chords_D[] = {{"D", 0x595D}, {"Dm", 0x565D}, {"Daug", 0x5849}, {"Ddim", 0x5658},
                                            {"D7", 0x495D}, {"Dm7", 0x465D}, {"Dmaj7", 0x195D}, {"Daug7", 0x4949}, {"Ddim7", 0x5258}, {"Dm7b5", 0x4658} ,{"DmMaj7", 0x7525},
                                            {"Dsus2", 0x555D}, {"Dsus4", 0x6559}, {"D7sus2", 0x1554}, {"D7sus4", 0x755D},
                                            {"D9", 0x4625}, {"Dm9", 0x15D5}, {"Dmaj9", 0x45D5}, {"D11", 0x4959}, {"Dm11", 0x4659}, {"D13", 0x5716}, {"Dm13", 0x915D},
                                            {"D5", 0x555D}, {"D6", 0x5D5D}, {"Dm6", 0x525D}, {"Dadd9", 0x1664}, {"Dmadd9", 0x5546}};

// All the chords for D#/Eb
const struct chord_positions chords_Eb[] = {{"Eb", 0x6465}, {"Ebm", 0x5875}, {"Ebaug", 0x6265}, {"Ebdim", 0x5961},
                                            {"Eb7", 0x2575}, {"Ebm7", 0x1975}, {"Ebmaj7", 0x195C}, {"Ebaug7", 0x2525}, {"Ebdim7", 0x4961}, {"Ebm7b5", 0x1961} ,{"EbmMaj7", 0x7525},
                                            {"Ebsus2", 0x5775}, {"Ebsus4", 0x9464}, {"Eb7sus2", 0x1675}, {"Eb7sus4", 0xD575},
                                            {"Eb9", 0x5756}, {"Ebm9", 0x295D}, {"Ebmaj9", 0x8552}, {"Eb11", 0xD565}, {"Ebm11", 0x19D5}, {"Eb13", 0x2545}, {"Ebm13", 0x915D},
                                            {"Eb5", 0xD557}, {"Eb6", 0x7575}, {"Ebm6", 0x4975}, {"Ebadd9", 0x5765}, {"Ebmadd9", 0x1919}};

// All the chords for E
const struct chord_positions chords_E[] = {{"E", 0x5194}, {"Em", 0x6195}, {"Eaug", 0x4554}, {"Edim", 0x5495},
                                            {"E7", 0x5158}, {"Em7", 0x5159}, {"Emaj7", 0x5164}, {"Eaug7", 0x4558}, {"Edim7", 0x5456}, {"Em7b5", 0x5459} ,{"EmMaj7", 0x5165},
                                            {"Esus2", 0x5DD5}, {"Esus4", 0x55D5}, {"E7sus2", 0x1275}, {"E7sus4", 0xD575}, 
                                            {"E9", 0x5D58}, {"Em9", 0x4595}, {"Emaj9", 0x1575}, {"E11", 0x5558}, {"Em11", 0x5559}, {"E13", 0x1558}, {"Em13", 0x1559},
                                            {"E5", 0x51D5}, {"E6", 0xD5D5}, {"Em6", 0x5156}, {"Eadd9", 0x5D94}, {"Emadd9", 0x5D95}};

// All the chords for F
const struct chord_positions chords_F[] = {{"F", 0x5651}, {"Fm", 0x4654}, {"Faug", 0x5652}, {"Fdim", 0x5254},
                                            {"F7", 0x4661}, {"Fm7", 0x4664}, {"Fmaj7", 0x4691}, {"Faug7", 0x1661}, {"Fdim7", 0x5258}, {"Fm7b5", 0x5264}, {"FmMaj7", 0x4694},
                                            {"Fsus2", 0x4655}, {"Fsus4", 0x5745}, {"F7sus2", 0x4665}, {"F7sus4", 0xD575},
                                            {"F9", 0x5665}, {"Fm9", 0x1965}, {"Fmaj9", 0x5695}, {"F11", 0x5675}, {"Fm11", 0x5764}, {"F13", 0x5716}, {"Fm13", 0x915D},
                                            {"F5", 0x4655}, {"F6", 0x465D}, {"Fm6", 0x4658}, {"Fadd9", 0x5655}, {"Fmadd9", 0x6195}};
// All the chords for F#/Gb
const struct chord_positions chords_Gb[] = {{"Gb", 0x5846},{"Gbm", 0x5952}, {"Gbaug", 0x5849}, {"Gbdim", 0x5951},
                                            {"Gb7", 0x1985}, {"Gbm7", 0x1991}, {"Gbmaj7", 0x4691}, {"Gbaug7", 0x4594}, {"Gbdim7", 0x4961}, {"Gbm7b5", 0x4991}, {"GbmMaj7", 0x4694},
                                            {"Gbsus2", 0x1957}, {"Gbsus4", 0x5D16}, {"Gb7sus2", 0x1994}, {"Gb7sus4", 0xD575},
                                            {"Gb9", 0xD585}, {"Gbm9", 0x8546}, {"Gbmaj9", 0x5757}, {"Gb11", 0x19D5}, {"Gbm11", 0x59D5}, {"Gb13", 0x5796}, {"Gbm13", 0x915D},
                                            {"Gb5", 0x1956}, {"Gb6", 0x1975}, {"Gbm6", 0x1961}, {"Gbadd9", 0x5857}, {"Gbmadd9", 0x5957}};

// All the chords for G
const struct chord_positions chords_G[] = {{"G", 0x6159}, {"Gm", 0x6459}, {"Gaug", 0x6165}, {"Gdim", 0x6456},
                                            {"G7", 0x5259}, {"Gm7", 0x5759}, {"Gmaj7", 0x5D59}, {"Gaug7", 0x5265}, {"Gdim7", 0x5456}, {"Gm7b5", 0x5756}, {"GmMaj7", 0x5859},
                                            {"Gsus2", 0x6559}, {"Gsus4", 0x7559}, {"G7sus2", 0x5659}, {"G7sus4", 0x4659},
                                            {"G9", 0x9495}, {"Gm9", 0x5649}, {"Gmaj9", 0x5691}, {"G11", 0x5255}, {"Gm11", 0x5755}, {"G13", 0x5295}, {"Gm13", 0x5795},
                                            {"G5", 0x1956}, {"G6", 0x5159}, {"Gm6", 0x5459}, {"Gadd9", 0x9456}, {"Gmadd9", 0x6549}};

// All the chords for G#/Ab
const struct chord_positions chords_Ab[] = {{"Ab", 0x6119}, {"Abm", 0x9125}, {"Abaug", 0x4554}, {"Abdim", 0x5158},
                                            {"Ab7", 0x4964}, {"Abm7", 0x5D64}, {"Abmaj7", 0x7564}, {"Abaug7", 0x4994}, {"Abdim7", 0x5258}, {"Abm7b5", 0x5D58}, {"AbmMaj7", 0x9165},
                                            {"Absus2", 0x9464}, {"Absus4", 0xD564}, {"Ab7sus2", 0x5864}, {"Ab7sus4", 0x1964},
                                            {"Ab9", 0x5854}, {"Abm9", 0x5825}, {"Abmaj9", 0x9455}, {"Ab11", 0x4957}, {"Abm11", 0x5D91}, {"Ab13", 0xD519}, {"Abm13", 0x5D91},
                                            {"Ab5", 0x9564}, {"Ab6", 0x4664}, {"Abm6", 0x1961}, {"Abadd9", 0x8575}, {"Abmadd9", 0x9425}};

// Array of all chord roots
char chord_roots[12][3] = { "Ab", "A", "Bb", "B", "C", "Db", "D", "Eb", "E", "F", "Gb", "G" };

extern void Strum(char speed);

// Sets the positions of servos based on the time info given to it
void set_servos(int pos, int servo){

	switch(servo){
		case 0:
			switch(pos){
				case Both:
					PWM_PA6_Duty(pos);
				case String2:
					PWM_PA6_Duty(pos-800);
				case Open:
					PWM_PA6_Duty(pos);
				case String1:
					PWM_PA6_Duty(pos);
				default: PWM_PA6_Duty(pos);
			}
			break;
		case 1:
			switch(pos){
				case Both:
					PWM_PA7_Duty(pos);
				case String2:
					PWM_PA7_Duty(pos-400);
				case Open:
					PWM_PA7_Duty(pos+500);
				case String1:
					PWM_PA7_Duty(pos);
				default: PWM_PA7_Duty(pos);
			}
			break;
		case 2:
			switch(pos){
				case Both:
					PWM_PB4_Duty(pos);
				case String2:
					PWM_PB4_Duty(pos+600);
				case Open:
					PWM_PB4_Duty(pos+200);
				case String1:
					PWM_PB4_Duty(pos);
				default: PWM_PB4_Duty(pos+100);
			}
			break;
		case 3:
			switch(pos){
				case Both:
					PWM_PB5_Duty(pos);
				case String2:
					PWM_PB5_Duty(pos);
				case Open:
					PWM_PB5_Duty(pos);
				case String1:
					PWM_PB5_Duty(pos);
				default: PWM_PB5_Duty(pos);
			}
			break; 
		case 4:
			switch(pos){
				case Both:
					PWM_PB6_Duty(pos);
				case String2:
					PWM_PB6_Duty(pos);
				case Open:
					PWM_PB6_Duty(pos);
				case String1:
					PWM_PB6_Duty(pos-600);
				default: PWM_PB6_Duty(pos);
			}
			break;
		case 5:
			switch(pos){
				case Both:
					PWM_PB7_Duty(pos);
				case String2:
					PWM_PB7_Duty(pos);
				case Open:
					PWM_PB7_Duty(pos);
				case String1:
					PWM_PB7_Duty(pos+200);
				default: PWM_PB7_Duty(pos);
			}
			break;
		case 6:
			switch(pos){
				case Both:
					PWM_PC4_Duty(pos);
				case String2:
					PWM_PC4_Duty(pos-200);
				case Open:
					PWM_PC4_Duty(pos-800);
				case String1:
					PWM_PC4_Duty(pos);
				default: PWM_PC4_Duty(pos);
			}
			break;
		case 7:
			switch(pos){
				case Both:
					PWM_PC5_Duty(pos-600);
				case String2:
					PWM_PC5_Duty(pos);
				case Open:
					PWM_PC5_Duty(pos);
				case String1:
					PWM_PC5_Duty(pos);
				default: PWM_PC5_Duty(pos);
			}
			break; 		
		default:
			break;
	}
}

// Takes the requested servo position and returns the PWM signal corresponding to position
int servo_decoder(int pos, int servo_x){
	switch (pos){
		case 0:
				return String1;
		case 1:
				return Open;
		case 2:
			return String2;
		case 3:
			return Both;
		default:
			UART0_OutString("An error has occured");
	}
	// An error occured in the function if -1 is returned 
	return -1; 
}

// Does the calculations to find servo position
void find_servo(int posInfo){
	// Stores ServoX postion to be loaded
	int servo_position;
	
	// Iterates through the hex values
	for(int i = 0; i < 8; i++){
		// Extract the 2 LSB for servo_i position
		servo_position = (posInfo >> (i * 2) & 0x3);
		// Gets the PWM singal for the servo
		servo_position = servo_decoder(servo_position, i);
		set_servos(servo_position, i);
  }
}

void chord_select(int location, char *Chord_Name){
   // Used to select which chord to play  
	switch (location){
        // G#/Ab
        case 0:
            for (int i = 0; i < 27; i++) {
                if (strcmp(chords_Ab[i].chord_name, Chord_Name) == 0) {
                    // Takes the values for servo position
										find_servo(chords_Ab[i].servo_pos);
                    break;
                }
            }
						break;
        // A
        case 1:
            for(int i = 0; i < 27; i++){
                if(strcmp(chords_A[i].chord_name, Chord_Name) == 0){
                    // Takes the values for servo position
										find_servo(chords_A[i].servo_pos);
                    break;
                }
            }
						break;
        // A#/Bb
        case 2:
            for (int i = 0; i < 26; i++) {
                if (strcmp(chords_Bb[i].chord_name, Chord_Name) == 0) {
                    // Takes the values for servo position
										find_servo(chords_Bb[i].servo_pos);
                    break;
                }
            }
						break;
        // B
        case 3:
            for (int i = 0; i < 27; i++) {
                if (strcmp(chords_B[i].chord_name, Chord_Name) == 0) {
                    // Takes the values for servo position
										find_servo(chords_B[i].servo_pos);
                    break;
                }
            }
						break;
        // C
        case 4:
            for (int i = 0; i < 27; i++) {
                if (strcmp(chords_C[i].chord_name, Chord_Name) == 0) {
                    // Takes the values for servo position
										find_servo(chords_C[i].servo_pos);
                    break;
                }
            }
						break;
        // C#/Db
        case 5:
            for (int i = 0; i < 27; i++) {
                if (strcmp(chords_Db[i].chord_name, Chord_Name) == 0) {
                    // Takes the values for servo position
										find_servo(chords_Db[i].servo_pos);
                    break;
                }
            }
						break;
        // D
        case 6:
            for (int i = 0; i < 27; i++) {
                if (strcmp(chords_D[i].chord_name, Chord_Name) == 0) {
                    // Takes the values for servo position
										find_servo(chords_D[i].servo_pos);
                    break;
                }
            }
						break;
        // D#/Eb
        case 7:
            for (int i = 0; i < 27; i++) {
                if (strcmp(chords_Eb[i].chord_name, Chord_Name) == 0) {
                    // Takes the values for servo position
										find_servo(chords_Eb[i].servo_pos);
                    break;
                }
            }
						break;
        // E
        case 8:
            for (int i = 0; i < 27; i++) {
                if (strcmp(chords_E[i].chord_name, Chord_Name) == 0) {
                    // Takes the values for servo position
										find_servo(chords_E[i].servo_pos);
                    break;
                }
            }
						break;
        // F
        case 9:
            for (int i = 0; i < 27; i++) {
                if (strcmp(chords_F[i].chord_name, Chord_Name) == 0) {
                    // Takes the values for servo position
										find_servo(chords_F[i].servo_pos);
                    break;
                }
            }
						break;
        // F#/Gb
        case 10:
            for (int i = 0; i < 27; i++) {
                if (strcmp(chords_Gb[i].chord_name, Chord_Name) == 0) {
                    // Takes the values for servo position
										find_servo(chords_Gb[i].servo_pos);
                    break;
                }
            }
						break;
        // G
        case 11:
            for (int i = 0; i < 27; i++) {
                if (strcmp(chords_G[i].chord_name, Chord_Name) == 0) {
                    // Takes the values for servo position
										find_servo(chords_G[i].servo_pos);
                    break;
                }
            }
						break;
        default:
            break;

    }
}

void find_root(char *chord){
    for(int i = 0; i < 12; i++){
        // Compares the first two char to see if they match
        // Covers Bb, Db, Eb, Gb, Ab
        if (chord[1] == 'b') {
					if(strncmp(chord, chord_roots[i], 2) == 0){
						chord_select(i,chord);
						break;
					}
				}

        // Compares the first char to see if it matches
        // Covers A, B, C, D, E, F, G
        else if (strncmp(chord, chord_roots[i], 1) == 0 && chord_roots[i][1] != 'b'){
            // stores the found root note in found_root
            chord_select(i, chord); 
						break;
        }
    }
}

// Outputs the menu screen to user for options 
// For debugging
void Menu(void){
	// Starts UART on a new line for message 
  OutCRLF0();
	UART0_OutString("Uke Servo Test");
	OutCRLF0();
  OutCRLF0();
	UART0_OutString("Please Enter a Chord");
  OutCRLF0();
	OutCRLF0();
	UART0_OutString("A, Bb, B, C, Db, D, Eb, E, F, Gb, G, Ab");
	OutCRLF0(); 
	OutCRLF0();
}
