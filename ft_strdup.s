; By calling convention, parameters are passed through rdi, rsi, rdx, rcx, ...
; rax is used for return value.
; By calling convention, rdi, rsi is caller saved register so we don't need to
; restore them befor return

section .text
	global _ft_strdup
	extern _ft_strlen
	extern _ft_strcpy
	extern _malloc

_ft_strdup:
	call	_ft_strlen
	inc		rax				; rax <-- ft_strlen(rdi) + 1
	push	rdi				; backup arg
	mov		rdi, rax		; set arg for malloc
	call	_malloc			; malloc will set errno, so we don't need to do it again.
	cmp		rax, 0
	je		done			; return if malloc failed
	mov		rdi, rax
	pop		rsi
	call	_ft_strcpy		; ft_strcpy(return of malloc, initial rdi)
done:
	ret
