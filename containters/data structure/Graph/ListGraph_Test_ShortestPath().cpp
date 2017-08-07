#include<iostream>
#include"ListGraph.hpp"
using namespace std;

int main(){
	const int infinite=1e6; 
	char v[]={'a','b','c','d','e'};
	ListGraph<char> og(sizeof(v)/sizeof(*v),v);//构造无向图 
	og.add_edge(1,2,2);//a to b
	og.add_edge(1,3,3);//a to c
	og.add_edge(1,4,4);//a to d
	og.add_edge(1,5,5);//a to e
	og.add_edge(2,3,3);//b to c
	og.add_edge(2,4,4);//b to d
	og.add_edge(2,5,2);//b to e
	og.add_edge(3,4,4);//c to d
	og.add_edge(3,5,3);//c to e
	og.add_edge(4,5,3);//d to e
	int vertex = og.get_vertex();
	double dist[vertex+1];
	fill(dist,dist+vertex+1,infinite);
	
	og.ShortestPath(1,dist,infinite);//求a到其他各点的最短路径 
	for(int i=1;i<=vertex;++i){
		cout<<"a"<<" to "<<v[i-1]<<": "<<dist[i]<<endl;
	}
	
	return 0;
}

/*
题目内容：
 有5个城市(A,B,C,D,E),其中每个城市到其他城市的直达距离已知，两个城市之间
 只有一条公路。计算从城市A到其他任意城市的最短路径距离。
 
输入描述
4行数据， 第一行是A到(B,C,D,E)的直达距离，第二行是B到（C,D,E）
的直达距离，。。。，第4行是D到E的直达距离。

输出描述
A城市到(B,C,D,E)的最短距离。

输入样例
2 3 4 5  
3 4 2 
4 3   
3

输出样例
2 3 4 4

*/
