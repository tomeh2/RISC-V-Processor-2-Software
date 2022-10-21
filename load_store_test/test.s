.global _start

.extern main

_start:
	li sp, 0x20008000
	jal zero, main
