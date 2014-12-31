LLVM_CONFIG=llvm-config-3.4
CXXFLAGS=-std=c++11 `$(LLVM_CONFIG) --cxxflags`
LDFLAGS=`$(LLVM_CONFIG) --ldflags`
LDLIBS=`$(LLVM_CONFIG) --libs core` -lz -lpthread -lffi  -ltinfo -lrt -ldl -lm

assembly:assembly.cpp semantic.cpp libmylang.a

libmylang.a: lex.yy.o mylang.tab.o
	ar r libmylang.a lex.yy.o mylang.tab.o 

lex.yy.o mylang.tab.o: mylang.l mylang.y
	bison -d mylang.y
	flex mylang.l
	gcc -g -c -DYYDEBUG -DYY_DEBUG mylang.tab.c lex.yy.c

syntax: syntax.c libmylang.a 
	gcc syntax.c libmylang.a -o syntax_prog

semantic: main.cpp semantic.cpp libmylang.a

clean:
	rm -f mylang.tab.* lex.yy.* *_prog libmylang.a

