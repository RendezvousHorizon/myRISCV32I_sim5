//
// Created by dell on 2019/7/5.
//
#ifndef Pipeline_cpp
#define Pipeline_cpp
#include "../headers/PipeLine.h"
#include "../headers/get_Operations.h"
#include "../headers/Scanner.h"
#include <iostream>

void renew_pc(){
    if(pc_renewed==false&&Dec.status!=2&&pc.locked==false)
        pc.data+=4;
    pc_renewed=false;
}
void renewRegisters(){
    PC=pc;
    for(int i=0;i<32;i++)
        Rg[i]=rg[i];
}
int processing()
{
    //fstream io("1",ios::out);
    pIF=new Operations;
    while(true){
        if(Write.status==0){
            pWB=Write.p;
            pWB->Write_Back();
            rg_written=Write.rd;
            if(pWB)delete pWB;
            Write.status=1;

/*
            io<<std::hex<<Write.valP<<'\n';
            io<<std::hex<<Write.rd<<" "<<Write.rs1<<" "<<Write.rs2<<" "<<Write.valA<<" "<<Write.valB<<" "<<Write.valE<<'\n';
            for(int i=0;i<32;i++)
                io<<std::hex<<rg[i].data<<" ";
            io<<'\n';
*/

/*
            std::cout<<std::hex<<Write.valP<<'\n';
            std::cout<<std::hex<<Write.rd<<" "<<Write.rs1<<" "<<Write.rs2<<" "<<Write.valA<<" "<<Write.valB<<" "<<Write.valE<<'\n';
            for(int i=0;i<32;i++)
                std::cout<<std::hex<<rg[i].data<<" ";
            std::cout<<'\n';

*/
            Write.rd=-1;
        }
/***********************************/
        if(Mem.status==0){
            Write=Mem;
            pMA=Mem.p;
            pMA->Mem_Access();
            Mem.status=1;
            Mem.rd=-1;
        }
/***********************************/
        if(Exe.status==0){
            Mem=Exe;
            pEX=Exe.p;
            pEX->Execute();
            Exe.status=1;
        }
/***********************************/
        if(Dec.status==2){
            Exe=Dec;
            Exe.status=0;
            pID=Dec.p;
            pID->Ins_Decode();
            Dec.status=1;
        }
        if(Dec.status==0){
            Exe=Dec;
            pID=Dec.p;
            pID->Ins_Decode();
            if(Dec.status==0)
                Dec.status=1;
            if(Dec.status==2)
                Exe.status=1;
        }
/***********************************/
        if(Dec.status!=2&&PC.locked==false&&endFlag==false){
            //std::cout<<std::hex<<PC.data<<" ";
            pIF->Ins_Fetch();
            get_Operations(pIF);
            pIF=new Operations;

        }

        renew_pc();
        renewRegisters();
        if(endFlag==true&&Write.status==1&&Mem.status==1&&Exe.status==1&&Dec.status==1){
            if(pIF)delete pIF;
            break;
        }
    }
    //io.close();
    //std::cout<<(double)correct_prediction/total_prediction<<"\n";
    return (Rg[10].data&0xff)%253;
}

#endif
