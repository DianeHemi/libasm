section .text
	global ft_strcpy

ft_strcpy: 
	push rbp 				;Save adress of previous stack frame
	mov rbp, rsp			;Adress of current stack frame
	xor rcx, rcx
	cmp rsi, 0
	je end
	jmp loop

loop:
	mov al, byte[rsi + rcx]			;on deplace le caractere dans al
	mov byte[rdi + rcx], al			;depuis al on le deplace dans rdi (dest)
	cmp al, 0
	je end
	add rcx, 1
	jmp loop

end:
	mov rax, rdi 			;On met la dest dans rax 
	mov rsp, rbp			;Pulling stack status
	pop rbp
	ret