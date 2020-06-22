all:
	nasm -fbin ../boot.asm -o boot
	./compile
	i686-elf-ld obj/*.o -T linker.ld -o kernel.bin


run:
	qemu-system-x86_64 -fda boot -curses