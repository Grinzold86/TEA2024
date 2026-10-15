#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

void changeValueByParameter(int value)
{
    value = 99;
    fmt::println("Neuer Wert: {}", value);
}

void changeValueByPointer(int* ptr)
{
    *ptr = 77;
    fmt::println("Neuer Wert: {}", *ptr);
}

int main(int argc, char **argv) {

    int x = 10;
    int* p = &x;
    double* d = new double(3.1415);
    int y = 10;


    fmt::print("Anzahl Argumente, {}\n", argc);

    for (int i=0;i<argc;i++)
    {
        fmt::print("Argumente {}: {} [Adresse: {}]\n", i, argv[i], (void*)argv[i]);
    }

    fmt::print("Wert von X {}\n", x);
    fmt::print("[Adresse: {}]\n", fmt::ptr(&x));

    fmt::print("Wert von X {}\n", *p);
    fmt::print("[Adresse: {}]\n", (void*)p);

    *p = 42;

    fmt::print("Wert von X {}\n", x);
    fmt::print("Wert von X {}\n", *p);

    fmt::println("Wert von Pi: {}", *d);
    fmt::println("Adresse von Pi {}", (void*)d);
    delete(d);

    fmt::print("Wert von Y {}\n", y);
    changeValueByParameter(y);
    fmt::print("Wert von Y {}\n", y);

    fmt::print("Wert von Y {}\n", y);
    changeValueByPointer(&y);
    fmt::print("Wert von Y {}\n", y);

    return 0; /* exit gracefully*/
}
