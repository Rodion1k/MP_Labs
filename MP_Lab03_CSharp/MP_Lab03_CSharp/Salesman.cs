using System;
using System.Collections.Generic;
using Lp_Lab01;

namespace MP_Lab03_CSharp
{
    public class Salesman // есть баги, но почти
    {
        private CMatrix _matrix;
        int INF = 0x7fffffff;
        private int[] _sumOfminElements;

        //private 
        private int _lowerBorder;
        private int _a;
        private int _b;
        private int _countOfCycles;
        private int countOfNull;
        private List<Point> _points;
        private List<Point> path;
    

        private class Point
        {
            public int I { get; set; }
            public int J { get; set; }
            public int Sum { get; set; }

            public Point(int i, int j, int sum)
            {
                I = i;
                J = j;
                Sum = sum;
            }
            public Point(int i, int j)
            {
                I = i;
                J = j;
                Sum = 0;
            }

            public override string ToString()
            {
                return $"({I},{J})";
            }
        }

        public Salesman(CMatrix matrix)
        {
            _matrix = matrix;
            _countOfCycles = _matrix.Rows - 2;
            _sumOfminElements = new int[_matrix.Rows * _matrix.Cols];
            _points = new List<Point>();
            path = new List<Point>();
        }

        public void FindingPath() //TODO мб лист точек 
        {
            for (int i = 0; i < _countOfCycles; i++)
            {
                СustomizeMatrix();
                FindNull();
                DeleteTown();
                _points = new List<Point>();
            }
            Console.WriteLine($"длина = {GetPathLength()}");
            Console.WriteLine("путь:");
            foreach (var p in path)
            {
                Console.Write(p+"->");
            }
        }

        public int GetPathLength() => _lowerBorder;

        private void СustomizeMatrix()
        {
            CustomizeRows();
            CustomizeCols();
            _lowerBorder += _a + _b;
        }

        private void FindNull()
        {
            for (int i = 0; i < _matrix.Rows; i++)
            {
                for (int j = 0; j < _matrix.Cols; j++)
                {
                    if (_matrix[i, j] == 0)
                    {
                        _points.Add(new Point(i, j, SumMin(i, j)));
                    }
                }
            }
        }


        private void DeleteTown()
        {
            CMatrix newMatrix = new CMatrix(_matrix.Rows - 1, _matrix.Cols - 1);
            int max = _points[0].Sum;
            int I = 0, J = 0;
            foreach (var point in _points)
            {
                if (max < point.Sum)
                {
                    max = point.Sum;
                    I = point.I;
                    J = point.J;
                }
            }
            _matrix[J, I] = INF;
            int row = 0, col = 0;
            for (int i = 0; i < _matrix.Rows; i++)
            {
                col = 0;
                if (i != I)
                {
                    for (int j = 0; j < _matrix.Cols; j++)
                    {
                        if (j == J)
                            j++;
                        newMatrix[row, col] = _matrix[i, j];
                        col++;
                    }
                    row++;
                }
            }
            path.Add(new Point(I,J));
            _matrix.RedimMatrix(newMatrix.Rows, newMatrix.Cols);
            _matrix = newMatrix;
            
            
        }


        private int SumMin(int i, int j)
        {
            CMatrix matrix = _matrix.GetRow(i);
            int min = INF, sum;
            for (int k = 0; k < matrix.Cols; k++)
            {
                if (k != j && matrix[k] < min)
                    min = matrix[k];
            }

            sum = min;
            matrix = _matrix.GetCol(j);
            min = INF;
            for (int k = 0; k < matrix.Rows; k++)
            {
                if (k != i && matrix[k, 0] < min)
                    min = matrix[k, 0];
            }

            sum += min;
            return sum;
        }

        private void CustomizeRows()
        {
            _a = 0;
            int min;
            for (int i = 0; i < _matrix.Rows; i++)
            {
                CMatrix matrix = _matrix.GetRow(i);
                min = matrix.MinElement();
                _a += min;
                for (int j = 0; j < _matrix.Cols; j++)
                {
                    _matrix[i, j] = _matrix[i, j] - min;
                }
            }
        }

        private void CustomizeCols()
        {
            int min;
            _b = 0;
            for (int i = 0; i < _matrix.Cols; i++)
            {
                CMatrix matrix = _matrix.GetCol(i);
                min = matrix.MinElement();
                _b += min;
                for (int j = 0; j < _matrix.Rows; j++)
                {
                    _matrix[j, i] = _matrix[j, i] - min;
                }
            }
        }
    }
    
}