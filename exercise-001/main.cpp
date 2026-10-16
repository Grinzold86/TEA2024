#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

    int globalVar1 = 1;
    int globalVar2 = 0;
    int static globalVar3 = 3;
    int const globalVar4 = 1;
    int globalVar5;

    void foo();

int main(int argc, char **argv) {

    int localVar1 = 1;
    int localVar2;
    int localVar3;
    int static localVar4 = 3;
    int const localVar5 = 1;

    int* heapVar = new int(1);

    fmt::println("Globale Variable (normal): {}, [Adresse: {}]", globalVar1, fmt::ptr(&globalVar1));
    fmt::println("Globale Variable (kein wert): {}, [Adresse: {}]", globalVar5, fmt::ptr(&globalVar5));
    fmt::println("Globale Variable (nullwert): {}, [Adresse: {}]", globalVar2, fmt::ptr(&globalVar2));
    fmt::println("Globale Variable (static): {}, [Adresse: {}]", globalVar3, fmt::ptr(&globalVar3));
    fmt::println("Globale Variable (const): {}, [Adresse: {}]", globalVar4, fmt::ptr(&globalVar4));

    fmt::println("lokale Variable (normal): {}, [Adresse: {}]", localVar1, fmt::ptr(&localVar1));
    fmt::println("lokale Variable (kein wert): {}, [Adresse: {}]", localVar2, fmt::ptr(&localVar2));
    fmt::println("lokale Variable (nullwert): {}, [Adresse: {}]", localVar3, fmt::ptr(&localVar3));
    fmt::println("lokale Variable (static): {}, [Adresse: {}]", localVar4, fmt::ptr(&localVar4));
    fmt::println("lokale Variable (const): {}, [Adresse: {}]", localVar5, fmt::ptr(&localVar5));

    fmt::println("heap Variable: {}, [Adresse: {}]", *heapVar, fmt::ptr(heapVar));

    delete(heapVar);

    fmt::println("Adresse von foo: {}", fmt::ptr(&foo));

    return 0; /* exit gracefully*/
}

void foo() 
{ 
    fmt::print("Hello from foo!\\n"); 
}