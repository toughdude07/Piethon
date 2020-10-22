#ifndef EVAL_MY
#define EVAL_MY

#include "datatypes.h"
using namespace std;
class Operation;
class Arithmetic;
Operation* findValue(Operation* a, string x, Operation* b);

Operation* setValue(Operation* a, Operation *b);

#endif