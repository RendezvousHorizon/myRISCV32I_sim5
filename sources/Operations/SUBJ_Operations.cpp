//
// Created by dell on 2019/7/5.
//

#include <iostream>
#include "../../headers/Operations/SUBJ_Operations.h"
/************************************************/
/************************************************/
/************************************************/
void SB::Mem_Access() {
    mem[Mem.addr]=Mem.valB;
}
/***************************/

void SH::Mem_Access() {
    mem[Mem.addr]=Mem.valB&0xff;
    mem[Mem.addr+1]=(Mem.valB>>8)&0xff;
}
/***************************/
void SW::Mem_Access(){
    mem[Mem.addr]=Mem.valB&0xff;
    mem[Mem.addr+1]=(Mem.valB>>8)&0xff;
    mem[Mem.addr+2]=(Mem.valB>>16)&0xff;
    mem[Mem.addr+3]=(Mem.valB>>24)&0xff;
}
/************************************************/
/************************************************/
/************************************************/
void LUI::Execute() {
    Mem.valE=Exe.imm;
}
void LUI::Mem_Access() {}
void LUI::Write_Back() {
    if(Write.rd!=0)rg[Write.rd].data=(unsigned int)Write.valE;
}
/***************************/
void AUIPC::Execute() {
    Mem.valE=Exe.valP+(unsigned int)Exe.imm;
}
void AUIPC::Mem_Access() {}
void AUIPC::Write_Back() {
    if(Write.rd!=0)rg[Write.rd].data=Write.valE;
}

/************************************************/
/************************************************/
/************************************************/
void BEQ::Execute() {
    Mem.valE=Exe.valA==Exe.valB;
    Mem.valM=(Exe.valA==Exe.valB)?Exe.valP+Exe.imm:Exe.valP+4;
    check();
}
void BNE::Execute() {
    Mem.valE=Exe.valA!=Exe.valB;
    Mem.valM=(Exe.valA!=Exe.valB)?Exe.valP+Exe.imm:Exe.valP+4;
    check();
}
/***********************************/
void BLT::Execute() {
    Mem.valE=Exe.valA<Exe.valB;
    Mem.valM=(Exe.valA<Exe.valB)?Exe.valP+Exe.imm:Exe.valP+4;
    check();
}
/***********************************/
void BGE::Execute() {
    Mem.valE=Exe.valA>=Exe.valB;
    Mem.valM=(Exe.valA>=Exe.valB)?Exe.valP+Exe.imm:Exe.valP+4;
    check();
}
/***********************************/
void BLTU::Execute() {
    Mem.valE=(unsigned int)Exe.valA<(unsigned int)Exe.valB;
    Mem.valM=((unsigned int)Exe.valA<(unsigned int)Exe.valB)?Exe.valP+Exe.imm:Exe.valP+4;
    check();
}
/***********************************/

void BGEU::Execute() {
    Mem.valE=(unsigned int)Exe.valA>=(unsigned int)Exe.valB;
    Mem.valM=((unsigned int)Exe.valA>=(unsigned int)Exe.valB)?Exe.valP+Exe.imm:Exe.valP+4;
    check();
}
/************************************************/
/************************************************/
/************************************************/
void JAL::Execute() {
    Mem.valE=Exe.valP+4;
    if(!jTable.count(Exe.valP)){
        Mem.valM=Exe.valP+Exe.imm;
        jTable.insert(std::pair<int,int>(Exe.valP,Mem.valM));
        pc.data=Mem.valM;
        pc_renewed=true;
        pc.locked=false;
    }
}
void JAL::Write_Back() {
    if(Write.rd!=0)rg[Write.rd].data=Write.valE;
}