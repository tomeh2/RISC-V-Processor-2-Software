CONFIG_INI = config.ini

include $(CONFIG_INI)

ELF_FILENAME = $(BUILDDIR)/$(PROJNAME).elf
BIN_FILENAME = $(BUILDDIR)/$(PROJNAME).bin
HEX_FILENAME = $(BUILDDIR)/$(PROJNAME).hex

FILES = $(foreach DIR,$(DIRS),$(wildcard $(DIR)/*.c $(DIR)/*.S))
OBJECTS := $(addprefix $(BUILDDIR)/,$(FILES:.c=.o))
OBJECTS := $(OBJECTS:.S=.S.o)

CMACROS = STACK_ADDR=$(STACK_ADDR) LOAD_ADDR=$(LOAD_ADDR) ORIGIN_ADDR=$(ORIGIN_ADDR) \
	UART_BASE_ADDR=$(UART_BASE_ADDR) CPU_CLK_MHZ=$(CPU_CLK_MHZ) GPIO_BASE_ADDR=$(GPIO_BASE_ADDR)
		  
BUILDDIR_DUMMY = $(BUILDDIR)/.null

$(BUILDDIR_DUMMY):
	@mkdir -p $(BUILDDIR)
	$(foreach DIR, $(DIRS), mkdir -p $(BUILDDIR)/$(DIR))
	@touch $(BUILDDIR_DUMMY)
	
$(BUILDDIR)/%.o: %.c $(BUILDDIR_DUMMY)
	$(CC) -c $< -o $@ $(CFLAGS) -Iarch -Iarch/boot -Ilib $(foreach MACRO,$(CMACROS),-D $(MACRO))
	
$(BUILDDIR)/%.S.o: %.S $(BUILDDIR_DUMMY)
	$(CC) -c $< -o $@ $(CFLAGS) -Iarch -Iarch/boot $(foreach MACRO,$(CMACROS),-D $(MACRO))
	
$(ELF_FILENAME): $(OBJECTS) 
	$(LD) -o $@ $(OBJECTS) -T $(LDSCRIPT) $(LDFLAGS)
	
$(BIN_FILENAME): $(ELF_FILENAME)
	$(OBJCOPY) -O binary $(ELF_FILENAME) $(BIN_FILENAME)
	
$(HEX_FILENAME): $(BIN_FILENAME)
	python $(PYTHON_HEX_GEN) $(BIN_FILENAME) 4096 > $(HEX_FILENAME)
	
hex: $(HEX_FILENAME)
	
decomp:
	$(OBJDUMP) $(ELF_FILENAME) -h > sections
	$(OBJDUMP) $(ELF_FILENAME) -D > decompiled
	
cleanall: 
	rm -r build