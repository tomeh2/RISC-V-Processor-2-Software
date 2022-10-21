.global _start

.extern main

_start:
	li sp, 0x20000200
	jal zero, main
