%{
#include <iostream>
#include <string>
#include <cmath>
#include <FlexLexer.h>
%}
 
%require "3.5.1"
%language "C++"
%defines "Parser.hpp"
%output "Parser.cpp"
 
%define api.parser.class {Parser}
%define api.namespace {calculator}
%define api.value.type variant
%parse-param {Scanner* scanner}
 
%code requires
{
    namespace calculator {
        class Scanner;
    }
} // %code requires
 
%code
{
    #include "InputScanner.hpp"
    #define yylex(x) scanner->lex(x)
}
 
%token <long long>  INT
%token <double>     FLT
%token <char>       INTVAR FLTVAR
 
%nterm <long long>  iexp
%nterm <double>     fexp
 
%nonassoc           ASSIGN
%left               PLUS MINUS
%left               MULTIPLY DIVIDE
%precedence         UMINUS
%right              EXPONENT
 
%code
{
    namespace calculator {
        long long ivars['Z' - 'A' + 1];
        double fvars['z' - 'a' + 1];
    } 
} // %code
 
%%
 
lines   : %empty
        | lines line
        ;
 
line    : EOL                       { std::cerr << "Ingrese una expresión.\n"; }
        | iexp EOL                  { std::cout << "Resultado:" << $1 << '\n'; }
        | INTVAR ASSIGN iexp EOL    { ivars[$1 - 'A'] = $3; }
        | FLTVAR ASSIGN fexp EOL    { fvars[$1 - 'a'] = $3; }
        | error EOL                 { yyerrok; }
        ;
 
iexp    : INT                       { $$ = $1; }
        | iexp PLUS iexp            { $$ = $1 + $3; }
        | iexp MINUS iexp           { $$ = $1 - $3; }
        | iexp MULTIPLY iexp        { $$ = $1 * $3; }
        | iexp DIVIDE iexp          { $$ = $1 / $3; }
        | iexp EXPONENT iexp        { $$ = pow($1, $3); }
        | MINUS iexp %prec UMINUS   { $$ = -$2; }
        | INTVAR                    { $$ = ivars[$1 - 'A']; }
        ;
 
fexp    : FLT                       { $$ = $1; }
        | fexp PLUS fexp            { $$ = $1 + $3; }
        | fexp MINUS fexp           { $$ = $1 - $3; }
        | fexp MULTIPLY fexp        { $$ = $1 * $3; }
        | fexp DIVIDE fexp          { $$ = $1 / $3; }
        | fexp EXPONENT fexp        { $$ = pow($1, $3); }
        | MINUS fexp %prec UMINUS   { $$ = -$2; }
        | FLTVAR                    { $$ = fvars[$1 - 'a']; }
        ;
 
%%
 
void calculator::Parser::error(const std::string& msg) {
    std::cerr << "Algo ocurrió." << '\n';
}