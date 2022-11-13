.global _start

.extern startup

_start:
	li sp, STACK_ADDR
	jal zero, startup