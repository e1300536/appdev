// this is main.c
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include "screen.h"		// for user defined header, use double quotes
#include "sound.h"
#include "comm.h"
int main()
{
	FILE *f;
	short sd[RATE];
 	while(1){
		int ret = system(CMD);
		if(ret == SIGINT) break;
		f = fopen("test.wav", "r");	// open the file for read only
		clearScreen();
		setColors(YELLOW, bg(BLUE));
		if(f == NULL){
			printf("Cannot open file\n");
			return 1;
		}
		struct WAVHDR h;		//instance of wav header
		fread(&h, sizeof(h), 1, f);	//read wav header
		displayWAVHDR(h);
		fread(&sd, sizeof(sd), 1, f);	//read wav data
		displayWAVDATA(sd);
		fclose(f);			//close the opened file
		sendDATA(sd);
	}
	resetColors();
}
