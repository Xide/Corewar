VM 		:= arena
ASM 		:= parser


CC 		:= clang++
RM 		:= rm -f
LN 		:= ln -fs

WFLAGS 		:= -W -Wall -Wextra
IFLAGS 		:= -I./includes
CXXFLAGS 	:= $(WFLAGS) $(IFLAGS)
LDFLAGS 	:= 

all: $(VM) $(ASM)

COMMON_S := $(wildcard sources/common/*.cpp)
ASM_S := $(wildcard sources/asm/*.cpp)
VM_S := $(wildcard sources/vm/*.cpp)

COMMON_O 	:= $(COMMON_S:.cpp=.o)
ASM_O 		:= $(ASM_S:.cpp=.o)
VM_O 		:= $(VM_S:.cpp=.o)

$(VM): $(COMMON_O) $(VM_O)
	$(CC) -o $(VM) $(LDFLAGS) $(COMMON_O) $(VM_O)

$(ASM): $(COMMON_O) $(ASM_O)
	$(CC) -o $(ASM) $(LDFLAGS) $(COMMON_O) $(ASM_O)

clean:
	$(RM) $(COMMON_O)
	$(RM) $(ASM_O)
	$(RM) $(VM_O)

fclean: clean
	$(RM) $(ASM) $(VM)

re: fclean all


