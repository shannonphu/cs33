	.file	"tri.c"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.section	.text.startup,"ax",@progbits
.LHOTB0:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	movl	$-962, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE0:
	.section	.text.startup
.LHOTE0:
	.ident	"GCC: (GNU) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
