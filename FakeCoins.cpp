#include "FakeCoins.h"

#include <iostream>
using namespace std;

int doubleDivide(int coin[], int low, int high)
{
	int i, mid, sum1, sum2, sign;
	coin[0] = 0;//计数位
	while (true)
	{
		mid = (low + high) / 2;
		sign = (low + high) % 2;//标记奇偶数
		sum1 = sum2 = 0;
		if (sign == 0)//奇数情况
		{
			for (i = low; i < mid; i++) sum1 += coin[i];
			for (i = mid + 1; i <= high; i++) sum2 += coin[i];
			if (sum1 == 0 && sum2 == 0);
			else coin[0] += 1;
			if (sum1 == sum2) return mid;
			else if (sum1 < sum2) high = mid - 1;
			else low = mid + 1;
		}
		else //处理偶数情况
		{
			for (i = low; i <= mid; i++) sum1 += coin[i];
			for (i = mid + 1; i <= high; i++) sum2 += coin[i];
			if (sum1 == 0 && sum2 == 0);
			else coin[0] += 1;
			if (sum1 < sum2) high = mid;
			else low = mid + 1;
		}
	}
	return -1;
}

int ThreeDivide(int coin[], int low, int high)
{
	int i, mid1, mid2, sum1, sum2, sum3, flag, my_space;
	coin[0] = 0;
	if (high < 3) {
		cout << "you must input a number bigger than 3!" << endl;
		return -1;
	}
	while (low <= high)
	{
		sum1 = sum2 = sum3 = 0;
		my_space = (high - low + 1) / 3;
		mid1 = low + my_space - 1;
		mid2 = mid1 + my_space;
		flag = (high - low + 1) % 3;//记录余数

		for (i = low; i <= mid1; i++) sum1 += coin[i];
		for (i = mid1 + 1; i <= mid2; i++) sum2 += coin[i];
		for (i = mid2 + 1; i <= mid2 + my_space; i++) sum3 += coin[i];

		if (sum1 == 0 && sum2 == 0 && sum3 == 0);
		else coin[0] += 1;
		if (flag == 0)//处理余数为0的情况
		{
			if (sum1 == sum2)
				low = mid2 + 1;
			if (sum1 == sum3)
			{
				low = mid1 + 1; high = mid2;
			}
			if (sum2 == sum3)
				high = mid1;
		}
		else if (flag == 1)////处理余数为1的情况
		{
			if (sum1 == sum2)
			{
				if (sum1 == sum3)
				{
					return high;
				}
				else
				{
					low = mid2 + 1; high = high - 1;
				}
			}
			else
			{
				if (sum1 == sum3)
				{
					low = mid1 + 1; high = mid2;
				}
				if (sum2 == sum3)
				{
					high = mid1;
				}

			}

		}
		else////处理余数为2的情况
		{


			if (sum1 == sum2)
			{
				if (sum1 == sum3)
				{
					coin[0] += 1;
					if (coin[high - 1] == 0)
						return high - 1;
					else
						return high;

				}
				else
				{
					low = mid2 + 1; high = high - 2;
				}
			}
			else
			{
				if (sum1 == sum3)
				{
					low = mid1 + 1; high = mid2;
				}
				if (sum2 == sum3)
				{
					high = mid1;
				}
			}
		}
	}
	return -1;
}
