##
## Makefile for corewar in /home/aslafy_z/.cloud/Dropbox/projects/corewar
##
## Made by Zadkiel Aslafy-Aharonian
## Login   <aslafy_z@epitech.net>
##
## Started on  Wed Jul 15 16:22:23 2015 Zadkiel Aslafy-Aharonian
## Last update Wed Jul 15 17:15:28 2015 Zadkiel Aslafy-Aharonian
##

V ?= 0

NAME        := warbler
LOGFILE     := warbler.log
SRCDIR      := sources
OBJDIR      := objects

LANG	    := cpp
CXX	    = g++ -std=c++0x
DEBUG	    := 0

WFLAGS      := -W -Wall -Wextra
INCFLAGS    := -I includes -I ../common/includes
DEFFLAGS    := -DLOGFILE='"$(LOGFILE)"'
DBGFLAGS    := -DNDEBUG

LDFLAGS     :=

CXXFLAGS    = $(DEFFLAGS) $(WFLAGS) $(INCFLAGS) $(DBGFLAGS)

SOURCES     := $(subst sources/,,$(wildcard sources/*.cpp)) \
		common/Log.cpp \
		common/LogException.cpp

OBJECTS     := $(patsubst %.cpp, $(OBJDIR)/%.o, $(SOURCES))
SOURCES     := $(patsubst %.cpp, $(SRCDIR)/%.cpp, $(SOURCES))

DIST        :=
CLEAN_DIST  :=

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(call cond_mkdir, $(OBJDIR)/common)
	$(call compile, $@, $<, $(OBJDIR))

PHONY := all
all: $(DIST) $(NAME)

$(NAME): $(OBJECTS)
	$(call link, $^, $@)
	$(call ln, asm/$(NAME), ../$(NAME))

PHONY += debug fdebug dere
debug: DBGFLAGS := -g3 -rdynamic -DDEBUG
debug: CMDLOG = $(D_CMDLOG)
debug: all

fdebug: fclean debug
dere: fdebug

PHONY += clean
clean:
	$(call rmdir,$(OBJDIR))

PHONY += fclean
fclean: clean $(CLEAN_DIST)
	$(call rm,$(NAME))
	$(call rm,$(LOGFILE))
	$(call rm,../$(NAME))

PHONY += re
re: fclean all

.PHONY: $(PHONY)
.DEFAULT: all

include ../common/common.mk
