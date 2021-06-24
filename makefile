flex flexLexer.l
bison grammar.y
g++ -o calculator Scanner.cpp Parser.cpp
chmod +x calculator
./calculator