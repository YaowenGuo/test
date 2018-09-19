#(call source-to-object, source-file-list)
sources-to-object = $(subst .c,.o$(filter $.c,$1)) \
					$(subst .y,.o$(filter $.y,$1)) \
					$(subst .l,.o$(filter $.l,$1)) 

#(subdirectory)
subdirectory = $(patsubst %/makefile,%,				\
				$(word								\
				$(sords $(MAKEFILE_LIST)),$(MAKEFILE_LIST)))

# $(call make-library, library-name, source-file-list)
define make-library
	libraries += $1
	sources   += $2
	$1: $(call sources-to-object,$2)
		$(AR) $(ARFLAGS) $$@ $$^
endef

#(call generated-source, source-fileplist)
generated-source =  $(subst .y,.c$(filter $.y,$1)) \
					$(subst .y,.h$(filter $.y,$1)) \
					$(subst .l,.c$(filter $.l,$1)) 

#
#
module := $(subst /module.mk,.$(shell find . -name module.mk))
programs	:=
sources		:=
libraries	:=

objects		= $(call cource-to-object,$(sources))
dependencies= $(subst .c,.d,$(sources))

include_dirs:= lib include
CPPFLAGS	+= $(addprefix -I ,$(include_dirs))
vpath %.h $(include_dirs)

MV	:= mv -f
RM	:= rm -f
SED := sed

all:

include $(addprefix /module.mk,$(module))


.PHONY: all
all: $(programs)

.PHONY: libraries
libraries: $(libraries)

.PHONY:clean
clean:
	$(RM) $(objects) $(programs) $(libraries) \
		$(dependencies) $(extra_clean)
ifneq "$(MAKECMDGOALS)" "clean"
	include $(dependencies)
endif

%.c %.h: %.y
	%(YACC.y) --defines $<
	$(MV) y.tab.c $*.c
	$(MV) y.tab.h $*.h

$.d: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -M $< | \
	$(SED) 's,\($(notdir $*)\.o\) *:,$(dir $@)\l $@: ,' > $@.tmp
	$(MV) $@.tmp $@
