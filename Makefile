all: parser lexer arith
	gcc -O2 parser.o lexer.o arith.o -ll -lm

parser: parser.y
	bison -d parser.y
	mv parser.tab.c parser.c
	gcc -O2 -c parser.c

lexer: lexer.fl
	flex lexer.fl
	mv lex.yy.c lexer.c
	gcc -O2 -c lexer.c

arith: arith.c arith.h
	gcc -O2 -c arith.c

clean:
	rm -f *~
	rm -f *.o
	rm -f parser.c
	rm -f parser.tab.h
	rm -f lexer.c
	rm -f a.out