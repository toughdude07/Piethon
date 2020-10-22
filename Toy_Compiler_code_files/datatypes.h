#ifndef DATA_MY
#define DATA_MY
#include "Operation.h"
using namespace std;
class Integer;
class Float;
class String;
class Operation;
extern int threeadd;
class Arithmetic: public Operation
{

    public:
    Arithmetic(){}
    ~Arithmetic(){delete A;}
    Arithmetic(string t, Arithmetic* x)
    {
        type = t;
        A = x;
    }
    string type;
    Arithmetic* A;
    string name;
    Operation* perform();
    Arithmetic* findValue(string x, Arithmetic* b);

    virtual Arithmetic* add(Arithmetic* x) = 0;
    virtual Arithmetic* divide(Arithmetic* x) = 0;
    virtual Arithmetic* mod(Arithmetic* x) = 0;
    virtual Arithmetic* multiply(Arithmetic* x) = 0;
    virtual Arithmetic* subtract(Arithmetic* x) = 0;
    virtual Arithmetic* lessthan(Arithmetic* x) = 0;
    virtual Arithmetic* greaterthan(Arithmetic* x) = 0;
    virtual Arithmetic* equalto(Arithmetic* x) = 0;
    virtual string print() = 0;
};

class Integer : public Arithmetic
{
    public:
    Integer(){}
    Integer(int x, string nm = "")
    {
            type = "integer";
    A = this;
    value = x;
    if (nm == "")
    {
        nm = "t" + to_string(threeadd);
        threeadd++;
    }
    name = nm;
    }
    int value;
    Arithmetic* add(Arithmetic* a);
    Arithmetic* subtract(Arithmetic* a);
    Arithmetic* multiply(Arithmetic* a);
    Arithmetic* divide(Arithmetic* a);
    Arithmetic* mod(Arithmetic* a);
    Arithmetic* lessthan(Arithmetic* a);
    Arithmetic* greaterthan(Arithmetic* a);
    Arithmetic* equalto(Arithmetic* a);
    string print();
};

class Float : public Arithmetic
{
    public:
    Float(){}
    Float(double x, string nm = ""){
            type = "float";
    A = this;
    value = x;
    if (nm == "")
    {
        nm = "t" + to_string(threeadd);
        threeadd++;
    }
    name = nm;
    }
    double value;
    Arithmetic* add(Arithmetic* a);
    Arithmetic* subtract(Arithmetic* a);
    Arithmetic* multiply(Arithmetic* a);
    Arithmetic* divide(Arithmetic* a);
    Arithmetic* mod(Arithmetic* a);
    Arithmetic* lessthan(Arithmetic* a);
    Arithmetic* greaterthan(Arithmetic* a);
    Arithmetic* equalto(Arithmetic* a);
    string print();
};

class String : public Arithmetic
{
    public:
    String(){}
    String(string x, string nm = ""){
            type = "string";
    A = this;
    value = x;
    if (nm == "")
    {
        nm = "t" + to_string(threeadd);
        threeadd++;
    }
    name = nm;
    }
    string value;
    Arithmetic* add(Arithmetic* a);
    Arithmetic* subtract(Arithmetic* a);
    Arithmetic* multiply(Arithmetic* a);
    Arithmetic* divide(Arithmetic* a);
    Arithmetic* mod(Arithmetic* a);
    Arithmetic* lessthan(Arithmetic* a);
    Arithmetic* greaterthan(Arithmetic* a);
    Arithmetic* equalto(Arithmetic* a);
    string print();
};

#endif