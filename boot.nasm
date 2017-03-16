[BITS 16]
org 0x7c00

mov AH,0Bh
mov BH,00h

mov BL,9
int 10h

mov AH,05h
mov AL,1
int 10h

mov AH, 02h
mov BH, 1
mov DH, 10
mov DL, 30
int 10h

mov AH, 0Eh
mov BL, 0

mov AL,'W'
int 10h
mov AL,'e'
int 10h
mov AL,'l'
int 10h
mov AL,'c'
int 10h
mov AL,'o'
int 10h
mov AL,'m'
int 10h
mov AL,'e'
int 10h
mov AL,' '
int 10h
mov AL,'t'
int 10h
mov AL,'o'
int 10h
mov AL,' '
int 10h
mov AL,'I'
int 10h
mov AL,'a'
int 10h
mov AL,'n'
int 10h
mov AL,"'"
int 10h
mov AL,'s'
int 10h
mov AL,' '
int 10h
mov AL,'O'
int 10h
mov AL,'S'
int 10h

mov AH, 02h
mov BH, 1
mov DH, 50
mov DL, 30
int 10h

jmp $

times 510-($-$$) db 0
dw 0xAA55