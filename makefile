base:
	flex flexLexer.l
	bison grammar.y

Parser.o: InputScanner.hpp Parser.hpp Parser.cpp
		g++ -c Parser.cpp

Scanner.o: InputScanner.hpp Scanner.hpp Scanner.cpp
		g++ -c Scanner.cpp

calculator: Parser.o Scanner.o
		g++ Parser.o Scanner.o -o calculator