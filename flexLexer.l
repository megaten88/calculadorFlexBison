%{
#include <stdlib.h>
#include "Parser.hpp"
#include "InputScanner.hpp"
#define YY_DECL int calculator::Scanner::lex(calculator::Parser::semantic_type *yylval)
%}
 
%option c++ interactive noyywrap noyylineno nodefault outfile="Scanner.cpp" header="Scanner.hpp"
 
dseq            ([[:digit:]]+)
dseq_opt        ({dseq}?)
frac            (({dseq_opt}"."{dseq})|{dseq}".")
exp             ([eE][+-]?{dseq})
exp_opt         ({exp}?)
 
integer         ({dseq})
float           (({frac}{exp_opt})|({dseq}{exp}))
intvar          ([[:upper:]])
fltvar          ([[:lower:]])
 
%%
 
{integer}       yylval->emplace<long long>(strtoll(YYText(), nullptr, 10)); return Parser::token::INT;
{float}         yylval->emplace<double>(strtod(YYText(), nullptr)); return Parser::token::FLT;
{intvar}        yylval->emplace<char>(YYText()[0]); return Parser::token::INTVAR;
{fltvar}        yylval->emplace<char>(YYText()[0]); return Parser::token::FLTVAR;
"+"             return Parser::token::PLUS;
"-"             return Parser::token::MINUS;
"*"             return Parser::token::MULTIPLY;
"/"             return Parser::token::DIVIDE;
"**"            return Parser::token::EXPONENT;
"="             return Parser::token::ASSIGN;
\n              return Parser::token::EOL;
.               /* no action on unmatched input */
 
%%
 
int yyFlexLexer::yylex() {
    throw std::runtime_error("Invalid call to yyFlexLexer::yylex()");
}
 
int main() {
    calculator::Scanner scanner{ std::cin, std::cerr };
    calculator::Parser parser{ &scanner };
    std::cout.precision(10);
    parser.parse();
}