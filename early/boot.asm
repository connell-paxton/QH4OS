org 0x7c00
bits 16

boot:
	mov ax, 0x2401
	int 0x15

	mov ax, 0x3
	int 0x10

	mov [disk], dl

; ERDP read
	mov ax, 0x48
	mov dl, [disk]
	int 0x13

	mov 

;	load superblock
	mov ax, 0x400
	div word [ds:si+0x18]	; read 1024 bytes, which is 1024/BYTES_PER_SECTOR sectors
	mov ch, 0				; cylinder idx
	mov dh, 0				; head idx
	mov dl, [disk]			; disk idx
	mov cl, al				; starts at 1024 bytes, which is 1024/BYTES_PER_SECTOR sectors
	mov ah, 0x2				; read sectors
	mov bx, superblock		; where we wish to store it
	int 13

; next part, locate /sys/kernel.bin


;	loads our kernel into memory
	mov ah, 0x2			; read sectors
	mov al, 			; sectors to read
	mov ch, 0			; cylinder idx
	mov dh, 0			; head idx
	mov cl, 			; sector idx
	mov dl, [disk]		; disk idx
	mov bx,	kernel_load	; load kernel into memory so we can call it
	int 0x13
	cli
	lgdt [gdt_pointer]
	mov eax, cr0
	or eax, 0x1
	mov cr0, eax
	mov ax, DATA_SEG
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
;	jmp CODE_SEG:boot2
gdt_start:
	dq 0x0
gdt_code:
	dw 0xFFFF
	dw 0x0
	db 0x0
	db 10011010b
	db 11001111b
	db 0x0
gdt_data:
	dw 0xFFFF
	dw 0x0
	db 0x0
	db 10010010b
	db 11001111b
	db 0x0
gdt_end:
gdt_pointer:
	dw gdt_end - gdt_start
	dd gdt_start
disk:
	db 0x0
CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start


times 510 - ($-$$) db 0
dw 0xaa55
; area reserved for superblock so we can parse it
edrp:
edrp_size:
	dw 0x1E
erdp_flags:
	resb 2
erdp_num_cyl:
	resb 4
erdp_

superblock:
	resb 0x400
kernel_load: