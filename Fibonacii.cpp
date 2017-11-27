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
	cout << "使用迭代法计算long long类型下最大的fibonacii数为：" << f2 << endl;
	cout << "用时：" << cost << "ms" << endl << "基本操作数为：" << countdiedai << "次" << endl;
}

void digui(int n)
{
	double start, end, cost;
	start = clock();
	long long s = diguiCount(n);
	end = clock();
	cost = end - start;
	cout << "使用递归法计算第" << n << "个fibonacii数为" << s<<endl;
	cout << "用时" << cost << "ms" << endl<< "基本操作数为：" << countdigui << "次" << endl;

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






