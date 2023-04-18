.section .data

.section .text
		.global approved_semester

approved_semester:
		movl $0, %eax
		movw (%rdi), %r10w
		movq 8(%rdi),% rsi

for:
		cmpw $0, %r10w
		je end
		movw (%rsi), %dx
		movb $16, %r9b
		movb $0, %r8b

second_for:
		cmpb $0, %r9b
		je continue
		shrw %dx
		jnc jump_the_bite
		incb %r8b

jump_the_bite:	
		decb %r9b
		jmp second_for

continue:	
		decw %r10W
		addq $2,%rsi
		cmpb $10,%r8b
		jl for
		incl %eax
		jmp for

end:
		
ret

