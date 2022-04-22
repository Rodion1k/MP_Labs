// Main      
#include <iostream>
#include <ctime>
#include "Combi.h"

int wmain()     // с помощью инкременирования битовой маски
{
    setlocale(LC_ALL, "rus");
    clock_t t1 = 0, t2 = 0;
    char  AA[] = { 'A', 'B', 'C', 'D' };
    std::cout << std::endl << " - Генератор множества всех подмножеств -";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < sizeof(AA); i++)
        std::cout << AA[i] << ((i < sizeof(AA)) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация всех подмножеств  ";    
    t1 = clock();
    combi::subset s1(sizeof(AA));           // создание генератора 
    int  n = s1.getfirst();                 // первое (пустое) подмножество  
    while (n >= 0)                          // пока есть подмножества 
    {
        std::cout << std::endl << "{ ";
        for (int i = 0; i < n; i++)
            std::cout << AA[s1.ntx(i)] << ((i < n - 1) ? ", " : " ");
        std::cout << "}";
        n = s1.getnext();                   // cледующее подмножество 
    };
    t2 = clock();
    std::cout << std::endl << "всего: " << s1.count() << std::endl;
    std::cout << std::endl << "время в мс: " <<(double) t2-t1 << std::endl;
    system("pause");
    return 0;
}
