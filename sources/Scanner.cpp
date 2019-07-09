//
// Created by dell on 2019/7/5.
//
#include "../headers/Scanner.h"
#include "../headers/RISCV.h"
inline int getn(char ch)
{
    if(ch>='A'&&ch<='F')
        return ch-'A'+10;
    return ch-'0';
}
void get_mem(char *memm){
    char ch;
    char ch2;
    int add=0;
    while(cin>>ch)
    {
        if(ch=='@'){
            add=0;
            for(int i=0;i<8;i++){
                cin>>ch;
                add=(add<<4)+getn(ch);
            }
            continue;
        }
        if(ch=='?') return;
        cin>>ch2;
        memm[add++]=(getn(ch)<<4)+getn(ch2);
    }
};
void get_mem2(char *memm)
{
    fstream io;
    char ch;
    char ch2;
    int add=0;
    io.open("testfile");
    if(!io){cerr<<"open file error\n";return;}
    while(io>>ch)
    {
        if(ch=='@'){
            add=0;
            for(int i=0;i<8;i++){
                io>>ch;
                add=(add<<4)+getn(ch);
            }
            continue;
        }
        io>>ch2;
        memm[add++]=(getn(ch)<<4)+getn(ch2);
    }
}
void display_mem(char *memm)
{
    for(int i=0;i<100;i++){
        cout<<hex<<(int)((unsigned char)memm[i+0x1000]>>4)<<(int)(memm[i+0x1000]&0xf)<<" ";
    }
    cout<<endl;
}
/*
void get_data(){
    io<<std::hex<<Write.valP<<'\n';
    io<<std::hex<<Write.rd<<" "<<Write.rs1<<" "<<Write.rs2<<" "<<Write.valA<<" "<<Write.valB<<" "<<Write.valE<<'\n';
    for(int i=0;i<32;i++)
        io<<std::hex<<rg[i].data<<" ";
    io<<'\n';
}
*/
void difference(){
    fstream io1("1");
    fstream io2("2");
    io1>>noskipws;
    io2>>noskipws;
    char ch1,ch2;
    while(io1>>ch1&&io2>>ch2){
        if(ch1==ch2)
            std::cout<<ch1;
        else break;
    }

}
