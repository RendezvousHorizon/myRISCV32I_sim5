//
// Created by dell on 2019/7/5.
//
#ifndef MYRISCV_SIM3_R_OPERATIONS_H
#define MYRISCV_SIM3_R_OPERATIONS_H
#include "Operations.h"

class ADD:public R_Operations{
public:
    virtual void Execute();
};
class SUB:public R_Operations{
public:
    virtual void Execute();
};
class SLL:public R_Operations{
public:
    virtual void Execute();
};
class SLT:public R_Operations{
public:
    virtual void Execute();
};
class SLTU:public R_Operations{
public:
    virtual void Execute();
};
class XOR:public R_Operations{
public:
    virtual void Execute();
};
class SRL:public R_Operations{
public:
    virtual void Execute();
};
class SRA:public R_Operations{
public:
    virtual void Execute();
};
class OR:public R_Operations{
public:
    virtual void Execute();
};
class AND:public R_Operations{
public:
    virtual void Execute();
};

#endif //MYRISCV_SIM3_R_OPERATIONS_H
