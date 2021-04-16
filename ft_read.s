; By calling convention, parameters are passed through rdi, rsi, rdx, rcx, ...
; rax is used for return value.
; ft_read(fd, buf, nbytes)  -->  rdi=fd,  rsi=buf,  rdx=nbytes
; -------------------------------------------------------------

section .text
	global _ft_read
	extern ___error					; external function to get address of errno

_ft_read:
	mov		rax, 0x02000003			; 0x2000000 (MacOS)+ 0x3 (system call for read)
	syscall
	jc		err						; jump to err if Carry Flag is set
	ret

err:
	push	rax						; backup error code
	call	___error				; rax <-- address of errno
	pop		rcx
	mov		[rax], rcx
	mov		rax, -1
	ret
