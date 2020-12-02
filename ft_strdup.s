section .text
	global	ft_strdup
	extern	malloc
	extern	ft_strlen
	extern	ft_strcpy

ft_strdup:
	push	rdi
	call	ft_strlen
	add		rax, 1

malloc:
	mov		rdi, rax
	call	malloc
	cmp		rax, 0
	je		end
	jne		copy

copy:
	pop		rsi
	mov		rdi, rax
	call	ft_strcpy
	jmp		end

end:
	ret





;rdi = str
;rax = strlen
