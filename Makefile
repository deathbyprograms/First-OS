ROUTINES = $(wildcard /boot/routines/*.nasm)
C_SOURCES = $(wildcard kernel/*.c drivers/*.c)
HEADERS = $(wildcard kernel/headers/*.h driver/headers/*.h)

OBJ = ${C_SOURCES:.c=.o}

all : os-image

run : all
	qemu-system-x86_64 ./os-image

run_bochs : all
	bochs

os-image: boot/boot_sect.bin kernel.bin
	cat $^ > os-image

kernel.bin: kernel/kernel_entry.o ${OBJ}
	ld -m elf_i386 -o $@ -Ttext 0x1000 $^ --oformat binary

%.o : %.c ${HEADERS}
	gcc -ffreestanding -m32  -c $< -o $@

%.o : %.nasm
	nasm $< -f elf -o $@

%.bin : %.nasm
	nasm $< -f bin -I './boot/routines/' -o $@

clean : 
	rm -fr *.bin *.o os-image
	rm -fr kernel/*.o boot/*.bin drivers/*.o