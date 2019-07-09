//
// Created by dell on 2019/7/5.
//
#include "../headers/RISCV.h"
#include "../headers/Operations/Operations.h"

char mem[1<<22];

Registers PC;
Registers pc;
Registers Rg[32];
Registers rg[32];

int endFlag=false;
bool pc_renewed=false;
int rg_written;
int ins;
bool prediction=true;
unsigned int total_prediction=0;
unsigned int correct_prediction=0;
Buffer Dec,Exe,Mem,Write;
Operations *pIF,*pID,*pEX,*pMA,*pWB;
Buffer::Buffer(){
    status=1;
}



