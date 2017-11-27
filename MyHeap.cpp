#include "MyHeap.h"

//template<class Elemtype, class Compare>
//MyHeap<Elemtype, Compare>::MyHeap() :numCounts(0)
//{
//	heapDataVec.push_back(MAX_VAlUE);
//}

template<class Elemtype, class Compare>
vector<Elemtype> MyHeap<Elemtype, Compare>::getVec()
{
	return heapDataVec;
}

template<class Elemtype, class Compare>
void MyHeap<Elemtype,Compare>::initHeap(Elemtype * data, const int n)
{
	//拷元素到vector中
	for (int i = 0; i < n; i++)
	{
		heapDataVec.push_back(data[i]);
		++numCounts;
	}
}

template<class Elemtype, class Compare>
void MyHeap<Elemtype, Compare>::printfHeap()
{
	cout << "Heap:";
	for (int i = 1; i <= numCounts; ++i)
		cout << heapDataVec[i] << " ";
	cout << endl;
}

template<class Elemtype, class Compare>
void MyHeap<Elemtype, Compare>::makeHeap()
{
	if (numCounts < 2) return;
	int parent = numCounts / 2;//从第一个非叶子节点开始往上调
	while (true)
	{
		adjustHeap(parent, heapDataVec[parent]);
		if (StartIndex == parent) return;
		--parent;
	}
}

template<class Elemtype, class Compare>
void MyHeap<Elemtype, Compare>::sortHeap()
{
	while (numCounts>0)
	{
		popHeap();
	}
}

template<class Elemtype, class Compare>
void MyHeap<Elemtype, Compare>::pushHeap(Elemtype elem)
{
	heapDataVec.push_back(elem);
	++numCounts;
	percolateUp(numCounts, heapDataVec[numCounts]);
}

template<class Elemtype, class Compare>
void MyHeap<Elemtype, Compare>::popHeap()
{
	//将堆顶的元素放在容器的最尾部，然后将尾部的原元素作为调整值，重新生成堆
	Elemtype adjustValue = heapDataVec[numCounts];
	//堆顶元素为容器的首元素
	heapDataVec[numCounts] = heapDataVec[StartIndex];
	--numCounts;
	adjustHeap(StartIndex, adjustValue);
}

template<class Elemtype, class Compare>
//是把位于childTree的adjustValue向"下调"到合适的位置（其实是，把洞值直接调到底，再将洞值上溯，下调的过程生成了除了洞值不符合的条件的堆）
void MyHeap<Elemtype, Compare>::adjustHeap(int childTree, Elemtype adjustValue)
{
	//洞节点索引
	int holeIndex = childTree;
	int secondChild = 2 * holeIndex + 1;//洞节点的右子节点
	while (secondChild <= numCounts)
	{
		if (comp(heapDataVec[secondChild], heapDataVec[secondChild - 1]))  --secondChild;//表示两个子节点中较大的那个
																						 //无条件下放洞值
		heapDataVec[holeIndex] = heapDataVec[secondChild];//令较大值为洞值
		holeIndex = secondChild;//洞节点索引下移
		secondChild = 2 * secondChild + 1;
	}
	//如果洞节点只有左子节点
	if (secondChild == numCounts + 1)
	{
		//令左子节点为洞值
		heapDataVec[holeIndex] = heapDataVec[secondChild - 1];
		holeIndex = secondChild - 1;
	}
	//将调整值赋予洞节点
	heapDataVec[holeIndex] = adjustValue;
	//此时可能尚未满足堆的特性。需要再进行一次上溯操作
	percolateUp(holeIndex, adjustValue);
}

template<class Elemtype, class Compare>
void MyHeap<Elemtype, Compare>::percolateUp(int holeIndex, Elemtype adjustValue)
{
	//将新节点与其父节点比较，如果键值比其父节点大，就父子交换位置
	//直到不需要对换或直到根节点为止
	int parentIndex = holeIndex / 2;
	while (holeIndex>StartIndex && comp(heapDataVec[parentIndex], adjustValue))
	{
		heapDataVec[holeIndex] = heapDataVec[parentIndex];
		holeIndex = parentIndex;
		parentIndex /= 2;
	}
	heapDataVec[holeIndex] = adjustValue;//将新值放在正确的位置
}
