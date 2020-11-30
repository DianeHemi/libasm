section .text
	global ft_strcmp

ft_strcmp:
	push	rbp 				;Save adress of previous stack frame
	mov		rbp, rsp			;Adress of current stack frame
	mov		rcx, 0

loop:
	mov		byte dl, [rdi + rcx]
	mov		byte dh, [rsi, rcx]
	add 	rcx, 1
	cmp		dl, 0
	je		equal
	cmp		byte dl, dh
	je		loop
	jl		lower
	jg		greater

equal:
	cmp		dh, 0
	jl		greater
	jg		lower
	mov		rax, 0
	jmp		end

lower:
	mov 	rax, -1
	jmp		end

greater:
	mov		rax, 1
	jmp		end


end:
	mov		rsp, rbp			;Pulling stack status
	pop		rbp
	ret



