; function arguments are stored on rdi, rsi, rdx, ...

section .text
	global _ft_strdup
	extern ___error
	extern _ft_strlen
	extern _ft_strcpy
	extern _malloc

_ft_strdup:
	call	_ft_strlen
	inc		rax	
	push	rdi				; backup arg
	mov		rdi, rax		; set arg
	call	_malloc
	pop		rdi
	mov		rsi, rdi
	mov		rdi, rax
	call	_ft_strcpy
	ret
