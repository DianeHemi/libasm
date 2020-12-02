section .text
	global ft_read
	extern	__errno_location

ft_read:
	mov		rax, 0		;invoke SYS_READ (opcode 0)
	syscall
	jc		error
	ret

error:
	neg		rax
	mov		rdi, rax
	call	__errno_location
	mov		[rax], rdi
	mov		rax, -1
	ret
