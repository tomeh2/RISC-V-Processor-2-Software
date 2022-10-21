TOOLCHAIN_PREFIX = riscv32-elf-

firmware.hex: hex 
	python makehex.py test.bin 1024 > firmware.hex

hex: firmware.elf
	riscv32-elf-objcopy -O binary firmware.elf test.bin

firmware.elf:
	riscv32-elf-gcc -Wall -Werror -march=rv32i -mabi=ilp32 test.s prog.c -o firmware.elf -ffreestanding -nostdlib -T test.ld
	
decomp:
	$(TOOLCHAIN_PREFIX)objdump firmware.elf -h > sects
	$(TOOLCHAIN_PREFIX)objdump firmware.elf -D > decomp

clean:
	rm -f *.o
	rm -f *.elf
	rm -f *.bin
	rm -f *.hex
	rm -f decomp
