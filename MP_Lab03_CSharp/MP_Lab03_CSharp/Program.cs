using System;
using Lp_Lab01;

namespace MP_Lab03_CSharp
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            int INF = 0x7fffffff;
            // int[,] arr = // мой
            // {
            //     { INF, 2, 22, INF, 1 },
            //     { 1, INF, 16, 67, 83 },
            //     { 3, 3, INF, 86, 50 },
            //     { 18, 57, 4, INF, 3 },
            //     { 92, 67, 52, 14, INF }
            // };
            int[,] arr = // марка
            {
                { INF, 14, 28, INF, 7 },
                { 7, INF, 22, 61, 77 },
                { 9, 21, INF, 86, 56 },
                { 24, 51, 28, INF, 21 },
                { 86, 73, 52, 20, INF }
            };
            CMatrix matrix = new CMatrix(arr,5,5);
         
            Salesman salesman = new Salesman(matrix);
            salesman.FindingPath();
        }
    }
}