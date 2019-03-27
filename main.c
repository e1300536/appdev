// this is main.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "screen.h"		// for user defined header, use double quotes

int main()
{
	int arr[80];		// just for making  a bar chart
	srand(time(NULL));
	for(int i=0; i<80; i++)
		arr[i] = rand()%70 + 30;

	clearScreen();
	setColors(RED, bg(MAGENTA));
//	printf("Printed from main.\n");
	barChart(arr);
	resetColors();
//	printf("Another message.\n");
	getchar();
}
