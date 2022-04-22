// --- Main
#include <iostream>
#include "Combi.h"
#include <iomanip> 
int wmain()     // алгоритм Джонсона – Троттера
{
    setlocale(LC_ALL, "rus");
    char  AA[] = { 'A', 'B', 'C', 'D', 'E' };
    std::cout << std::endl << " --- Генератор перестановок ---";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < sizeof(AA); i++)

        std::cout << AA[i] << ((i < sizeof(AA)) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация перестановок ";
    combi::permutation p(sizeof(AA));
    __int64  n = p.getfirst();
    while (n >= 0)
    {
        std::cout << std::endl << std::setw(4) << p.np << ": { ";

        for (int i = 0; i < p.n; i++)

            std::cout << AA[p.ntx(i)] << ((i < p.n - 1) ? ", " : " ");

        std::cout << "}";

        n = p.getnext();
    };
    std::cout << std::endl << "всего: " << p.count() << std::endl;
    system("pause");
    return 0;
}
