//
// Created by dell on 2019/7/5.
//
#include <iostream>
#include "../../headers/Operations/Operations.h"

void R_Operations::Write_Back(){
    if(Write.rd!=0)rg[Write.rd].data=Write.valE;
}
void S_Operations::Execute(){
    Mem.addr=Exe.valA+Exe.imm;
    if(Mem.addr==0x30004)
        endFlag=true;
}
void S_Operations::Write_Back() {}
/*********************************************/
void B_Operations::Write_Back(){}
void B_Operations::Mem_Access() {
}
void B_Operations::check() {
    //选择了不跳转
    if(Mem.imm>0){
        if(Mem.valE==false){
            correct_prediction++;
            return;
        }
        pc.data=Mem.valP+Mem.imm;
        pc.locked=false;
        pc_renewed=true;

        PC.locked=true;
        Dec.status=1;
        delete Dec.p;
        return;
    }
    if(!bTable.count(Mem.valP)){
        bTable.insert(std::pair<int,int>(Mem.valP,Mem.valP+Mem.imm));
        pc.data=(Mem.valE)?Mem.valM:Mem.valP+4;
        pc.locked=false;
        pc_renewed=true;
        return;
    }
    //选择了跳转
    if(Mem.valE==true){
        correct_prediction++;
        return;
    }
    //对错误预测的处理
    pc.data=Mem.valP+4;
    pc.locked=false;
    pc_renewed=true;

    PC.locked=true;
    Dec.status=1;
    delete Dec.p;
}
/************************************************************************/
void R_get_imm(){
}
void I_get_imm(){
    Dec.imm=ins>>20;
    Dec.rs2=-1;
}
void S_get_imm(){
    Dec.imm=((ins>>7)&0x1f)+(ins>>25<<5);
    Dec.rd=-1;
}
void B_get_imm(){
    Dec.imm=((ins>>7&1)<<11)+((ins>>8&0xf)<<1)+((ins>>25&0x3f)<<5)
        +(ins>>31<<12);
    Dec.rd=-1;
}
void U_get_imm(){
    Dec.imm=ins>>12<<12;
    Dec.rs1=Dec.rs2=-1;
}
void J_get_imm(){
    Dec.imm=((ins>>21&0x3ff)<<1)
        +((ins>>20&1)<<11)
        +((ins>>12&0xff)<<12)+(ins>>31<<20);
    Dec.rs1=Dec.rs2=-1;
}
/************************************************************************/
void Operations::Ins_Fetch(){
    unsigned char ch1=mem[PC.data];
    unsigned char ch2=mem[PC.data+1];
    unsigned char ch3=mem[PC.data+2];
    unsigned char ch4=mem[PC.data+3];

    ins=(int)ch1+(int)(ch2<<8)+(int)(ch3<<16)+(int)(ch4<<24);
    Dec.icode=ins&0x7f;
    Dec.valP=PC.data;

    Dec.rd=(ins>>7)&0x1f;
    Dec.ifun3=(ins>>12)&7;
    Dec.rs1=(ins>>15)&0x1f;
    Dec.rs2=(ins>>20)&0x1f;
    Dec.ifun7=(ins>>25)&0x7f;
    Dec.status=0;

    switch(Dec.icode){
        case 0x37:
        case 0x17:U_get_imm();break;
        case 0x6f:J_get_imm();break;
        case 0x67:
        case 0x03:
        case 0x13:I_get_imm();break;
        case 0x63:B_get_imm();break;
        case 0x23:S_get_imm();break;
        case 0x33:R_get_imm();break;
        default:Dec.status=1;break;
    }

}

/**************************************************************************************/
/*********Ins_Decode*******************************************************************/
/**************************************************************************************/

void data_move(int &val,const int &idx){
    if(idx==0){
        val=0;
        return;
    }
    if(Dec.status==2&&idx==Mem.rd){
        val=Write.valE;
        return;
    }
    if(idx==Mem.rd){
        val=Mem.valE;
    }
    else if(idx==Write.rd){
        val=Write.valE;
    }
    else if(idx==rg_written){
        val=rg[rg_written].data;
    }

    if(Mem.icode==0x03&&idx==Mem.rd){
        Dec.status=2;
    }//load instrucitons

}
void R_Operations::Ins_Decode() {
    Exe.valA=Rg[Dec.rs1].data;
    Exe.valB=Rg[Dec.rs2].data;
    data_move(Exe.valA,Dec.rs1);
    data_move(Exe.valB,Dec.rs2);

}
void I_Operations::Ins_Decode() {
    Exe.valA=Rg[Dec.rs1].data;
    data_move(Exe.valA,Dec.rs1);

}
void S_Operations::Ins_Decode() {
    Exe.valA=Rg[Dec.rs1].data;
    Exe.valB=Rg[Dec.rs2].data;
    data_move(Exe.valA,Dec.rs1);
    data_move(Exe.valB,Dec.rs2);
}
void B_Operations::Ins_Decode() {
    Exe.valA=Rg[Dec.rs1].data;
    Exe.valB=Rg[Dec.rs2].data;
    data_move(Exe.valA,Dec.rs1);
    data_move(Exe.valB,Dec.rs2);
}
void U_Operations::Ins_Decode() {
}
void J_Operations::Ins_Decode() {
}
