; function arguments are stored in rdi, rsi, rdx, ...
; We will use cl as temporary register, so backup its contents first
; then restore it at end.
; 
; -----------------------------------------------------
; function arguments are stored on rdi, rsi, rdx, ...
;
;	ft_strcmp(const char *s1, const char *s2)
;	{
;		if (s1 == NULL || s2 == NULL)
;		{
;			if (s1 != NULL) return 1;
;			if (s2 != NULL) return -1;
;			return 0;
;		}
;
;		int i = 0;
;		while (s1[i] == s2[i])
;		{
;			if (s1[i] == 0)
;				return 0;
;			i++;
;		}
;		return (s1[i] - s2[i]);
;	}
; -------------------------------------------------------

section .text
	global _ft_strcmp

_ft_strcmp:
	cmp	rdi, 0
	je	chk_null
	cmp	rsi, 0
	je	chk_null
	mov	rax, 0
	push	cx
loop:
		mov	cl, BYTE [rdi + rax]
		cmp	cl, BYTE [rsi + rax]
		ja	greater							; use unsigned compare
		jb	less
		cmp	cl, 0
		je	equal
		inc	rax
		jmp	loop

chk_null:
	cmp	rdi, 0
	jne	greater_null
	cmp	rsi, 0
	jne	less_null
	jmp	equal_null
greater_null:
	mov	rax, 1
	ret
less_null:
	mov	rax, -1
	ret
equal_null:
	mov	rax, 0
	ret

greater:
	movzx	rax, cl							; copy and fill target operand with zero
	movzx	rdx, BYTE [rsi + rax]
	sub		rax, rdx
	pop		cx
	ret
less:
	movzx	rax, cl
	movzx	rdx, BYTE [rsi + rax]
	sub		rax, rdx
	pop		cx
	ret
equal:
	mov	rax, 0
	pop	cx
	ret
