VPATH = src include
CPPFLAGS = -I include

SOURCES = count_words.c \
          lexer.c       \
          counter.c

count_words: counter.o lexer.o -lfl
count_words.o:counter.h
counter.o:counter.h lexer.h
lexer.o:lexer.h

include $( subst .c, .d, $(SOURCES) )

%.d: %c
	$(CC) -M $(CPPFLAGS) $< > $@.$$$$		\
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@;	\
	rm -f $@.$$$$
clean:
	rm c*
	rm l*
# 	gcc $(CPPFLAGS) -c $<
# lexer.c: lexer.l
# 	flex -t $< > $@

#The -l option to gcc indicates a system library that must
#be linked into the application. The actual library name indicated by “fl” is libfl.a.
#GNU make includes special support for this syntax. When a prerequisite of the form -
#l<NAME> is seen, make searches for a file of the form libNAME.so; if no match is found,
#it then searches for libNAME.a. Here make finds /usr/lib/libfl.a and proceeds with the
#final action, linking.
