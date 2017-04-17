#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80
#define WHITE_ON_BLACK 0x0f

#define REG_SCREEN_CTRL 0x3D4
#define REG_SCREEN_DATA 0x3D5

#include "../kernel/headers/kernel.h"

int row = 0;
int col = 0;

int current_attribute=WHITE_ON_BLACK;

void default_attribute(){
	change_attribute(WHITE_ON_BLACK);
}



void clear(){
	char* start=VIDEO_ADDRESS;
	int i;
	for(i=0; i<MAX_COLS*MAX_ROWS*2; i+=2){
		start[i]=0;
		start[i+1]=current_attribute;
	}
}

void clear_row(int clr_row){
	char* start=VIDEO_ADDRESS+2*clr_row*MAX_COLS;
	int i;
	for(i=0; i<MAX_COLS*2; i+=2){
		start[i]=0;
		start[i+1]=current_attribute;
	}
}

void change_attribute(int attribute){
	char* start=VIDEO_ADDRESS+1;
	int i;
	for(i=0; i<MAX_COLS*MAX_ROWS*2; i+=2){
		start[i]=attribute;
	}
	current_attribute=attribute;
}

void handle_scrolling(){
	if(col>=80){
	row+=col/80;
	col=0;
	}
	if(row>25){
		char* source=VIDEO_ADDRESS+160*(row-25);
		char* dest=VIDEO_ADDRESS;
		memory_copy(source, dest, MAX_ROWS*MAX_COLS*2);
		row=25;
	}
	char* LAST = VIDEO_ADDRESS+2*MAX_COLS*(MAX_ROWS-1);
	int i;
	for(i = 1; i<160; i+=2){
		LAST[i]=current_attribute;	
	}
}

void new_line(){
		col=0;
		row++;
		handle_scrolling();
}

void print(char* message){
	clear_row(row);
	char* start=VIDEO_ADDRESS+(col+row*80)*2;
	int i=0;
	while(message[i]!=0){
		start[2*i]=message[i];
		col++;
		handle_scrolling();
		i++;
	}
	new_line();
}

void print_at(char* message, int print_row, int print_col){
	char* start=VIDEO_ADDRESS+(print_col+print_row*80)*2;
	int i=0;
	while(message[i]!=0){
		start[2*i]=message[i];
		i++;
	}
}