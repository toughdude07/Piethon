#include <iostream>
#include <cstdio>

using std::cerr;
using std::endl;

extern int yyparse();
extern int parseResult;
extern FILE* yyin;

int main() {
   
   // if a filename was passed on the command line, attempt to open handle for parsing

   // else, we are reading from STDIN
   yyparse();
   
   return parseResult;
}