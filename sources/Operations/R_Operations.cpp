//
// Created by dell on 2019/7/5.
//

#include <ios>
#include <iostream>
#include "../../headers/Operations/R_Operations.h"
/*********************/
void ADD::Execute(){
    Mem.valE=Exe.valA+Exe.valB;
}
/*********************/
void SUB::Execute(){
    Mem.valE=Exe.valA-Exe.valB;
}
/*********************/
void SLL::Execute(){
    Mem.valE=Exe.valA<<(Exe.valB&0x1f);
}
void SLT::Execute(){
    Mem.valE=(Exe.valA<Exe.valB);
}
void SLTU::Execute(){
    Mem.valE=(unsigned int)Exe.valA<(unsigned int)Exe.valB;
}
void XOR::Execute(){
    Mem.valE=Exe.valA^Exe.valB;
/*
    if(Mem.valP==0x1008)
        for(int i=0;i<32;i++)
            std::cout<<std::hex<<Rg[i].data<<" ";
        std::cout<<'\n';
        std::cout<<std::hex<<" "<<Mem.valA<<" "<<Mem.valB<<" "<<Mem.valE<<" "<<Mem.rs1<<" "<<Mem.rs2<<" "<<Mem.rd<<'\n';
        */
}

void SRL::Execute(){
    Mem.valE=(unsigned int)Exe.valA>>(Exe.valB&0x1f);
}
void SRA::Execute(){
    Mem.valE=Exe.valA>>(Exe.valB&0x1f);
}
void OR::Execute(){
    Mem.valE=Exe.valA|Exe.valB;
}
void AND::Execute() {
    Mem.valE=Exe.valA&Exe.valB;
}