; function arguments are stored on rdi, rsi, rdx, ...

section .text
	global _ft_read
	extern ___error

_ft_read:			;ft_read(fd, buf, nbytes)  -->  rdi = fd, rsi = buf, rdx = nbytes
	mov		rax, 0x02000003			; 0x2000000 (MacOS)+ 0x3 (system call for read)
	syscall							; invoke system to do the read
	jc		err
	ret

err:
	push	rax
	call	___error
	pop		QWORD [rax]
	mov		rax, -1
	ret
