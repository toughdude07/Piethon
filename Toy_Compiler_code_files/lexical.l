%option noyywrap
%option yylineno

%{
#include <bits/stdc++.h>
#include "evaluate.h"
#include "y.tab.h"

using namespace std;

extern void yyerror(const char*, char);
%}

ident [_a-zA-Z][_0-9a-zA-Z]*
int   [0-9]+
float [0-9]*\.[0-9]+
string "\""[^"\n]*"\""

%%

"#"[^\r\n]* { /* comments */    }
[ \t]       { /* whitespace */  }
[\n]        { return yytext[0]; }
"+"         { return yytext[0]; }
"-"         { return yytext[0]; }
"*"         { return yytext[0]; }
"/"         { return yytext[0]; }
"%"         { return yytext[0]; }
"^"         { return yytext[0]; }
"("         { return yytext[0]; }
")"         { return yytext[0]; }
"="         { return yytext[0]; }
":"         { return yytext[0]; }
","         { return yytext[0]; }
"<"         { return yytext[0]; }
">"         { return yytext[0]; }
"+="        { return PLUSEQ;    }
"-="        { return MINUSEQ;   }
"*="        { return MULTEQ;    }
"/="        { return DIVEQ;     }
"%="        { return MODEQ;     }
"^="        { return POWEQ;     }
"++"        { return INC;       }
"--"        { return DEC;       }
"<="        { return LE;        }
">="        { return GE;        }
"=="        { return EQ;        }
"!="        { return NE;        }
"if"        { return IF;        }
"else"      { return ELSE;      }
"def"       { return DEF;       }
"while"     { return WHILE;     }
"print"     { return PRINT;     }
"end"       { return END;       }
"return"    { return RETURN;    }

{ident}  { yylval.ident = new char[strlen(yytext)+1];
           strcpy(yylval.ident, yytext);
           return IDENT;
         }
{float}  { 
            istringstream(string(yytext)) >> yylval.floatVal;
           return FLOATNUM;
         }

{int}    { istringstream(string(yytext)) >> yylval.intVal;
           return INTNUM;
         }
{string} {
            string x = yytext;
            x = x.substr(1, x.size() - 2);
            yylval.data = (new string(x));
            return DATA;
         }
.        { yyerror("undefined token", yytext[0]); yyterminate(); }
%%