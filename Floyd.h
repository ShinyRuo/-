#pragma once
#include <iostream>
using namespace std;
const int  MAX_LENGTH = 10000;//�������޾��룬����ͼ��������ͨ·���
const int  VertexNum = 4;
struct Gragh
{
	char vertex[VertexNum] = { 'a','b','c' ,'d' };         //�����
	string way[VertexNum][VertexNum];  //·����
	int diatance[VertexNum][VertexNum];  //�����
};
class Floyd
{
	Gragh g;
public:
	Floyd();
	Floyd(string(*str)[VertexNum],int(*dis)[VertexNum]);
     void printGraph();
	 void floyd();

	~Floyd();
};

