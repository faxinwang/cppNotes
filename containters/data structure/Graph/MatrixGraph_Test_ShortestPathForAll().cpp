#include<iostream> 
#include<vector>
#include"MatrixGraph.hpp"
using namespace std;


int main(){
	int v[]={1,2,3};
	const int Infinity=1e4;
	MatrixGraph<int> g(sizeof(v)/sizeof(*v),v,Infinity,true);
	
	g.add_edge(1,2,4);
	g.add_edge(1,3,11);
	g.add_edge(2,1,6);
	g.add_edge(2,3,2);
	g.add_edge(3,1,3);
	
	int NumNode = g.get_vertex();
	printf("NumNode:%d\n",NumNode);
	g.print_matrix();
	

	vector<vector<int> > a;
	g.ShortestPathForAll(a);
	
	for(int i=0;i<NumNode;++i){
		for(int j=0;j<NumNode;++j) 
			printf("%3d",a[i][j]);
		puts("");
	}
	
	return 0;
}

/*
有一个邻接矩阵:
0   4    11
6   0    2
3   INF  0

运算结果应该是:
0   4   6
5   0   2
3   7   0
*/
