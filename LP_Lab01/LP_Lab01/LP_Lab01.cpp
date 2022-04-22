﻿#include "Auxil.h"
#include <iostream>
#include <ctime>
#include <locale>

#define CYCLE 1000000

using namespace std;

int main()
{
    double av1 = 0, av2 = 0;
    clock_t t1 = 0, t2 = 0;
    setlocale(LC_ALL, "rus");
    auxil::start();
    t1 = clock();
    for (int i = 0; i < CYCLE; i++)
    {
        av1 += (double)auxil::iget(-100, 100);
        av2 += auxil::dget(-100, 100);
    }
    t2 = clock();
    cout << endl << "количество циклов:         " << CYCLE;
    cout << endl << "среднее значение (int):    " << av1 / CYCLE;
    cout << endl << "среднее значение (double): " << av2 / CYCLE;
    cout << endl << "продолжительность (у.е):   " << (t2 - t1);
    cout << endl << "                  (сек):   " << (double)(t2 - t1) / (double)CLOCKS_PER_SEC;
    cout << endl;
    return 0;
}
