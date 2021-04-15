; By calling convention, parameters are passed through rdi, rsi, rdx, rcx, ...
; rax is used for return value.
; ------------------------------------
;	size_t ft_strlen(const char *s)
;	{
;		if (s == NULL)
;			return ;
;		int i = 0;
;		while (s[i] != 0)
;			i++;
;		return i;
;	}
; -------------------------------------

section .text
	global _ft_strlen

_ft_strlen:
	cmp	rdi, 0						; return if arg is NULL
	je	done
	mov	rax, 0						; i = 0
loop:
		cmp	BYTE [rdi + rax], 0		; *(str + i) == 0
		je	done
		inc	rax						; i++
		jmp	loop
done:
	ret

