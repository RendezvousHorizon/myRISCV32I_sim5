#include <iostream>
#include <fstream>
#include "headers/RISCV.h"
#include "headers/PipeLine.h"
#include "headers/Scanner.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    get_mem2(mem);
    cout<<processing();
    return 0;
}