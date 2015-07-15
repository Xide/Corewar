CMDLOG := printf "  %-7s %s\n"
D_CMDLOG := printf "  %-7s D %s\n"

RM          := rm -f
RMDIR       := rm -rf
MKDIR       := mkdir -p
LN          := ln -fs
GREP        := grep

ifeq ($(V), 0)
define cond_mkdir
	@if test ! -d $(1) ; then $(CMDLOG) 'MKDIR' $(1) ; $(MKDIR) $(1) ; fi
endef
else
define cond_mkdir
	@if test ! -d $(1) ; then echo $(MKDIR) $(1) ; $(MKDIR) $(1) ; fi
endef
endif

define file_print_todo
	@$(GREP) -Eon '(TODO|NOTE|FIXME|XXX|IMPORTANT).*' $(1) 2>/dev/null | sed "s/^/    - /"; true
endef

# conditional link
define cond_link
	@if test "$(3)" == "link"; then ln -fs $(1)/$(2) $(2); else rm -f $(1)/$(2) $(2); fi
endef

# remove file
ifeq ($(V), 0)
define rm
	@$(CMDLOG) 'RM' $(1)
	@$(RM) $(1)
endef
else
define rm
	$(RM) $(1)
endef
endif

# remove directory
ifeq ($(V), 0)
define rmdir
	@$(CMDLOG) 'RM' $(1)
	@$(RMDIR) $(1)
endef
else
define rmdir
	$(RMDIR) $(1)
endef
endif

ifeq ($(LANG),c)
  CCC := $(CC)
  CCCFLAGS = $(CFLAGS)
  LANGCMD := 'CC'
else
ifeq ($(LANG),cpp)
  CCC := $(CXX)
  CCCFLAGS = $(CXXFLAGS)
  LANGCMD := 'CXX'
endif
endif

# compile source to object
ifeq ($(V), 0)
define compile
	@$(CMDLOG) $(LANGCMD) "$(1:$(OBJDIR)/%=%)"
	$(call cond_mkdir, $(3))
	$(call file_print_todo, $(2))
	@$(CCC) $(CCCFLAGS) $(4) -c -o $(1) $(2)
endef
else
define compile
	$(call cond_mkdir, $(3))
	$(call file_print_todo, $(2))
	$(CCC) $(CCCFLAGS) $(4) -c -o $(1) $(2)
endef
endif

# link binary
ifeq ($(V), 0)
define link
	@$(CMDLOG) 'LINK' $(2)
	@$(CCC) $(1) $(LDFLAGS) -o $(2)
endef
else
define link
	$(CCC) $(1) $(LDFLAGS) -o $(2)
endef
endif

# ln
ifeq ($(V), 0)
define ln
	@$(CMDLOG) 'LN' $(2)
	@$(LN) $(1) $(2)
endef
else
define ln
	$(LN) $(1) $(2)
endef
endif

# ifeq ($V,0)
# define cond_qmake
# 	@if test ! -f $(1)/Makefile ; then $(CMDLOG) 'QMAKE' $(1) ; cd $(1) ; $(QMAKE) ; cd .. ; fi
# endef
# else
# define cond_qmake
# 	@if test ! -f $(1)/Makefile ; then echo "(cd$1 ; $(QMAKE))" ; cd $(1) ; $(QMAKE) ; cd .. ; fi
# endef
# endif
