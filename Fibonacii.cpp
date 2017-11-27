#include "Fibonacii.h"
#include <iostream>
#include <time.h>
using namespace std;

static long long countdiedai = 0;
static long long countdigui = 0;

void diedai()
{
	double start, end, cost;
	start = clock();
	long long f1 = 0, f2 = 0, f = 1;
	while (f>0)
	{
		++countdiedai;
		f1 = f2;
		f2 = f;
		f = f1 + f2;
	}
	end = clock();
	cost = end - start;
	cout << "ʹ�õ���������long long����������fibonacii��Ϊ��" << f2 << endl;
	cout << "��ʱ��" << cost << "ms" << endl << "����������Ϊ��" << countdiedai << "��" << endl;
}

void digui(int n)
{
	double start, end, cost;
	start = clock();
	long long s = diguiCount(n);
	end = clock();
	cost = end - start;
	cout << "ʹ�õݹ鷨�����" << n << "��fibonacii��Ϊ" << s<<endl;
	cout << "��ʱ" << cost << "ms" << endl<< "����������Ϊ��" << countdigui << "��" << endl;

}

long long diguiCount(int n)
{
	if (n == 1 || n == 2) return 1;
	else if (n <= 92) {
		++countdigui;
		return diguiCount(n - 1) + diguiCount(n - 2);
	}
	else return 0;
}






