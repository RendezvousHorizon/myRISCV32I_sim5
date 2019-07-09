//
// Created by dell on 2019/7/5.
//
#include "../RISCV.h"

#ifndef MYRISCV_SIM3_OPERATIONS_HPP
#define MYRISCV_SIM3_OPERATIONS_HPP
class Operations{
public:
    void Ins_Fetch();
    virtual void Ins_Decode(){};
    virtual void Execute(){};
    virtual void Mem_Access(){};
    virtual void Write_Back(){};
};
class R_Operations:public Operations{
public:
    virtual void Ins_Decode();
    virtual void Execute(){};
    virtual void Mem_Access(){};
    virtual void Write_Back();
};
class I_Operations:public Operations{
public:
    virtual void Ins_Decode();
    virtual void Execute(){};
    virtual void Mem_Access(){};
    virtual void Write_Back(){};
};
class S_Operations:public Operations{
public:
    virtual void Ins_Decode();
    virtual void Execute();
    virtual void Mem_Access(){};
    virtual void Write_Back();
};
class B_Operations:public Operations{
public:
    virtual void Ins_Decode();
    virtual void Execute(){};
    void check();
    virtual void Mem_Access();
    virtual void Write_Back();
};
class U_Operations:public Operations{
public:
    virtual void Ins_Decode();
    virtual void Execute(){};
    virtual void Mem_Access(){};
    virtual void Write_Back(){};
};

class J_Operations:public Operations{
public:
    virtual void Ins_Decode();
    virtual void Execute(){};
    virtual void Mem_Access(){};
    virtual void Write_Back(){};
};

void data_move(int &val,const int &idx);
#endif //MYRISCV_SIM3_OPERATIONS_HPP
