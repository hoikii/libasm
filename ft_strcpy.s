; function arguments are stored in rdi, rsi, rdx, ...
; We will use cl as temporary register, so backup its contents first
; then restore it at end.
; -----------------------------------------------------
;
;	ft_strcpy(char *dst, const char *src)
;	{
;		if (src == NULL)
;			return dst;
;		int i = 0;
;		while (true)
;		{
;			*(dst + i) = *(src + i);
;			if ( *(dst + i) == '\0' )
;				break ;
;			i++;
;		}
;		return dst;
;	}
; ------------------------------------------------------

section .text
	global _ft_strcpy

_ft_strcpy:
	push cx								; backup temporary register
	cmp	rsi, 0							; return if src==NULL
	je	done
	mov	rax, 0
loop:
		mov cl, BYTE [rsi + rax]		; memory-memory operation is impossile
		mov	BYTE [rdi + rax], cl
		cmp	cl, 0
		je	done
		inc	rax
		jmp loop
done:
	mov	rax, rdi
	pop	cx								; restore temporary register
	ret
