// Main      
#include <iostream>
#include <ctime>
#include "Combi.h"
int wmain()     // тоже битовая маска, но берем только подмножества с N двоичными единицами
{
    setlocale(LC_ALL, "rus");
    clock_t t1 = 0, t2 = 0;
    char  AA[] = { 'A', 'B', 'C', 'D', 'E'};
    std::cout << std::endl << " --- Генератор сочетаний ---";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < sizeof(AA); i++)

        std::cout << AA[i] << ((i < sizeof(AA)) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация сочетаний ";
    t1 = clock();
    combi::xcombination xc(sizeof(AA), 3);
    std::cout << "из " << xc.n << " по " << xc.m;
    int  n = xc.getfirst();
    while (n >= 0)
    {
        std::cout << std::endl << xc.nc << ": { ";
        for (int i = 0; i < n; i++)
            std::cout << AA[xc.ntx(i)] << ((i < n - 1) ? ", " : " ");

        std::cout << "}";
        n = xc.getnext();
    };
    t2 = clock();
    std::cout << std::endl << "всего: " << xc.count() << std::endl;
    std::cout << std::endl << "время в мс: " << (double)t2 - t1 << std::endl;
    system("pause");
    return 0;
}
