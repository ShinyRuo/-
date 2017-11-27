#include <iostream>
#include <iomanip>
#include "Floyd.h"
#include "Fibonacii.h"
#include "FakeCoins.h"
#include "Matrix.h"
#include "MyHeap.h"

using namespace std;

void main()
{
	string str[VertexNum][VertexNum] = {
		"a","","a->c","",
		"b->a","b","","",
		"","c->b","c","c->d",
		"d->a","","","d"
	};
	int dis[VertexNum][VertexNum] = {
		0,MAX_LENGTH,3,MAX_LENGTH,
		2,0,MAX_LENGTH,MAX_LENGTH,
		MAX_LENGTH,7,0,1,
		6,MAX_LENGTH,MAX_LENGTH,0
	};
	Floyd fl(str, dis);
	fl.printGraph();
	fl.floyd();
	fl.printGraph();


 //   digui(40);
	//diedai();

	//int i, *coin, n, temp;
	//cout << "请输入硬币的个数(n最大为机器整数值):";
	//cin >> n;
	//srand((unsigned)time(NULL));//srand()函数产生一个以当前时间开始的随机种子 
	//coin = new int[n + 1];
	//temp = 1 + rand() % n;//随机产生一个1~n之间的数
	//coin[0] = 0;
	//for (i = 1; i < n + 1; ++i)
	//{
	//	i != temp ? coin[i] = 1 : coin[i] = 0;
	//}
	//for (i = 1; i < n + 1; ++i)
	//	if (i != temp)
	//		cout << "第" << setw(3) << i << "枚硬币是真币" << endl;
	//	else
	//		cout << "第" << setw(3) << i << "枚硬币是假币" << endl;
	//cout << endl << endl << "假币二分算法结果：" << endl;
	//cout << "假币在第" << setw(3) << doubleDivide(coin, 1, n) << "个位置!" << endl;
	//cout << "总共称的次数为" << setw(3) << coin[0] << "次!" << endl;

	//cout << endl << endl << "假币三分算法结果：" << endl;
	//cout << "假币在第" << setw(3) << ThreeDivide(coin, 1, n) << "个位置!" << endl;
	//cout << "总共称的次数为" << setw(3) << coin[0] << "次!" << endl << endl << endl;
	//const int MatrixSize = 32;
	//int** a = initializationMatrix(MatrixSize);
	//int** b = initializationMatrix(MatrixSize); 
	//int** c = DivideAndConquer(a, b, MatrixSize);
	//int** d = BruteForce(a, b, MatrixSize);

	//printMatrix(c, MatrixSize);

	//printMatrix(d, MatrixSize);

	//deleteMatrix(a, MatrixSize);
	//deleteMatrix(b, MatrixSize);
	//deleteMatrix(c, MatrixSize);
	//deleteMatrix(d, MatrixSize);
	//MyHeap<int> heap;
	//const int n = 9;
	//int data[n] = { 3,8,2,9,4,6,11,5,7 };
	//heap.initHeap(data, n);
	//heap.makeHeap();
	//heap.printfHeap();
	//heap.sortHeap();
	//heap.printfHeap();
	//cout << "Vec:";
	//for (int i = 1; i <= n; i++)
	//{
	//	cout << heap.heapDataVec[i] << " ";
	//}
	//cout << endl;


}