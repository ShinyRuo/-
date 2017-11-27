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
	//��Ԫ�ص�vector��
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
	int parent = numCounts / 2;//�ӵ�һ����Ҷ�ӽڵ㿪ʼ���ϵ�
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
	//���Ѷ���Ԫ�ط�����������β����Ȼ��β����ԭԪ����Ϊ����ֵ���������ɶ�
	Elemtype adjustValue = heapDataVec[numCounts];
	//�Ѷ�Ԫ��Ϊ��������Ԫ��
	heapDataVec[numCounts] = heapDataVec[StartIndex];
	--numCounts;
	adjustHeap(StartIndex, adjustValue);
}

template<class Elemtype, class Compare>
//�ǰ�λ��childTree��adjustValue��"�µ�"�����ʵ�λ�ã���ʵ�ǣ��Ѷ�ֱֵ�ӵ����ף��ٽ���ֵ���ݣ��µ��Ĺ��������˳��˶�ֵ�����ϵ������Ķѣ�
void MyHeap<Elemtype, Compare>::adjustHeap(int childTree, Elemtype adjustValue)
{
	//���ڵ�����
	int holeIndex = childTree;
	int secondChild = 2 * holeIndex + 1;//���ڵ�����ӽڵ�
	while (secondChild <= numCounts)
	{
		if (comp(heapDataVec[secondChild], heapDataVec[secondChild - 1]))  --secondChild;//��ʾ�����ӽڵ��нϴ���Ǹ�
																						 //�������·Ŷ�ֵ
		heapDataVec[holeIndex] = heapDataVec[secondChild];//��ϴ�ֵΪ��ֵ
		holeIndex = secondChild;//���ڵ���������
		secondChild = 2 * secondChild + 1;
	}
	//������ڵ�ֻ�����ӽڵ�
	if (secondChild == numCounts + 1)
	{
		//�����ӽڵ�Ϊ��ֵ
		heapDataVec[holeIndex] = heapDataVec[secondChild - 1];
		holeIndex = secondChild - 1;
	}
	//������ֵ���趴�ڵ�
	heapDataVec[holeIndex] = adjustValue;
	//��ʱ������δ����ѵ����ԡ���Ҫ�ٽ���һ�����ݲ���
	percolateUp(holeIndex, adjustValue);
}

template<class Elemtype, class Compare>
void MyHeap<Elemtype, Compare>::percolateUp(int holeIndex, Elemtype adjustValue)
{
	//���½ڵ����丸�ڵ�Ƚϣ������ֵ���丸�ڵ�󣬾͸��ӽ���λ��
	//ֱ������Ҫ�Ի���ֱ�����ڵ�Ϊֹ
	int parentIndex = holeIndex / 2;
	while (holeIndex>StartIndex && comp(heapDataVec[parentIndex], adjustValue))
	{
		heapDataVec[holeIndex] = heapDataVec[parentIndex];
		holeIndex = parentIndex;
		parentIndex /= 2;
	}
	heapDataVec[holeIndex] = adjustValue;//����ֵ������ȷ��λ��
}
