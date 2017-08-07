#include<iostream> 
#include"MatrixGraph.hpp"
using namespace std;

int main(){
	int v[] ={1,2,3,4,5,6,7,8,9};
	MatrixGraph<int> og(sizeof(v)/sizeof(*v),v,-1,true);//创建有向图 
	//添加各边
	og.add_edge(2,3);
	og.add_edge(2,4);
	og.add_edge(2,5);
	og.add_edge(1,3);
	og.add_edge(1,8);
	og.add_edge(5,6);
	og.add_edge(4,6);
	og.add_edge(3,4);
	og.add_edge(4,7);
	og.add_edge(8,9);
	og.add_edge(9,7);
	og.TopoSort();
	
	
	return 0;
}

/*
表示课程之间优先关系的有向无环图
假设直线都带有从左到右的箭头 
		  C5
	    /    \
	   /      C6
	  /	    /  
	C2----C4
	 \   /  \
	  \ /    \
	  C3      \
	 /    	  C7
   C1        /
     \      /
      C8   /
       \  /
        C9
输出结果为 : 2 5 1 8 9 3 4 7 6


*/
