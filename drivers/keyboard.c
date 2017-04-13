typedef struct{
	
}key;

unsigned char get_scancode(){
	return byte_in(0x60);
}

char get_char(unsigned char scancode){
	return scancode[scancode];
}

