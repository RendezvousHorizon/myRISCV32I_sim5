cmake_minimum_required(VERSION 3.14)
project(myRISCV_sim3)

set(CMAKE_CXX_STANDARD 14)

add_executable(myRISCV_sim3 main.cpp headers/RISCV.h sources/RISCV.cpp sources/Operations/Operations.cpp headers/Operations/Operations.h sources/Operations/R_Operations.cpp headers/Operations/R_Operations.h sources/Operations/I_Operations.cpp headers/Operations/I_Operations.h sources/Operations/SUBJ_Operations.cpp headers/Operations/SUBJ_Operations.h sources/PipeLine.cpp headers/PipeLine.h sources/Scanner.cpp sources/get_Operations.cpp headers/get_Operations.h headers/Scanner.h sources/jump_table.cpp headers/jump_table.h)