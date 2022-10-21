.global _start

_start:
	li a0, 0
	li a1, 32
	li a2, 0
	li a3, 0
loop:
	addi a2, a2, 1
	bne a2, a1, loop
	
	sw a3, 0(a0)
	addi a3, a3, 1
	add a2, zero, zero
	li a5, 0x10
	jalr t0, 0(a5)
