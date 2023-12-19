#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "uart_v2.h"
#include "chordProcessing.h"

#define FILENAME_SIZE 1024
#define MAX_LINE 4096
char buff[2];

struct Song {
	char chord[4];
	char timing;
};

void chordparse(void) {
	FILE *file;
	
	char filename[FILENAME_SIZE];
	char buffer[MAX_LINE];
	
	int read_line = 524;
	
	file = fopen("audio.txt", "r");
	
	if (file == NULL) {
		printf("Error opening file.\n");
	}
	
	bool keep_reading = true;
	int current_line = 1;
	do
	{
		fgets(buffer, MAX_LINE, file);
		
		if (feof(file))
		{
			keep_reading = false;
			printf("File %d lines.\n", current_line-1);
			printf("Couldn't find line %d.\n", read_line);
		}
		else if (current_line == read_line)
		{
			keep_reading = false;
			printf("Line:\n%s",buffer);	
		}
		
		current_line++;
	} while (keep_reading);
	
	fclose(file);
	
	struct Song song[50];
	
	int numCurrChord = 1;
	int numChords = 0;
	char currChord[4];
	char firstChord[4];
	bool notFirstTime = false;
	
	for (int i=0; i<strlen(buffer); i++) {
		if (buffer[i] == '"') { //found "
			i++;
			for (int j = 0; j<5; j++) { // copy contents of "" to currChord
				if (buffer[i+j] == '"') {
					i+=j;
					break;
				}
				currChord[j] = buffer[i+j];
			}
			if (strcmp(currChord, firstChord) == 0) { // currChord == firstChord
				numCurrChord++;
			} 
			else if (notFirstTime) { // currChord != firstChord
				// save chord & number
				if (numCurrChord > 10) {
					sprintf(song[numChords].chord, "%s", firstChord);
					song[numChords].timing = numCurrChord; 
					numChords++; // increment total number of chords in big list
				}
				// firstChord gets currChord
				sprintf(firstChord, "%s", currChord);
				numCurrChord = 1; // reset current chord count
			} 
			else 
			{
				// firstChord gets currChord
				sprintf(firstChord, "%s", currChord);
				notFirstTime = true;
			}
			
			// clear
			memset(currChord, 0, 4); 
			
		} else if (buffer[i] == ']') {
			if(numCurrChord > 10){
				sprintf(song[numChords].chord, "%s", firstChord);
				song[numChords].timing = numCurrChord;
			}
			break;
		}
	}
	char num[8];
	int i = 0;
	for (int i=0; i<numChords; i++) {
		uart_write(song[i].chord);
		sprintf(num, "%d", song[i].timing);
		uart_write(num);
		sleep(1);
		printf(song[i].chord);
		printf(" %d :i=%d\n", song[i].timing, i);
	}
	printf("the number of chords is: %d", numChords);
	system("echo hello");	
	uart_write("0");
	uart_write("0");			
}
