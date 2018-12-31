DIST_VERSION      = 0.1

ifneq (,$(wildcard .git))
GITDESC           = $(subst tig-,,$(shell git describe 2>/dev/null))
COMMIT           := $(if $(GITDESC),$(GITDESC),$(DIST_VERSION)-$(shell git describe --always))
WTDIRTY           = $(if $(shell git diff-index HEAD 2>/dev/null),-dirty)
VERSION           = $(COMMIT)$(WTDIRTY)
else
VERSION           = $(DIST_VERSION)
endif

ifdef RELEASE_BUILD
VERSION           = $(DIST_VERSION)
endif

# Generating file version.h if current version has changed
VERSION_FILE     := inc/version.h
SOFTWARE_VERSION := $(shell git describe 2>/dev/null || echo '$(VERSION)')
VERSION_H        := $(shell cat $(VERSION_FILE) 2>/dev/null)
ifneq ($(lastword $(VERSION_H)),"$(SOFTWARE_VERSION)")
$(info $(shell echo   '    GEN       '$(VERSION_FILE)))
$(shell echo '#define SOFTWARE_VERSION "$(SOFTWARE_VERSION)"' > $(VERSION_FILE))
endif

# override CPPFLAGS += '-DTIG_VERSION="$(VERSION)"'

CC_TOOL           = gcc
LD_TOOL           = gcc
AR_TOOL           = ar
OBJDUMP_TOOL      = objdump

CC                = $(QUIET_CC)$(CC_TOOL)
LD                = $(QUIET_LD)$(LD_TOOL)
OBJDUMP           = $(QUIET_DUMP)$(OBJDUMP_TOOL)

SOURCES           = src
INCLUDE           = inc

# find all c files
CFILES            = $(shell find $(SOURCES) -type f -iname '*.c')
COBJS             = $(foreach cfile, $(basename $(CFILES)), $(cfile).o)
OBJS              = $(COBJS)

EXE               = src/test

CFLAGS            = -Wall -Werror -g -Os -I$(INCLUDE)

DEPS_CFLAGS       = -MMD -MP -MF .deps/$*.d

ALL_CFLAGS        = $(CFLAGS) $(DEPS_CFLAGS)
INSTALL           = install

all: $(EXE)

install: $(EXE)
	$(QUIET_INSTALL)$(INSTALL)  $(EXE) test

debug: $(EXE)
	$(OBJDUMP) -D $(EXE) > $(EXE).dis

$(EXE): $(OBJS)

%: %.o
	$(LD) $(CFLAGS) $^ -o $@

%.o: %.c
	$(Q)mkdir -p .deps/$(*D)
	$(CC) $(ALL_CFLAGS) -c -o $@ $<

-include $(OBJS:%.o=.deps/%.d)

clean:
	$(Q)$(RM) -r .deps
	$(Q)$(RM) $(OBJS) $(EXE) $(EXE).dis

distclean: clean

.PHONY: all debug clean distclean

CCCOLOR="\033[34m"
LINKCOLOR="\033[34;1m"
SRCCOLOR="\033[33m"
BINCOLOR="\033[37;1m"
MAKECOLOR="\033[32;1m"
ENDCOLOR="\033[0m"

START_LEN='   '
C_START_LEN='  '

ifndef V
# QUIET_CC = @printf '    %b %b\n' $(CCCOLOR)CC$(ENDCOLOR) $(SRCCOLOR)$@$(ENDCOLOR) 1>&2;
# QUIET_LINK = @printf '    %b %b\n' $(LINKCOLOR)LINK$(ENDCOLOR) $(BINCOLOR)$@$(ENDCOLOR) 1>&2;
# QUIET_INSTALL = @printf '    %b %b\n' $(LINKCOLOR)INSTALL$(ENDCOLOR) $(BINCOLOR)$@$(ENDCOLOR) 1>&2;
endif

Color_Off='\033[0m'       # Text Reset

# Regular Colors
Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White

# Bold
BBlack='\033[1;30m'       # Black
BRed='\033[1;31m'         # Red
BGreen='\033[1;32m'       # Green
BYellow='\033[1;33m'      # Yellow
BBlue='\033[1;34m'        # Blue
BPurple='\033[1;35m'      # Purple
BCyan='\033[1;36m'        # Cyan
BWhite='\033[1;37m'       # White

# Underline
UBlack='\033[4;30m'       # Black
URed='\033[4;31m'         # Red
UGreen='\033[4;32m'       # Green
UYellow='\033[4;33m'      # Yellow
UBlue='\033[4;34m'        # Blue
UPurple='\033[4;35m'      # Purple
UCyan='\033[4;36m'        # Cyan
UWhite='\033[4;37m'       # White

# Background
On_Black='\033[40m'       # Black
On_Red='\033[41m'         # Red
On_Green='\033[42m'       # Green
On_Yellow='\033[43m'      # Yellow
On_Blue='\033[44m'        # Blue
On_Purple='\033[45m'      # Purple
On_Cyan='\033[46m'        # Cyan
On_White='\033[47m'       # White

# High Intensity
IBlack='\033[0;90m'       # Black
IRed='\033[0;91m'         # Red
IGreen='\033[0;92m'       # Green
IYellow='\033[0;93m'      # Yellow
IBlue='\033[0;94m'        # Blue
IPurple='\033[0;95m'      # Purple
Color_Off='\033[0m'       # Text Reset

# Regular Colors
Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White

# Bold
BBlack='\033[1;30m'       # Black
BRed='\033[1;31m'         # Red
BGreen='\033[1;32m'       # Green
BYellow='\033[1;33m'      # Yellow
BBlue='\033[1;34m'        # Blue
BPurple='\033[1;35m'      # Purple
BCyan='\033[1;36m'        # Cyan
BWhite='\033[1;37m'       # White

# Underline
UBlack='\033[4;30m'       # Black
URed='\033[4;31m'         # Red
UGreen='\033[4;32m'       # Green
UYellow='\033[4;33m'      # Yellow
UBlue='\033[4;34m'        # Blue
UPurple='\033[4;35m'      # Purple
UCyan='\033[4;36m'        # Cyan
UWhite='\033[4;37m'       # White

# Background
On_Black='\033[40m'       # Black
On_Red='\033[41m'         # Red
On_Green='\033[42m'       # Green
On_Yellow='\033[43m'      # Yellow
On_Blue='\033[44m'        # Blue
On_Purple='\033[45m'      # Purple
On_Cyan='\033[46m'        # Cyan
On_White='\033[47m'       # White

# High Intensity
IBlack='\033[0;90m'       # Black
IRed='\033[0;91m'         # Red
IGreen='\033[0;92m'       # Green
IYellow='\033[0;93m'      # Yellow
IBlue='\033[0;94m'        # Blue
IPurple='\033[0;95m'      # Purple
On_IRed='\033[0;101m'     # Red
On_IGreen='\033[0;102m'   # Green
On_IYellow='\033[0;103m'  # Yellow
On_IBlue='\033[0;104m'    # Blue
On_IPurple='\033[0;105m'  # Purple
On_ICyan='\033[0;106m'    # Cyan
On_IWhite='\033[0;107m'   # White

ifndef V
# quiet and pretty print
V			= @
Q			= $(V:1=)
QUIET_CC		= $(Q:@=@echo -e  $(START_LEN)$(Cyan)CC$(Color_off)'       '$(Yellow)$@$(Color_off);)
QUIET_LD		= $(Q:@=@echo -e  $(START_LEN)$(BBlue)LINK$(Color_off)'     '$(BGreen)$@$(Color_off);)
QUIET_GEN		= $(Q:@=@echo -e  $(START_LEN)$(Cyan)GEN$(Color_off)'      '$(SRCCOLOR)$@$(Color_off);)
QUIET_DUMP		= $(Q:@=@echo -e  $(START_LEN)$(BPurple)DUMP$(Color_off)'     '$(BGreen)$<$(Color_off);)
QUIET_INSTALL		= $(Q:@=@echo -e  $(START_LEN)$(BBlue)INSTALL$(Color_off)'  '$(BGreen)$<$(Color_off);)
# QUIET_INSTALL		= $(Q:@=@printf  '   INSTALL  ';)
QUIET_ASCIIDOC		= $(Q:@=@echo    '  ASCIIDOC  '$@;)
QUIET_XMLTO		= $(Q:@=@echo    '     XMLTO  '$@;)
QUIET_DB2PDF		= $(Q:@=@echo    '    DB2PDF  '$@;)
# tools/install.sh will print 'file -> $install_dir/file'
QUIET_INSTALL_EACH	= $(Q:@=printf   '   INSTALL  ';)
QUIET_UNINSTALL		= $(Q:@=@printf  ' UNINSTALL  ';)
QUIET_UNINSTALL_EACH	= $(Q:@=printf   ' UNINSTALL  ';)
QUIET_TEST		= $(Q:@=@echo    '      TEST  '$@;)
QUIET_SUMMARY		= $(Q:@=@printf  '   SUMMARY  ';)
QUIET_LCOV		= $(Q:@=@echo    '      LCOV  '$@;)
QUIET_GENHTML		= $(Q:@=@echo    '   GENHTML  '$@;)
endif
