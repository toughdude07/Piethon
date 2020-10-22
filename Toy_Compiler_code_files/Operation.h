#ifndef ABC_MY
#define ABC_MY 
#include <bits/stdc++.h>    
using namespace std;

class Operation
{
    public:
    virtual Operation* perform() = 0;
};

class Print: public Operation
{
    public:
    Print(Operation* st)
    {
        str = st;
    }
    Operation* str;
    Operation* perform();
};

class Assign: public Operation
{
    public:
    Operation *a2;
    string name;
    Assign(char* a, Operation* b)
    {
        name = string(a);
        a2 = b;
    }
    Operation* perform();
};

class CreateInteger: public Operation
{
    public:
    int val;
    CreateInteger(int x)
    {
        val = x;
    }
    Operation* perform();
};

class CreateString: public Operation
{
    public:
    string val;
    CreateString(string x)
    {
        val = x;
    }
    Operation* perform();
};

class CreateFloat: public Operation
{
    public:
    double val;
    CreateFloat(double x)
    {
        val = x;
    }
    Operation* perform();
};

class GetVal: public Operation
{
    public:
    string name;
    GetVal(char* x)
    {
        name = string(x);
    }
    Operation* perform();
};
class Arithm: public Operation
{
    public:
    Operation* a1, *a2;
    string x;
    Arithm(Operation* a, string b, Operation* c)
    {
        Operation* xx = a;
        a1 = dynamic_cast<Operation*>(xx);
        xx = c;
        a2 = dynamic_cast<Operation*>(xx);
        x = b;
    }
    Operation* perform();
};

class If_Else: public Operation
{
    public:
    Operation* a1;
    vector<Operation*> *a2, *a3;
    If_Else(Operation* a, vector<Operation*> * c)
    {
        
        a1 = a;
        a2 = c;
        a3 = NULL;
    }
    If_Else(Operation* a, vector<Operation*> * c, vector<Operation*> * d)
    {
        
        a1 = a;
        a2 = c;
        a3 = d;
    }
    Operation* perform();
};

class While: public Operation
{
    public:
    Operation* a1;
    vector<Operation*> *a2;
    While(Operation* a, vector<Operation*> * c)
    {
        
        a1 = a;
        a2 = c;
    }
    Operation* perform();
};
#endif