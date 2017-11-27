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
	//cout << "������Ӳ�ҵĸ���(n���Ϊ��������ֵ):";
	//cin >> n;
	//srand((unsigned)time(NULL));//srand()��������һ���Ե�ǰʱ�俪ʼ��������� 
	//coin = new int[n + 1];
	//temp = 1 + rand() % n;//�������һ��1~n֮�����
	//coin[0] = 0;
	//for (i = 1; i < n + 1; ++i)
	//{
	//	i != temp ? coin[i] = 1 : coin[i] = 0;
	//}
	//for (i = 1; i < n + 1; ++i)
	//	if (i != temp)
	//		cout << "��" << setw(3) << i << "öӲ�������" << endl;
	//	else
	//		cout << "��" << setw(3) << i << "öӲ���Ǽٱ�" << endl;
	//cout << endl << endl << "�ٱҶ����㷨�����" << endl;
	//cout << "�ٱ��ڵ�" << setw(3) << doubleDivide(coin, 1, n) << "��λ��!" << endl;
	//cout << "�ܹ��ƵĴ���Ϊ" << setw(3) << coin[0] << "��!" << endl;

	//cout << endl << endl << "�ٱ������㷨�����" << endl;
	//cout << "�ٱ��ڵ�" << setw(3) << ThreeDivide(coin, 1, n) << "��λ��!" << endl;
	//cout << "�ܹ��ƵĴ���Ϊ" << setw(3) << coin[0] << "��!" << endl << endl << endl;
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