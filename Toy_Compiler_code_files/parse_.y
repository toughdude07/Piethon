%error-verbose

%{
#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include "evaluate.h"
#include "Operation.h"

using std::cerr;
using std::endl;
using std::string;
using std::cout;

extern int yylex();
extern int yylineno;
extern int threeadd;
bool error = false;

int parseResult = 1;
extern std::map<int, std::map<string, Arithmetic*> > symboltable;
extern int currscope;
extern std::vector<int> allscopes;
class Arithmetic;
void yyerror(const char* s) {
   // bision seems to call both versions of yyerror, check a flag to supress the duplicate message
   if (!error) {
      cerr << "error (line " << yylineno << "): " << s << endl;
   }
}

void yyerror(const char* s, char c) {
   cerr << "error (line " << yylineno << "): " << s << " \"" << c << "\"" << endl;
   error = true;
}

%}

%union {
    int                             intVal;
    double                          floatVal;
    char*                           ident;
    string*                         op;
    Operation*                      atm;
    string*                         data;
    vector<Operation*>*             stmt;
    vector<vector<Operation*>*>*     pr;
}

%token<intVal>   INTNUM    "int"
%token<floatVal> FLOATNUM  "float"
%token<ident>    IDENT     "identifier"
%token<data>     DATA      "string data"
%token PLUSEQ  "+="
%token MINUSEQ "-="
%token MULTEQ  "*="
%token DIVEQ   "/="
%token MODEQ   "%="
%token POWEQ   "^="
%token INC     "++"
%token DEC     "--"
%token LE      "<="
%token GE      ">="
%token EQ      "=="
%token NE      "!="
%token IF      "if"
%token ELSE    "else"
%token WHILE   "while"
%token DEF     "def"
%token PRINT   "print"
%token RETURN  "return"
%token END     "end"

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%left "<" LE ">" GE EQ NE
%left "+" "-"
%left "*" "/" "%" "^"
%nonassoc UMINUS


%type<op> assignment_op relational_op arithmetic_op 
%type<atm> expression zz print assignment list if_else while_loop
%type<stmt> program
%type<pr>   if_else_val


%%




main            : program {
                                // cout << "1\n";
                                if($1 != NULL)
                                {
                                    vector<Operation*> v = *($1);
                                    for(int i = 0; i < v.size(); i++)
                                    {
                                        try
                                        {
                                            v[i]->perform();
                                        }
                                        catch(string x)
                                        {
                                            cout << x << endl;
                                        }
                                    }
                                }
                            }
                ;

program         :    program list    {
                                // cout << "2\n";
                                if($1 == NULL && currscope == 0)
                                {
                                    try
                                    {
                                        ($2)->perform();
                                    }
                                    catch(string x)
                                    {
                                        cout << x << endl;
                                    }
                                    $$ = NULL;
                                }
                                else
                                {
                                    ($1)->push_back($2); 
                                    $$ = $1;
                                }
                            }
                |   list
                            { 
                                if(currscope == 0)
                                {
                                    try
                                    {
                                        ($1)->perform();
                                    }
                                    catch(string x)
                                    {
                                        cout << x << endl;
                                    }
                                    $$ = NULL;
                                }
                                else
                                {
                                    // cout << "22" << endl;
                                    vector<Operation*>* ab = (new vector<Operation*>());
                                    ab->push_back($1);
                                    $$ = ab; 
                                }
                            }
                ;

list            :   assignment '\n' {$$ = $1;}
                |   print '\n'      {$$ = $1;}
                |   if_else '\n'    {$$ = $1;}
                |   while_loop '\n' {$$ = $1;}
                ;

if_else         :       "if" expression ':' '\n' {currscope++;} if_else_val  {
                                                                $$ = new If_Else($2, (*($6))[0], (*($6))[1]);
                                                                currscope--;
                                                            }
                ;

if_else_val     :   program "else" ':' '\n' program "end"  {
                                                                vector<vector<Operation*>* >* p = new vector<vector<Operation*>* >();
                                                                p->push_back($1);
                                                                p->push_back($5);
                                                                $$ = p;
                                                            }
                |   program "end"   {
                                       vector<vector<Operation*>* >* p = new vector<vector<Operation*>* >();
                                                                p->push_back($1);
                                                                p->push_back(NULL);
                                                                $$ = p;
                                    }
                ;


while_loop      :   "while" expression ':' '\n' {currscope++;} program "end" {
                                                        $$ = new While($2, $6);
                                                        currscope--;
                                                    }
                ;

// stmtlst         :   stmtlst assignment '\n' { ($1)->push_back($2); 
//                                                 $$ = $1;
//                                             }
//                 |   stmtlst print '\n'      { ($1)->push_back($2); 
//                                                 $$ = $1;
//                                             }
//                 |   print '\n'              { $$ = (new vector<Operation*>());
//                                                 $$->push_back($1); 
//                                             }
//                 |   assignment '\n'         { $$ = (new vector<Operation*>());
//                                                 $$->push_back($1); 
//                                             }
                ;

// return          :   "return" expression
//                 ;

// start           :   start assignment '\n'   { ($2)->perform(); }
//                 |   start print '\n'        { ($2)->perform(); }
//                 |   assignment '\n'         { ($1)->perform(); }
//                 |   print '\n'              { ($1)->perform(); }
//                 ;




assignment      :   IDENT '=' expression    {
                                                // cout << "aye\n";
                                                $$ = new Assign($1, $3);
                                                                
                                            }
                |   IDENT assignment_op expression   {
                                                Operation* k = new GetVal($1);
                                                Operation* t = new Arithm(k, *($2), $3);
                                                $$ = new Assign($1, t);
                                            }
                ;

assignment_op   :   "-="    { $$ = new string("-="); }
                |   "+="    { $$ = new string("+="); }
                |   "/="    { $$ = new string("/="); }
                |   "%="    { $$ = new string("%="); }
                |   "*="    { $$ = new string("*="); }
                ;

expression      :   expression relational_op expression {
                                                            $$ = new Arithm($1, *($2), $3);
                                                        }
                |   expression arithmetic_op expression {
                                                           $$ = new Arithm($1, *($2), $3);
                                                        }
                |   '(' expression ')' {  
                                            $$ = $2;
                                        }
                |   zz   { 
                            $$ = $1;
                         }
                |   INTNUM  {
                                $$ = new CreateInteger($1);
                            }
                |   FLOATNUM{
                                $$ = new CreateFloat($1);
                            }
                |   DATA{
                            $$ = new CreateString(*($1));
                        }
                ;

zz              :   IDENT   {
                                $$ = new GetVal(($1));
                            }
                ;

relational_op   :   "<=" {$$ = new string("<=");}
                |   ">=" {$$ = new string(">=");}
                |   '<' {$$ = new string("<");}
                |   '>' {$$ = new string(">");}
                |   "==" {$$ = new string("==");}
                |   "!=" {$$ = new string("!=");}
                ;
            
arithmetic_op   :   '+' {$$ = new string("+");}
                |   '-' {$$ = new string("-");}
                |   "**" {$$ = new string("**");}
                |   '*' {$$ = new string("*");}
                |   '/' {$$ = new string("/");}
                |   '%' {$$ = new string("%");}
                ;

print           :   PRINT expression  {
                                            Operation* yy = ($2);
                                            $$ = new Print(yy);
                                        }
                ;
%%

std::map<int, std::map<string, Arithmetic*> > symboltable;
int currscope = 0;
int threeadd = 1;
std::vector<int> allscopes;
int main(){
    allscopes.push_back(1);
    cout << ">> ";
    return yyparse();
}
int yywrap(){
    return(1);
}