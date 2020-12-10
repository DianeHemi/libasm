section .text
	global	ft_strdup
	extern	malloc
	extern	ft_strlen
	extern	ft_strcpy
	extern	__errno_location

ft_strdup:
	push	rdi
	call	ft_strlen
	add		rax, 1

	mov		rdi, rax
	call	malloc wrt ..plt
	cmp		rax, 0
	je		end
	jl		error
	jne		copy

copy:
	pop		rsi
	mov		rdi, rax
	call	ft_strcpy
	jmp		end

error:
	neg		rax
	mov		rdi, rax
	call	__errno_location
	mov		[rax], rdi
	mov		rax, -1
	ret

end:
	ret