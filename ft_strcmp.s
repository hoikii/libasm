; By calling convention, parameters are passed through rdi, rsi, rdx, rcx, ...
; rax is used for return value.
; By calling convention, cx and dx is caller saved register so we can use it as
; temporary variable.
; -----------------------------------------------------
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
loop:
		mov	cl, BYTE [rdi + rax]		; memory-to-memory operation is impossile
		cmp	cl, BYTE [rsi + rax]
		jne	differ
		cmp	cl, 0
		je	equal
		inc	rax
		jmp	loop

chk_null:
	cmp	rdi, 0
	jne	greater_null
	cmp	rsi, 0
	jne	less_null
	jmp	equal
greater_null:
	mov	rax, 1
	ret
less_null:
	mov	rax, -1
	ret

differ:
	movzx	edx, BYTE [rsi + rax]			; copy and fill target operand with zero
	movzx	eax, cl
	sub		eax, edx						; return 32bit register
	ret
equal:
	mov eax, 0
	ret
