##
## Makefile for corewar in /home/aslafy_z/.cloud/Dropbox/projects/corewar
## 
## Made by Zadkiel Aslafy-Aharonian
## Login   <aslafy_z@epitech.net>
## 
## Started on  Wed Jul 15 16:28:37 2015 Zadkiel Aslafy-Aharonian
## Last update Wed Jul 15 16:46:32 2015 Zadkiel Aslafy-Aharonian
##

include common/common.mk

VM := arena
ASM := warbler

OPT := all

all: $(VM) $(ASM)

$(VM):
	@$(MAKE) -C vm $(OPT)

$(ASM):
	@$(MAKE) -C asm $(OPT)

PHONY += debug fdebug dere
debug: OPT := debug
debug: all

fdebug: OPT := debug
fdebug: fclean all

dere: fdebug

PHONY += clean
clean: OPT := clean
clean:
	@$(MAKE) -C vm $(OPT)
	@$(MAKE) -C asm $(OPT)

PHONY += fclean
fclean: OPT := fclean
fclean:
	@$(MAKE) -C vm $(OPT)
	@$(MAKE) -C asm $(OPT)

PHONY += re
re: fclean all

.PHONY: $(PHONY)
