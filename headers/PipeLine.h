//
// Created by dell on 2019/7/5.
//

#ifndef MYRISCV_SIM3_PIPELINE_H
#define MYRISCV_SIM3_PIPELINE_H

#include "Operations/R_Operations.h"
#include "Operations/I_Operations.h"
#include "Operations/SUBJ_Operations.h";
void renew_pc();
void renewRegisters();
int processing();
#endif //MYRISCV_SIM3_PIPELINE_H
