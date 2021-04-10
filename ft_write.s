; function arguments are stored on rdi, rsi, rdx, ...

section .text
	global _ft_write
	extern ___error

_ft_write:			;ft_write(fd, buf, nbytes)  -->  rdi = fd, rsi = buf, rdx = nbytes
	mov		rax, 0x02000004			; 0x2000000 (MacOS)+ 0x4 (system call for write)
	syscall							; invoke system to do the read
	jc		err
	ret

err:
	push	rax
	call	___error
	pop		QWORD [rax]
	mov		rax, -1
	ret
