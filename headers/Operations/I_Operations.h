//
// Created by dell on 2019/7/5.
//
#ifndef MYRISCV_SIM3_I_OPERATIONS_H
#define MYRISCV_SIM3_I_OPERATIONS_H

#include "Operations.h"

class JALR: public I_Operations{
public:
    virtual void Execute();
    virtual void Mem_Access();
    virtual void Write_Back();
};
class LB:public I_Operations{
public:
    virtual void Execute();
    virtual void Mem_Access();
    virtual void Write_Back();
};
class LH:public I_Operations{
public:
    virtual void Execute();
    virtual void Mem_Access();
    virtual void Write_Back();
};
class LW:public I_Operations{
public:
    virtual void Execute();
    virtual void Mem_Access();
    virtual void Write_Back();
};
class LBU:public I_Operations{
public:
    virtual void Execute();
    virtual void Mem_Access();
    virtual void Write_Back();
};
class LHU:public I_Operations{
public:
    virtual void Execute();
    virtual void Mem_Access();
    virtual void Write_Back();
};
class ADDI:public I_Operations{
public:
    virtual void Execute();
    virtual void Mem_Access();
    virtual void Write_Back();
};
class SLTI:public I_Operations{
public:
    virtual void Execute();
    virtual void Mem_Access();
    virtual void Write_Back();
};
class SLTIU:public I_Operations{
public:
    virtual void Execute();
    virtual void Mem_Access();
    virtual void Write_Back();
};
class XORI:public I_Operations{
public:
    virtual void Execute();
    virtual void Mem_Access();
    virtual void Write_Back();
};
class ORI:public I_Operations{
public:
    virtual void Execute();
    virtual void Mem_Access();
    virtual void Write_Back();
};
class ANDI:public I_Operations{
public:
    virtual void Execute();
    virtual void Mem_Access();
    virtual void Write_Back();
};
class SLLI:public I_Operations{
public:
    virtual void Execute();
    virtual void Mem_Access();
    virtual void Write_Back();
};
class SRLI:public I_Operations{
public:
    virtual void Execute();
    virtual void Mem_Access();
    virtual void Write_Back();
};
class SRAI:public I_Operations{
public:
    virtual void Execute();
    virtual void Mem_Access();
    virtual void Write_Back();
};

#endif //MYRISCV_SIM3_I_OPERATIONS_H
