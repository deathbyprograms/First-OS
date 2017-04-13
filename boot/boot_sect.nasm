[bits 16]
org 0x7c00

mov [BOOT_DISK], dl

mov bp, 8000h
mov sp, bp



mov bx, 0x1000
mov dh, 15
mov dl, [BOOT_DISK]
call disk_load

mov bx, REAL_STRING
call print_string

pusha
mov ah, 2
mov dh, 26
int 10h
popa

call switch_to_pm

jmp $

BOOT_DISK: db 0

%include "print_string.nasm"
%include "disk_load.nasm"
%include "print_string_pm.nasm"
%include "gdt.nasm"
%include "switch_to_pm.nasm"

[bits 32]

BEGIN_PM:

	call 0x1000

	jmp $

REAL_STRING: db "Loaded into real mode.", 0

times 510-($-$$)db 0
dw 0xaa55