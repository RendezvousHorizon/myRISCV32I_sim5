//
// Created by dell on 2019/7/5.
//
#include <iostream>
#include "../headers/get_Operations.h"

void U_get(Operations *&ptr){
    if(Dec.icode==0x37)
        ptr=new LUI;
    else if(Dec.icode==0x17)
        ptr=new AUIPC;
    else Dec.status=1;
}
/**************************************************************************/

void J_get(Operations *&ptr){
    if(Dec.icode==0x6f)ptr=new JAL;
    else Dec.status=1;
    if(Dec.status==0){
        if(jTable.count(Dec.valP)){
            pc.data=jTable[Dec.valP];
            pc_renewed=true;
        }
        else{
            pc.locked=true;
        }
    }
}
/**************************************************************************/

void I_get(Operations *&ptr){

    if(Dec.icode==0x67){
        if(Dec.ifun3!=0){
            Dec.status=1;
            return;
        }
        ptr=new JALR;
        pc.locked=true;
    }
/****************************************************/
    else if(Dec.icode==0x03)
    {
        switch(Dec.ifun3)
        {
            case 0:ptr=new LB;break;
            case 1:ptr=new LH;break;
            case 2:ptr=new LW;break;
            case 4:ptr=new LBU;break;
            case 5:ptr=new LHU;break;
            default:Dec.status=1;
        }
    }
    else if(Dec.icode==0x13){
        switch(Dec.ifun3)
        {
            case 0:ptr=new ADDI;break;
            case 2:ptr=new SLTI;break;
            case 3:ptr=new SLTIU;break;
            case 4:ptr=new XORI;break;
            case 6:ptr=new ORI;break;
            case 7:ptr=new ANDI;break;
            case 1:ptr=new SLLI;break;
            case 5:{
                if(Dec.ifun7==0)ptr=new SRLI;
                else if(Dec.ifun7==0x20)ptr=new SRAI;
                else Dec.status=1;
                break;
            }
            default:Dec.status=1;
        }
    }
    else Dec.status=1;
}
/**************************************************************************/

void B_get(Operations *&ptr){
    switch(Dec.ifun3){
        case 0:ptr=new BEQ;break;
        case 1:ptr=new BNE;break;
        case 4:ptr=new BLT;break;
        case 5:ptr=new BGE;break;
        case 6:ptr=new BLTU;break;
        case 7:ptr=new BGEU;break;
        default:Dec.status=1;
    }
    if(Dec.status==0){
        if(Dec.imm>0){
            total_prediction++;
            pc.data=Dec.valP+4;
            pc_renewed=true;
            return;
        }
        if(bTable.count(Dec.valP)){
            total_prediction++;
            pc.data=bTable[Dec.valP];
            pc_renewed=true;
        }
        else{
            pc.locked=true;
        }
    }
}
/**************************************************************************/

void S_get(Operations *&ptr){
    switch(Dec.ifun3){
        case 0:ptr=new SB;break;
        case 1:ptr=new SH;break;
        case 2:ptr=new SW;break;
        default:Dec.status=1;
    }
}
/**************************************************************************/

void R_get(Operations *&ptr) {
    if (Dec.ifun7 == 0x20) {
        switch(Dec.ifun3)
        {
            case 0:ptr=new SUB;break;
            case 5:ptr=new SRA;break;
            default:Dec.status=1;
        }
    }
    else if(Dec.ifun7==0){
        switch(Dec.ifun3){
            case 0:ptr=new ADD;break;
            case 1:ptr=new SLL;break;
            case 2:ptr=new SLT;break;
            case 3:ptr=new SLTU;break;
            case 4:ptr=new XOR;break;
            case 5:ptr=new SRL;break;
            case 6:ptr=new OR;break;
            case 7:ptr=new AND;break;
            default:Dec.status=1;
        }
    }
    else Dec.status=1;

}
/**************************************************************************/
void get_Operations(Operations *&ptr)
{

    if(ptr)
        delete ptr;
    switch(Dec.icode)
    {
        case 0x37:
        case 0x17:U_get(ptr);break;
        case 0x6f:J_get(ptr);break;
        case 0x67:
        case 0x03:
        case 0x13:I_get(ptr);break;
        case 0x63:B_get(ptr);break;
        case 0x23:S_get(ptr);break;
        case 0x33:R_get(ptr);break;
        default:Dec.status=1;
    }
    if(Dec.status==0)
        Dec.p=pIF;

}