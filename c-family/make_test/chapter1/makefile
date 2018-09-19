count_words: count_words.o lexer.o -lfl
	gcc count_words.o lexer.o -lfl -o count_words
count_words.o: count_words.c
	gcc -c count_words.c
lexer.o: lexer.c
	gcc -c lexer.c 
lexer.c: lexer.l
	flex -t lexer.l > lexer.c

#The -l option to gcc indicates a system library that must
#be linked into the application. The actual library name indicated by “fl” is libfl.a.
#GNU make includes special support for this syntax. When a prerequisite of the form -
#l<NAME> is seen, make searches for a file of the form libNAME.so; if no match is found,
#it then searches for libNAME.a. Here make finds /usr/lib/libfl.a and proceeds with the
#final action, linking.