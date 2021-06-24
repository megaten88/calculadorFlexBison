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
}
 
%code
{
    #include "InputScanner.hpp"
    #define yylex(x) scanner->lex(x)
}
 
%token <long long>  INT
%token <double>     FLT
%token <char>       INTVAR FLTVAR
%token              EOL
%token              LPAREN
%token              RPAREN

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
        | fexp EOL                  { std::cout << "Resultado:" << $1 << '\n'; }
        | INTVAR ASSIGN iexp EOL    { ivars[$1 - 'A'] = $3; }
        | FLTVAR ASSIGN fexp EOL    { fvars[$1 - 'a'] = $3; }
        | error EOL                 { yyerrok; }
        ;
 
iexp    : INT                       { $$ = $1; }
        | iexp PLUS iexp            { $$ = $1 + $3; }
        | iexp MINUS iexp           { $$ = $1 - $3; }
        | iexp MULTIPLY iexp        { $$ = $1 * $3; }
        | iexp DIVIDE iexp          { if($3==0) { std::cerr<<"No se puede dividir en 0 \n"; $$=0;} else{$$ = $1 / $3; } }
        | iexp EXPONENT iexp        { $$ = pow($1, $3); }
        | MINUS iexp %prec UMINUS   { $$ = -$2; }
        | INTVAR                    { $$ = ivars[$1 - 'A']; }
        | LPAREN iexp RPAREN        { $$ = $2; }
        ;
 
fexp    : FLT                       { $$ = $1; }
        | fexp PLUS iexp            { $$ = $1 + (double)$3; }
        | fexp MINUS iexp           { $$ = $1 - (double)$3; }
        | fexp MULTIPLY iexp        { $$ = $1 * (double)$3; }
        | fexp DIVIDE iexp          { if($3==0) { std::cerr<<"No se puede dividir en 0 \n"; $$=0;} else{$$ = $1 / ((double)$3); } }
        | fexp EXPONENT iexp        { $$ = pow($1, $3); }
        | fexp PLUS fexp            { $$ = $1 + $3; }
        | fexp MINUS fexp           { $$ = $1 - $3; }
        | fexp MULTIPLY fexp        { $$ = $1 * $3; }
        | fexp DIVIDE fexp          { if($3==0) { std::cerr<<"No se puede dividir en 0 \n"; $$=0;} else{$$ = $1 / $3; } }
        | fexp EXPONENT fexp        { $$ = pow($1, $3); }
        | iexp PLUS fexp            { $$ = (double)$1 + $3; }
        | iexp MINUS fexp           { $$ = (double)$1 - $3; }
        | iexp MULTIPLY fexp        { $$ = (double)$1 * $3; }
        | iexp DIVIDE fexp          { if($3==0) { std::cerr<<"No se puede dividir en 0 \n"; $$=0;} else{$$ = (double)$1 / $3; } }
        | iexp EXPONENT fexp        { $$ = pow((double)$1, $3); }
        | MINUS fexp %prec UMINUS   { $$ = -$2; }
        | FLTVAR                    { $$ = fvars[$1 - 'a']; }
        | LPAREN fexp RPAREN        { $$ = $2; }
        ;

%%
 
void calculator::Parser::error(const std::string& msg) {
    std::cerr << "Algo ocurrió." << msg << '\n';
}