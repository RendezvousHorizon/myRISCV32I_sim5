//
// Created by dell on 2019/7/5.
//

#ifndef MYRISCV_SIM3_RISCV_H
#define MYRISCV_SIM3_RISCV_H

#include "jump_table.h"
class Operations;
struct Registers{
    int data;
    int locked;
    Registers(){data=locked=0;}
};
extern char mem[1<<22];
extern Registers Rg[32];
extern  Registers rg[32];
extern Registers PC;
extern Registers pc;
extern int endFlag;
extern int ins;
extern bool pc_renewed;
extern int rg_written;
extern bool prediction;
extern unsigned int total_prediction;
extern unsigned int correct_prediction;

class Buffer
{
public:
    Operations *p;
    int status;

    int icode;int ifun3;int ifun7;

    int rd;int rs1;int rs2;int imm;

    int valA;int valB;int addr;
    int valE;int valP;int valM;

    Buffer();
};
extern Buffer Dec,Exe,Mem,Write;
extern Operations *pIF,*pID,*pEX,*pMA,*pWB;
#endif //MYRISCV_SIM3_RISCV_H
