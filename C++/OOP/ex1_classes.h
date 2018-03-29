#ifndef OOP_EX1_CLASSES_H
#define OOP_EX1_CLASSES_H

#include <iostream>
#include <string>

using namespace std;

class calculator{
    int calculate(int status);
    float result = 0.0;
};

class loop_manager{
    public:
        loop_manager(calculator c);

        void start();

    private:
        calculator calc;
        int run = 0, control = 0;
        string check;
        void stop(){run = 0;}

};

#endif
