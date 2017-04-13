[bits 16]

print_string:

pusha
mov ah, 0Eh
mov di, bx
print_string_loop:

cmp byte [di], 0
je print_string_end

mov al, byte [di]
int 10h
add di, 1

jmp print_string_loop

print_string_end:

popa
ret