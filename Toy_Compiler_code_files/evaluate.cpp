
#include <bits/stdc++.h>
#include "evaluate.h"
#include "Operation.h"
#include "datatypes.h"
extern std::map<int, std::map<string, Arithmetic*> > symboltable;
Operation* findValue(Operation* a, string x, Operation* b)
{
    Arithmetic* xx = dynamic_cast<Arithmetic*>(a);
    Arithmetic* yy = dynamic_cast<Arithmetic*>(b);
    return xx->findValue(x, yy);
}

Operation* setValue(Operation* a, Operation *b)
{
    Arithmetic * bb = dynamic_cast<Arithmetic*>(b);
    if(bb->type == "integer")
    {
        Integer *c = new Integer(((dynamic_cast<Integer*> (bb))->value));
        a= c;
    }
    else if(bb->type == "float")
    {
        a = new Float(((dynamic_cast<Float*> (bb))->value));
    }
    else
    {
        String *c = new String(((dynamic_cast<String*> (bb))->value));
        a=c; 
    }
    return a;
}