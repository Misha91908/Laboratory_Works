#include <iostream>
#include "ex1_classes.h"

int main() {
    calculator calc;
    loop_manager loop(calc);

    loop.start();

    return 0;
}