#pragma once
#include <iostream>
using namespace std;
const int  MAX_LENGTH = 10000;//当做无限距离，代表图的两点无通路情况
const int  VertexNum = 4;
struct Gragh
{
	char vertex[VertexNum] = { 'a','b','c' ,'d' };         //顶点表
	string way[VertexNum][VertexNum];  //路径表
	int diatance[VertexNum][VertexNum];  //距离表
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

