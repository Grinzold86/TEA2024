#include "module.h"

#include <fmt/format.h>
#include "bonus_config.h"

/* .bss Segment */
int foo;
int foo2 = 0;

/* .data Segment */
int data = 45;
int data2 = 43;

/* .rodata Segment */

const int rodata = 45;
const int rodata2 = 0;

const int big_data_blob[] = {42,0xff};

static int moduleCounter;
static int moduleValue = 123;

static int shadow = 11;

void doSomething(int value)
{
    value = value + 1;
    fmt::print("doSomething, value {}\n", value);
}

void doSomethingPtr(int* ptr)
{
    *ptr = *ptr + 1;
    fmt::print("doSomethingPtr, value {}\n", *ptr);
}

int* doReturnAPtr()
{
    int value = 4711;
    fmt::print("doReturnAPtr, value {}\n", value);
    /* 
     * This causes a warning and shall be avoided by all means
     * warning: address of stack memory associated with local variable 'value' returned [-Wreturn-stack-address]
     */
    return &value;
}

void doSomethingStatic()
{
    static int value = 56;
    int value2 = 56;
    value = value + 1;
    value++;
    fmt::print("doSomethingStatic, value {}\n", value);
    fmt::print("Static address [{}] \n", fmt::ptr(&value));

    fmt::print("doSomethingStatic, value2 {}\n", value2);
    fmt::print("Static address [{}] \n", fmt::ptr(&value2));
}

void printConstantAdr()
{
    fmt::print("constant address [{}] \n", fmt::ptr(&rodata));
    fmt::print("constant address [{}] \n", fmt::ptr(&rodata2));
}

void modulCounter()
{
    fmt::print("static address, mit 0 init. [{}] \n", fmt::ptr(&moduleCounter));
    fmt::print("static address [{}] \n", fmt::ptr(&moduleValue));
    /*
    if (moduleValue < 150)
    {
        moduleValue++;
        moduleCounter = moduleCounter + 2;
    }
    fmt::print("modulCounter = {}\n", moduleCounter);
    */
}

void printValues()
{
    fmt::print("shadow modul {}\n", shadow);
    fmt::print("shadow modul adress [{}] \n", fmt::ptr(&shadow));
}

/*
void printValues()
{
    fmt::print("doSomethingStatic, value {}\n", value);
    fmt::print("doSomethingStatic, value {}\n", moduleValue);
}
*/

