	.file	"main.c"
.globl f
	.bss
	.align 4
	.type	f, @object
	.size	f, 4
f:
	.zero	4
.globl v
	.align 4
	.type	v, @object
	.size	v, 4
v:
	.zero	4
.globl b
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.zero	4
.globl c
	.align 4
	.type	c, @object
	.size	c, 4
c:
	.zero	4
	.comm	srcdir,8,8
	.comm	destdir,8,8
	.text
.globl main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movl	-4(%rbp), %eax
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	getflags
	movq	-16(%rbp), %rdx
	movl	-4(%rbp), %eax
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	getdirs
	movl	$0, %eax
	call	dupdirs
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
.LC0:
	.string	"-F"
.LC1:
	.string	"-V"
.LC2:
	.string	"-b"
.LC3:
	.string	"-c"
	.text
.globl getflags
	.type	getflags, @function
getflags:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	-20(%rbp), %eax
	subl	$3, %eax
	movl	%eax, -8(%rbp)
	movl	$1, -4(%rbp)
	jmp	.L4
.L6:
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	(%rax), %rax
	movl	$.LC0, %esi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	jne	.L5
	movl	$1, f(%rip)
.L5:
	addl	$1, -4(%rbp)
.L4:
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jle	.L6
	movl	$1, -4(%rbp)
	jmp	.L7
.L9:
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	(%rax), %rax
	movl	$.LC1, %esi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	jne	.L8
	movl	$1, v(%rip)
.L8:
	addl	$1, -4(%rbp)
.L7:
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jle	.L9
	movl	$1, -4(%rbp)
	jmp	.L10
.L12:
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	(%rax), %rax
	movl	$.LC2, %esi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	jne	.L11
	movl	$1, b(%rip)
.L11:
	addl	$1, -4(%rbp)
.L10:
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jle	.L12
	movl	$1, -4(%rbp)
	jmp	.L13
.L15:
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	(%rax), %rax
	movl	$.LC3, %esi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	jne	.L14
	movl	$1, c(%rip)
.L14:
	addl	$1, -4(%rbp)
.L13:
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jle	.L15
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	getflags, .-getflags
	.section	.rodata
	.align 8
.LC4:
	.string	"Source directory and/or destination directory is invalid."
	.text
.globl getdirs
	.type	getdirs, @function
getdirs:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	-20(%rbp), %eax
	subl	$2, %eax
	movl	%eax, -8(%rbp)
	movl	-20(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -4(%rbp)
	movl	-8(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, srcdir(%rip)
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, destdir(%rip)
	movq	srcdir(%rip), %rax
	movzbl	(%rax), %eax
	cmpb	$47, %al
	jne	.L18
	movq	destdir(%rip), %rax
	movzbl	(%rax), %eax
	cmpb	$47, %al
	je	.L20
.L18:
	movl	$.LC4, %edi
	call	puts
	movl	$9, %edi
	call	exit
.L20:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	getdirs, .-getdirs
	.section	.rodata
	.align 8
.LC5:
	.string	"The source directory and/or destination directory failed to open."
	.text
.globl dupdirs
	.type	dupdirs, @function
dupdirs:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	srcdir(%rip), %rax
	movq	%rax, %rdi
	call	opendir
	movq	%rax, -16(%rbp)
	movq	destdir(%rip), %rax
	movq	%rax, %rdi
	call	opendir
	movq	%rax, -8(%rbp)
	cmpq	$0, -16(%rbp)
	je	.L22
	cmpq	$0, -8(%rbp)
	jne	.L23
.L22:
	movl	$.LC5, %edi
	call	puts
	movl	$9, %edi
	call	exit
.L23:
	movq	destdir(%rip), %rdx
	movq	srcdir(%rip), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	processdirs
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	dupdirs, .-dupdirs
	.section	.rodata
.LC6:
	.string	"."
.LC7:
	.string	".."
.LC8:
	.string	"%s/%s"
	.text
.globl processdirs
	.type	processdirs, @function
processdirs:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$2120, %rsp
	movq	%rdi, -2120(%rbp)
	movq	%rsi, -2128(%rbp)
	movq	-2120(%rbp), %rax
	movq	%rax, %rdi
	.cfi_offset 3, -24
	call	opendir
	movq	%rax, -48(%rbp)
	cmpq	$0, -48(%rbp)
	jne	.L34
	jmp	.L33
.L32:
	movl	$0, -52(%rbp)
	leaq	-52(%rbp), %rax
	movq	%rax, -32(%rbp)
	movl	$0, -20(%rbp)
	movq	-40(%rbp), %rax
	addq	$19, %rax
	movl	$.LC6, %esi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	je	.L35
	movq	-40(%rbp), %rax
	addq	$19, %rax
	movl	$.LC7, %esi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	je	.L36
.L30:
	movq	-40(%rbp), %rax
	leaq	19(%rax), %rcx
	movq	-32(%rbp), %rdx
	movq	-2128(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	CheckDestDIR
	movl	%eax, -20(%rbp)
	cmpl	$1, -20(%rbp)
	jne	.L31
	movq	-40(%rbp), %rax
	movzbl	18(%rax), %eax
	cmpb	$4, %al
	jne	.L28
	movq	-32(%rbp), %rax
	movl	(%rax), %eax
	cmpl	$1, %eax
	jne	.L28
	movq	-40(%rbp), %rax
	leaq	19(%rax), %rbx
	movl	$.LC8, %edx
	movq	-2120(%rbp), %rcx
	leaq	-1088(%rbp), %rax
	movq	%rbx, %r8
	movl	$1024, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf
	movq	-40(%rbp), %rax
	leaq	19(%rax), %rbx
	movl	$.LC8, %edx
	movq	-2128(%rbp), %rcx
	leaq	-2112(%rbp), %rax
	movq	%rbx, %r8
	movl	$1024, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf
	leaq	-2112(%rbp), %rdx
	leaq	-1088(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	processdirs
	jmp	.L28
.L31:
	movq	-40(%rbp), %rax
	leaq	19(%rax), %rbx
	movl	$.LC8, %edx
	movq	-2128(%rbp), %rcx
	leaq	-2112(%rbp), %rax
	movq	%rbx, %r8
	movl	$1024, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf
	movq	-40(%rbp), %rax
	addq	$19, %rax
	movq	%rax, %rdi
	call	puts
	leaq	-2112(%rbp), %rax
	movq	%rax, %rdi
	call	puts
	movq	-40(%rbp), %rax
	leaq	19(%rax), %rbx
	movl	$.LC8, %edx
	movq	-2120(%rbp), %rcx
	leaq	-1088(%rbp), %rax
	movq	%rbx, %r8
	movl	$1024, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf
	leaq	-2112(%rbp), %rdx
	leaq	-1088(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	CopyDirectory
	jmp	.L28
.L34:
	nop
	jmp	.L28
.L35:
	nop
	jmp	.L28
.L36:
	nop
.L28:
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	readdir
	movq	%rax, -40(%rbp)
	cmpq	$0, -40(%rbp)
	jne	.L32
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	closedir
.L33:
	addq	$2120, %rsp
	popq	%rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	processdirs, .-processdirs
.globl CheckDestDIR
	.type	CheckDestDIR, @function
CheckDestDIR:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	opendir
	movq	%rax, -16(%rbp)
	cmpq	$0, -16(%rbp)
	jne	.L45
	movl	$0, %eax
	jmp	.L39
.L43:
	movq	-8(%rbp), %rax
	leaq	19(%rax), %rdx
	movq	-32(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	strcmp
	testl	%eax, %eax
	jne	.L40
	movq	-8(%rbp), %rax
	movzbl	18(%rax), %eax
	cmpb	$4, %al
	jne	.L41
	movq	-40(%rbp), %rax
	movl	$1, (%rax)
	jmp	.L42
.L41:
	movq	-40(%rbp), %rax
	movl	$0, (%rax)
.L42:
	movl	$1, %eax
	jmp	.L39
.L45:
	nop
.L40:
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	readdir
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L43
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	closedir
	movl	$0, %eax
.L39:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	CheckDestDIR, .-CheckDestDIR
.globl CopyDirectory
	.type	CopyDirectory, @function
CopyDirectory:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$2088, %rsp
	movq	%rdi, -2088(%rbp)
	movq	%rsi, -2096(%rbp)
	movq	-2088(%rbp), %rax
	movq	%rax, %rdi
	.cfi_offset 3, -24
	call	opendir
	movq	%rax, -32(%rbp)
	cmpq	$0, -32(%rbp)
	je	.L54
.L47:
	movq	-2096(%rbp), %rax
	movq	%rax, %rdi
	call	puts
	movq	-2096(%rbp), %rax
	movl	$511, %esi
	movq	%rax, %rdi
	call	mkdir
	jmp	.L49
.L52:
	movq	-24(%rbp), %rax
	addq	$19, %rax
	movl	$.LC6, %esi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	je	.L55
	movq	-24(%rbp), %rax
	addq	$19, %rax
	movl	$.LC7, %esi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	je	.L56
.L51:
	movq	-24(%rbp), %rax
	movzbl	18(%rax), %eax
	cmpb	$4, %al
	jne	.L49
	movq	-24(%rbp), %rax
	leaq	19(%rax), %rbx
	movl	$.LC8, %edx
	movq	-2088(%rbp), %rcx
	leaq	-1056(%rbp), %rax
	movq	%rbx, %r8
	movl	$1024, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf
	movq	-24(%rbp), %rax
	leaq	19(%rax), %rbx
	movl	$.LC8, %edx
	movq	-2096(%rbp), %rcx
	leaq	-2080(%rbp), %rax
	movq	%rbx, %r8
	movl	$1024, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf
	leaq	-2080(%rbp), %rdx
	leaq	-1056(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	CopyDirectory
	jmp	.L49
.L55:
	nop
	jmp	.L49
.L56:
	nop
.L49:
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	readdir
	movq	%rax, -24(%rbp)
	cmpq	$0, -24(%rbp)
	jne	.L52
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	closedir
	jmp	.L53
.L54:
	nop
.L53:
	addq	$2088, %rsp
	popq	%rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	CopyDirectory, .-CopyDirectory
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-18)"
	.section	.note.GNU-stack,"",@progbits
