.global _start

.extern main

_start:
	li sp, STACK_ADDR
	jal zero, main