.global _start

.extern main

_start:
	li sp, 0x20000100
	jal zero, main
