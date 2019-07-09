//
// Created by dell on 2019/7/5.
//
#include "Operations.h"
#ifndef MYRISCV_SIM3_SUBJ_OPERATIONS_HPP
#define MYRISCV_SIM3_SUBJ_OPERATIONS_HPP
class SB:public S_Operations{
public:
    virtual void Mem_Access();
};
class SH:public S_Operations{
public:
    virtual void Mem_Access();
};
class SW:public S_Operations{
public:
    virtual void Mem_Access();
};
/***********************************************/
/***********************************************/
/***********************************************/

class LUI:public U_Operations{
public:
    virtual void Execute();
    virtual void Mem_Access();
    virtual void Write_Back();
};
class AUIPC:public U_Operations{
public:
    virtual void Execute();
    virtual void Mem_Access();
    virtual void Write_Back();
};
/***********************************************/
/***********************************************/
/***********************************************/

class BEQ:public B_Operations{
public:
    virtual void Execute();
};
class BNE:public B_Operations{
public:
    virtual void Execute();
};
class BLT:public B_Operations{
public:
    virtual void Execute();
};
class BGE:public B_Operations{
public:
    virtual void Execute();
};
class BLTU:public B_Operations{
public:
    virtual void Execute();
};
class BGEU:public B_Operations{
public:
    virtual void Execute();
};
/***********************************************/
/***********************************************/
/***********************************************/

class JAL:public J_Operations{
public:
    virtual void Execute();
    virtual void Write_Back();
};
#endif //MYRISCV_SIM3_SUBJ_OPERATIONS_HPP
