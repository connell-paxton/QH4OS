bits 32
boot2:
	mov esp,kernel_stack_top
	mov ebp, kernel_stack_bottom
	extern kmain
	call kmain
	cli
	hlt


section .bss
align 4
kernel_stack_bottom: equ $
	resb 16384 ; 16 KB
kernel_stack_top: