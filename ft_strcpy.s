; -----------------------------------------------------
; function arguments are stored on rdi, rsi, rdx, ...
; ft_strcpy(*dst, *src) --> rdi = dst, rsi = src
;
;	ft_strcpy(char *dst, const char *src)
;	{
;		int i = 0;
;		while (*(src + i) != 0)
;		{
;			*(dst + i) = *(src + i);
;			i++;
;		}
;		*(dst + i) = '\0';
;		return dst;
;	}
; ------------------------------------------------------

section .text
	global _ft_strcpy

_ft_strcpy:
	cmp	rsi, 0
	je	done
	mov	rax, 0
loop:
		mov cl, BYTE [rsi + rax]
		mov	BYTE [rdi + rax], cl
		cmp	cl, 0
		je	done
		inc	rax
		jmp loop
add_null:
	mov		BYTE [rsi + rax], 0
done:
	mov		rax, rdi
	ret
