	.file	"pexex.c"
	.globl	__addvdi3
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	testovf
	.type	testovf, @function
testovf:
.LFB0:
	.cfi_startproc
	movslq	big(%rip), %rdi
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$1, %esi
	movq	%rdi, %rbx
	call	__addvdi3
	cmpl	%eax, %ebx
	setg	%al
	movzbl	%al, %eax
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE0:
	.size	testovf, .-testovf
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.section	.text.unlikely
.LCOLDB1:
	.section	.text.startup,"ax",@progbits
.LHOTB1:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	rep; ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE1:
	.section	.text.startup
.LHOTE1:
	.globl	big
	.data
	.align 4
	.type	big, @object
	.size	big, 4
big:
	.long	2147483647
	.ident	"GCC: (GNU) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
