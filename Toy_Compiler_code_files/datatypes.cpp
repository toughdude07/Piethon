#include <bits/stdc++.h>
#include "datatypes.h"
#include "Operation.h"
using namespace std;


extern int threeadd;
Arithmetic* Arithmetic::findValue(string x, Arithmetic* b)
{
    if(x[0] == '+')
    return add(b);
    else if(x[0] == '/')
    return divide(b);
    else if(x[0] == '%')
    return mod(b);
    else if(x[0] == '*')
    return multiply(b);
    else if(x[0] == '-')
    return subtract(b);
    else if(x[0] == '<')
    return lessthan(b);
    else if(x[0] == '>')
    return greaterthan(b);
    else if(x == "==")
    return equalto(b);
    else if(x == "<=")
    {
        Integer* x = new Integer(((dynamic_cast<Integer*> (lessthan(b)))->value) && ((dynamic_cast<Integer*> (equalto(b)))->value));
        return x;
    }
    else if(x == ">=")
    {
        Integer* x = new Integer(((dynamic_cast<Integer*> (greaterthan(b)))->value) && ((dynamic_cast<Integer*> (equalto(b)))->value));
        return x;
    }
    else if(x == "!=")
    {
        Integer* x = new Integer((!(dynamic_cast<Integer*> (equalto(b)))->value));
        return x;
    }
    return NULL;
}
Operation* Arithmetic::perform()
{
    return this;
}

string Integer::print()
{
    string x = to_string(value);
    return x;
}
Arithmetic* Integer::add(Arithmetic* a)
{
    Integer* x = new Integer(value + ((dynamic_cast<Integer*> (a))->value));
    x->name = "t" + to_string(threeadd);
    threeadd++;
    return x;
}
Arithmetic* Integer::subtract(Arithmetic* a)
{
    Integer* x = new Integer(value - ((dynamic_cast<Integer*> (a))->value));
    x->name = "t" + to_string(threeadd);
    threeadd++;
    return x;
}
Arithmetic* Integer::multiply(Arithmetic* a)
{
    Integer* x = new Integer(value * ((dynamic_cast<Integer*> (a))->value));
    x->name = "t" + to_string(threeadd);
    threeadd++;
    return x;
}
Arithmetic* Integer::divide(Arithmetic* a)
{
    Integer* x = new Integer(value / ((dynamic_cast<Integer*> (a))->value));
    x->name = "t" + to_string(threeadd);
    threeadd++;
    return x;
}
Arithmetic* Integer::mod(Arithmetic* a)
{
    Integer* x = new Integer(value%((dynamic_cast<Integer*> (a))->value));
    x->name = "t" + to_string(threeadd);
    threeadd++;
    return x;
}
Arithmetic* Integer::lessthan(Arithmetic* a)
{
    Integer* x = new Integer((value < ((dynamic_cast<Integer*> (a))->value))?1:0);
    x->name = "t" + to_string(threeadd);
    threeadd++;
    return x;
}
Arithmetic* Integer::greaterthan(Arithmetic* a)
{
    Integer* x = new Integer((value > ((dynamic_cast<Integer*> (a))->value))?1:0);
    x->name = "t" + to_string(threeadd);
    threeadd++;
    return x;
}
Arithmetic* Integer::equalto(Arithmetic* a)
{
    Integer* x = new Integer((value == ((dynamic_cast<Integer*> (a))->value))?1:0);
    x->name = "t" + to_string(threeadd);
    threeadd++;
    return x;
}

string Float::print()
{
    string x = to_string(value);
    return x;
}
Arithmetic* Float::add(Arithmetic* a)
{
    Float* x = new Float(value + ((dynamic_cast<Float*> (a))->value));
    x->name = "t" + to_string(threeadd);
    threeadd++;
    return x;
}
Arithmetic* Float::subtract(Arithmetic* a)
{
    Float* x = new Float(value - ((dynamic_cast<Float*> (a))->value));
    x->name = "t" + to_string(threeadd);
    threeadd++;
    return x;
}
Arithmetic* Float::multiply(Arithmetic* a)
{
    Float* x = new Float(value * ((dynamic_cast<Float*> (a))->value));
    x->name = "t" + to_string(threeadd);
    threeadd++;
    return x;
}
Arithmetic* Float::divide(Arithmetic* a)
{
    Float* x = new Float(value / ((dynamic_cast<Float*> (a))->value));
    x->name = "t" + to_string(threeadd);
    threeadd++;
    return x;
}
Arithmetic* Float::mod(Arithmetic* a)
{
    Float* x = new Float();
    return x;
}
Arithmetic* Float::lessthan(Arithmetic* a)
{
    Integer* x = new Integer((value < ((dynamic_cast<Integer*> (a))->value))?1:0);
    x->name = "t" + to_string(threeadd);
    threeadd++;
    return x;
}
Arithmetic* Float::greaterthan(Arithmetic* a)
{
    Integer* x = new Integer((value > ((dynamic_cast<Integer*> (a))->value))?1:0);
    x->name = "t" + to_string(threeadd);
    threeadd++;
    return x;
}
Arithmetic* Float::equalto(Arithmetic* a)
{
    Integer* x = new Integer((value == ((dynamic_cast<Integer*> (a))->value))?1:0);
    x->name = "t" + to_string(threeadd);
    threeadd++;
    return x;
}

string String::print()
{
    string x = (value);
    return x;
}
Arithmetic* String::add(Arithmetic* a)
{
    String* x = new String(value + ((dynamic_cast<String*> (a))->value));
    x->name = "t" + to_string(threeadd);
    threeadd++;
    return x;
}
Arithmetic* String::subtract(Arithmetic* a)
{
    throw "No such operation allowed";
    String* x = new String();
    return x;
}
Arithmetic* String::multiply(Arithmetic* a)
{
    int l = (dynamic_cast<Integer*> (a))->value;
    string str;
    for(int i = 0; i < l; i++)
    str = str + value;
    return new String(str);
}
Arithmetic* String::divide(Arithmetic* a)
{
    String* x = new String();
    return x;
}
Arithmetic* String::mod(Arithmetic* a)
{
    String* x = new String();
    return x;
}
Arithmetic* String::lessthan(Arithmetic* a)
{
    Integer* x = new Integer((value < ((dynamic_cast<String*> (a))->value))?1:0);
    return x;
}
Arithmetic* String::greaterthan(Arithmetic* a)
{
    Integer* x = new Integer((value > ((dynamic_cast<String*> (a))->value))?1:0);
    return x;
}
Arithmetic* String::equalto(Arithmetic* a)
{
    Integer* x = new Integer((value == ((dynamic_cast<String*> (a))->value))?1:0);
    return x;
}