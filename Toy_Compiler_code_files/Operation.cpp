#include <bits/stdc++.h>
#include "Operation.h"
#include "datatypes.h"
#include "evaluate.h"
using namespace std;

extern std::map<int, std::map<string, Arithmetic*> > symboltable;
extern int currscope;
extern std::vector<int> allscopes;
extern int threeadd;

Operation* Print::perform()
{
    Arithmetic* x = dynamic_cast<Arithmetic*>(str->perform());
    cout << (x->print()) << "\n";
    return NULL;
}

Operation* Assign::perform()
{
    Operation* x = dynamic_cast<Operation*>((a2)->perform());
    // cout << name << " " << ((dynamic_cast<Integer*>(x))->value) << endl;
    Arithmetic* xx = dynamic_cast<Arithmetic*>(setValue(NULL, x));
    // cout << name << " " << ((dynamic_cast<Integer*>(xx))->value) << endl;
    symboltable[0][name] = xx;
    return xx;
}

Operation* CreateInteger::perform()
{
    return new Integer(val);
}

Operation* CreateString::perform()
{
    return new String(val);
}

Operation* CreateFloat::perform()
{
    return new Float(val);
}

Operation* GetVal::perform()
{
    // cout << "hi\n";

    if (symboltable[0].find(name) == symboltable[0].end())
    {
        throw "Undefined variable " + name;
    }
    return symboltable[0][name];
}

Operation* Arithm::perform()
{
    Operation* y = NULL;
    Operation *a, *b;
    a = a1->perform();
    b = a2->perform();
    if(((dynamic_cast<Arithmetic*> (a))->type) != ((dynamic_cast<Arithmetic*> (b))->type) && !(x[0] == '*' && ((dynamic_cast<Arithmetic*> (a))->type) == "string" && ((dynamic_cast<Arithmetic*> (b))->type) == "integer"))
    throw "Invalid data types " + ((dynamic_cast<Arithmetic*> (a))->type) + " and " +((dynamic_cast<Arithmetic*> (b))->type) + " for operation " + x;
    Arithmetic* zz = (dynamic_cast<Arithmetic*> (a));
    Arithmetic* yy = (dynamic_cast<Arithmetic*> (b));
    y = findValue(a, x, b);
    //cout << ((dynamic_cast<Arithmetic*>(y))->name) << " = " << ((dynamic_cast<Arithmetic*>(a))->name) << " " << x << " " << ((dynamic_cast<Arithmetic*>(b))->name) << endl;
    return y;
}

Operation* If_Else::perform()
{
    vector<Operation*> v = *(a2);
    Operation* x = a1->perform();
    Integer* y = dynamic_cast<Integer*>(x);
    if(y->value != 0)
    for(int i = 0; i < v.size(); i++)
    {
        v[i]->perform();
    }
    else if(a3 != NULL)
    {
        vector<Operation*> v_ = *(a3);
        for(int i = 0; i < v_.size(); i++)
        {
            v_[i]->perform();
        }
    }
    return NULL;
}

Operation* While::perform()
{
    vector<Operation*> v = *(a2);
    Operation* x = a1->perform();
    Integer* y = dynamic_cast<Integer*>(x);
    //cout << (y->value) << "\n";
    int cnt = 0;
    while(y->value != 0)
    {
        for(int i = 0; i < v.size(); i++)
        {
            v[i]->perform();
        }
        x = a1->perform();
        y = dynamic_cast<Integer*>(x);
        //cout << (y->value);
        //cout << ((dynamic_cast<Integer*>((symboltable[0]["a"])))->value) << "\n";
        //cout << "x" << endl;
    }
    return NULL;
}
