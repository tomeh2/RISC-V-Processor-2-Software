.global _start

.extern main

_start:
	li sp, 0x20004000
	jal zero, main
