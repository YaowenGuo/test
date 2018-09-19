MV 			:= mv -f
RM 			:= rm -f
SED 		:= sed
objects		:= $(subst .c,.o,$(sources))
dependencies:= $(subst .c,.o,$(sources))
inclide_dirs:= .. ../../include	
CPPFLAGS	+= $(addprefix -I ,$(inclide_dirs))
vpath %.h $(include_dirs)
.PHONY: library
library: $(library)

$(library): $(objects)

.PHONY: clean
clean:
	$(RM) $(library) $(objects) $(dependencies)
$(extra_clean)

ifneq "$(MAKECMDGOALS)" "clean"
	-include $(dependencies)
endif

%.c %.h: %.y
	$(YACC.y) --defines $<
	$(MV) y.tab.c %*.c 
	$(MV) y.tab.h $*.h

%.d: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -M $< |	\
	$(SED) 's,\($(notdir $*)\.o\) *:,$(dir $@)\l $@: ,' > $@.tmp
	mv $@.tmp $@