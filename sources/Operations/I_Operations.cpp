//
// Created by dell on 2019/7/5.
//
#include <ios>
#include <iostream>
#include "../../headers/Operations/I_Operations.h"
/**************************/
void JALR::Execute() {
    Mem.valM=(Exe.valA+Exe.imm)&0xfffffffe;
    Mem.valE=Exe.valP+4;

    pc.data=Mem.valM;
    pc_renewed=true;
    pc.locked=false;
}
void JALR::Mem_Access() {}
void JALR::Write_Back() {
    if(Write.rd!=0)rg[Write.rd].data=Write.valE;
}
/**************************/
void LB::Execute() {
    Mem.addr=Exe.valA+Exe.imm;
}
void LB::Mem_Access() {
    Write.valE=mem[Mem.addr];
}
void LB::Write_Back() {
    if(Write.rd!=0)rg[Write.rd].data=Write.valE;
}
/*************************/
void LH::Execute() {
    Mem.addr=Exe.valA+Exe.imm;
}
void LH::Mem_Access() {
    Write.valE=(int)(mem[Mem.addr+1]<<8)+(unsigned char)mem[Mem.addr];
}
void LH::Write_Back() {
    if(Write.rd!=0)rg[Write.rd].data=Write.valE;
}
/************************/
void LW::Execute() {
    Mem.addr=Exe.valA+Exe.imm;
}
void LW::Mem_Access() {
    Write.valE=(int)(mem[Mem.addr+3]<<24)
         +(int)((unsigned char)mem[Mem.addr+2]<<16)
         +(int)((unsigned char)mem[Mem.addr+1]<<8)
         +(int)((unsigned char)mem[Mem.addr]);
}
void LW::Write_Back() {
    if(Write.rd!=0)rg[Write.rd].data=Write.valE;
}
/************************/
void LBU::Execute() {
    Mem.addr=Exe.valA+Exe.imm;
}
void LBU::Mem_Access() {
    Write.valE=(unsigned char)mem[Mem.addr];
}
void LBU::Write_Back() {
    if(Write.rd!=0)rg[Write.rd].data=Write.valE;
}
/*************************/
void LHU::Execute() {
    Mem.addr=Exe.valA+Exe.imm;
}
void LHU::Mem_Access() {
    Write.valE=(int)((unsigned char)mem[Mem.addr+1]<<8)
         +(unsigned char)mem[Mem.addr];
}
void LHU::Write_Back() {
    if(Write.rd!=0)rg[Write.rd].data=Write.valE;
}
/*******************************************/

/*******************************************/
void ADDI::Execute() {
    Mem.valE=Exe.imm+Exe.valA;
}
void ADDI::Mem_Access() {}
void ADDI::Write_Back() {
    if(Write.rd!=0)rg[Write.rd].data=Write.valE;
}
/************************/
void SLTI::Execute() {
    Mem.valE=Exe.valA<Exe.imm;
}
void SLTI::Mem_Access() {}
void SLTI::Write_Back() {
    if(Write.rd!=0)rg[Write.rd].data=Write.valE;
}
/************************/
void SLTIU::Execute() {
    Mem.valE=(unsigned int)Exe.valA<(unsigned int)Exe.valB;
}
void SLTIU::Mem_Access() {}
void SLTIU::Write_Back() {
    if(Write.rd!=0)rg[Write.rd].data=Write.valE;
}
/************************/
void XORI::Execute() {
    Mem.valE=Exe.valA^Exe.imm;
}
void XORI::Mem_Access() {}
void XORI::Write_Back() {
    if(Write.rd!=0)rg[Write.rd].data=Write.valE;
}
/************************/
void ORI::Execute() {
    Mem.valE=Exe.valA|Exe.imm;
}
void ORI::Mem_Access() {}
void ORI::Write_Back() {
    if(Write.rd!=0)rg[Write.rd].data=Write.valE;
}
/************************/
void ANDI::Execute() {
    Mem.valE=Exe.valA&Exe.imm;
}
void ANDI::Mem_Access() {}
void ANDI::Write_Back() {
    if(Write.rd!=0)rg[Write.rd].data=Write.valE;
}
/************************/
void SLLI::Execute() {
    Mem.valE=Exe.valA<<(Exe.imm&0x1f);
}
void SLLI::Mem_Access() {}
void SLLI::Write_Back() {
    if(Write.rd!=0)rg[Write.rd].data=Write.valE;
}
/************************/
void SRLI::Execute() {
    Mem.valE=(unsigned int)Exe.valA>>(Exe.imm&0x1f);
}
void SRLI::Mem_Access() {}
void SRLI::Write_Back() {
    if(Write.rd!=0)rg[Write.rd].data=Write.valE;
}
/************************/
void SRAI::Execute() {
    Mem.valE=Exe.valA>>(Exe.imm&0x1f);
}
void SRAI::Mem_Access() {}
void SRAI::Write_Back() {
    if(Write.rd!=0)rg[Write.rd].data=Write.valE;
}