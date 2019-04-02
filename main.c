// this is main.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "screen.h"		// for user defined header, use double quotes
#include "sound.h"
int main()
{
	FILE *f;
	short sd[80000];
 	for(;;){
		system(RCMD);
		f = fopen("test.wav", "r");
		if(f == NULL){
			printf("Cannot open file\n");
			return 1;
			}

	clearScreen();
	setColors(RED, bg(MAGENTA));
	struct WAVHDR hdr;
	fread(&hdr; sizeof(hdr), 1, f);	//read wav header
	fread(&sd, sizeof(sd), 1, f);	//read wav data
	fclose(f);
	displayWAVHDR(hdr);
	//displayWAVDATA(sd);
	}
	resetColors();
	getchar();
}
