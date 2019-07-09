//
// Created by dell on 2019/7/5.
//
#ifndef MYRISCV_SIM3_GET_OPERATIONS_H
#define MYRISCV_SIM3_GET_OPERATIONS_H
#include "../headers/Operations/Operations.h"
#include "../headers/Operations/R_Operations.h"
#include "../headers/Operations/I_Operations.h"
#include "../headers/Operations/SUBJ_Operations.h"

void R_get(Operations* &ptr);
void I_get(Operations* &ptr);
void S_get(Operations* &ptr);
void B_get(Operations* &ptr);
void U_get(Operations* &ptr);
void J_get(Operations* &ptr);

void get_Operations(Operations *&ptr);

#endif //MYRISCV_SIM3_GET_OPERATIONS_H
