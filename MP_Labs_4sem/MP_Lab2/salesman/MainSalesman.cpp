#include <iostream>
#include <iomanip>
#include <ctime>
#include "Salesman.h"
#include "Auxil.h"
#define N 5
int wmain()
{
    setlocale(LC_ALL, "rus");
    int d[N][N];
    clock_t t1 = 0, t2 = 0;
    auxil::start();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            d[i][j] = auxil::iget(10,300);
        }
    }
    d[1][0] = INF; d[2][2] = INF; d[1][3] = INF;
  /* 
  int d[N][N] =  { 
      {INF,2,22,INF,1},
      {1,INF,16,67,83},
      {3,3,INF,86,50},
      {18,57,4,INF,3},
      {92,67,52,14,INF}
    };*/
    


    int r[N];                     // результат 
    t1 = clock();
    int s = sal::salesman(
        N,          // [in]  количество городов 
        (int*)d,          // [in]  массив [n*n] расстояний 
        r           // [out] массив [n] маршрут 0 x x x x  

    );
    t2 = clock();
    std::cout << std::endl << "-- Задача коммивояжера -- ";
    std::cout << std::endl << "-- количество  городов: " << N;
    std::cout << std::endl << "-- матрица расстояний : ";
    for (int i = 0; i < N; i++) {
        std::cout << std::endl;
        for (int j = 0; j < N; j++)
            if (d[i][j] != INF) std::cout << std::setw(3) << d[i][j] << " ";
            else std::cout << std::setw(3) << "INF" << " ";
    }
    std::cout << std::endl << "-- оптимальный маршрут: ";
    for (int i = 0; i < N; i++) std::cout << r[i]+1 << "-->"; std::cout << 1;
    std::cout << std::endl << "-- длина маршрута     : " << s;
    std::cout << std::endl;
    std::cout << std::endl << "-- время работы   : " << t2 - t1 << std::endl;
    system("pause");
    return 0;


}


// ============================  ЗАВИСИМОСТЬ ВРЕМЕНИ ВЫЧИСЛЕНИЯ  ============================

//
//#include <iostream>
//#include <iomanip>
//
//#include <time.h>
//#define NN (sizeof(v)/sizeof(int))
//#define MM 6
//#define SPACE(n) std::setw(n)<<" "
//int wmain()
//{
//    setlocale(LC_ALL, "rus");
//
//   /* int V = 1000,
//        v[] = { 250, 560, 670, 400, 200, 270, 370, 330, 330, 440, 530, 120,
//               200, 270, 370, 330, 330, 440, 700, 120, 550, 540, 420, 170,
//               600, 700, 120, 550, 540, 420, 430, 140, 300, 370, 310, 120 };
//    int c[NN] = { 15,26,  27,  43,  16,  26,  42,  22,  34,  12,  33,  30,
//               42,22,  34,  43,  16,  26,  14,  12,  25,  41,  17,  28,
//               12,45,  60,  41,  33,  11,  14,  12,  25,  41,  30,  40 };
//    short r[MM];
//    int maxcc = 0;
//    clock_t t1, t2;
//    std::cout << std::endl << "-- Задача об оптимальной загрузке судна -- ";
//    std::cout << std::endl << "-  ограничение по весу    : " << V;
//    std::cout << std::endl << "-  количество мест        : " << MM;
//    std::cout << std::endl << "-- количество ------ продолжительность -- ";
//    std::cout << std::endl << "   контейнеров        вычисления  ";
//    for (int i = 24; i <= NN; i++)
//    {
//        t1 = clock();
//        int maxcc = boat(V, MM, i, v, c, r);
//        t2 = clock();
//        std::cout << std::endl << SPACE(7) << std::setw(2) << i
//            << SPACE(15) << std::setw(5) << (t2 - t1);
//    }
//    std::cout << std::endl << std::endl;*/
//    system("pause");
//    return 0;
//}