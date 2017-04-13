#include "./headers/kernel.h"

#define false 0
#define true 1

void memory_copy(char* source, char* dest, int bytes){
	int i;
	if(source>dest){
		for(i=0; i<bytes;  i++){
			*(dest+i) = *(source+i);
		}
	}else if(source<dest){
		for(i=bytes-1; i>=0;  i--){
			*(dest+i) = *(source+i);
		}	
	}
}

int str_cmp(char* a, char* b){
	int answer = true;
	int i = 0;
	while(a[i]!=0&&b[i]!=0){
		if(a[i]!=b[i])answer = false;
	}
	return answer;
}

void cpu_wait(int cycles){
	int i;
	for(i = 0; i<cycles/3; i++);
}