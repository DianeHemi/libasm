section .text
	global ft_strlen

ft_strlen:
	push rbp
	mov rbp, rsp
	mov rbx, rdi	;on met la string dans rbx
	mov rax, rbx	;on fait pointer rax vers rbx

loop:
	cmp byte[rax], 0	;on compare le byte sur lequel pointe rax pour voir si il vaut 0 (=fin de str)
	je end				;jump si zero flag est set
	add rax, 1			;on incremente rax
	jmp loop			;on relance la boucle

end:
	sub rax, rbx		;on soustrait les adresses pointant sur debut et fin de la str
	mov rsp, rbp
	pop rbp
	ret					;on return
