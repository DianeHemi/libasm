section .text
	global ft_strlen

ft_strlen:
	mov		rax, rdi

loop:
	cmp		byte[rax], 0
	je		end
	add		rax, 1
	jmp		loop

end:
	sub		rax, rdi
	ret
