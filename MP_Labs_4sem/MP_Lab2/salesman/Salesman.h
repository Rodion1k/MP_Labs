#pragma once 
#define INF   0x7fffffff   // ������������� 
namespace sal
{
	int salesman(     // ������� ���������� ����� ������������ ��������
		int n,         // [in]  ���������� ������� 
		const int* d,  // [in]  ������ [n*n] ���������� 
		int* r         // [out] ������ [n] ������� 0 x x x x 
	);
}




