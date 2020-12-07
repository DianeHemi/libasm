section .text
	global ft_strcmp

ft_strcmp:
	mov		rcx, 0

loop:
	mov		byte dl, [rdi + rcx]
	mov		byte dh, [rsi + rcx]
	add 	rcx, 1
	cmp		dl, 0
	je		cmp
	cmp		dh, 0
	je		cmp2
	cmp		dl, dh
	je		loop

cmp:
	sub		dl, dh
	cmp		dl, 0
	jl		lower
	jg		greater
	mov		rax, 0
	ret

cmp2:
	sub		dh, dl
	cmp		dh, 0
	jg		lower
	jl		greater
	mov		rax, 0
	ret

lower:
	mov 	rax, -1
	jmp		end

greater:
	mov 	rax, 1

end:
	ret