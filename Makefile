VM 		:= arena

CC 		:= clang++
RM 		:= rm -f
LN 		:= ln -fs

WFLAGS 		:= -W -Wall -Wextra
IFLAGS 		:= -I./includes
CXXFLAGS 	:= $(WFLAGS) $(IFLAGS)
LDFLAGS 	:= 

all: $(VM)

VM_S := $(wildcard sources/vm/*.cpp)

VM_O 		:= $(VM_S:.cpp=.o)

$(VM): $(VM_O)
	$(CC) -o $(VM) $(LDFLAGS) $(VM_O)
clean:
	$(RM) $(VM_O)

fclean: clean
	$(RM) $(VM)

re: fclean all


