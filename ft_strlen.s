section .text
	global _ft_strlen

_ft_strlen:
	mov	rax, 0						; i = 0
loop:
		cmp	BYTE [rdi + rax], 0		; *(str + i) == 0
		je	done
		inc	rax						; i++
		jmp	loop
done:
	ret

