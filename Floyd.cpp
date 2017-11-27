#include "Floyd.h"
#include <string>


Floyd::Floyd()
{
}

Floyd::Floyd(string(*str)[VertexNum], int(*dis)[VertexNum])
{
	int j;
	for (int i = 0; i < VertexNum; ++i)
		for (j = 0; j < VertexNum; ++j)
		{
			g.way[i][j] = str[i][j];
			g.diatance[i][j] = dis[i][j];
		}
}

void Floyd::printGraph()
{
	int j;
	for (int i = 0; i < VertexNum; ++i)
	{
		cout << endl;
		for (j = 0; j < VertexNum; ++j)
		{
			cout << g.way[i][j] << g.diatance[i][j] << " ";
		}
	}
	cout << endl;
}

void Floyd::floyd()
{
	int i,j,k;
	for (k = 0; k<VertexNum; k++)
		for (i = 0; i<VertexNum; i++)
			for (j = 0; j < VertexNum; j++)
			{
				if (g.diatance[i][j] > (g.diatance[i][k] + g.diatance[k][j]))
				{
					g.diatance[i][j] = g.diatance[i][k] + g.diatance[k][j];
					g.way[i][j] = g.way[i][k] + g.way[k][j];
				}
			}
}


Floyd::~Floyd()
{
}
