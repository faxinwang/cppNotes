#include<iostream> 
#include"ListGraph.hpp"
using namespace std;

int main(){
	int v[]={1,2,3,4,5,6};
	ListGraph<int> g(sizeof(v)/sizeof(*v),v,false);
	g.add_edge(1,2);
	g.add_edge(1,4);
	g.add_edge(2,3);
	g.add_edge(3,5);
	g.add_edge(4,5);
	g.add_edge(4,6);
	
	cout<<"是否有向:\t"<<boolalpha<<g.is_oriented()<<endl;
	cout<<"in_degree(1):\t"<<g.in_degree(1)<<endl;
	cout<<"out_degree(1):\t"<<g.out_degree(1)<<endl;
	cout<<"degree(1):\t"<<g.degree(1)<<endl<<endl;
	
	cout<<"in_degree(4):\t"<<g.in_degree(4)<<endl;
	cout<<"out_degree(4):\t"<<g.out_degree(4)<<endl;
	cout<<"degree(4):\t"<<g.degree(4)<<endl<<endl;	


	ListGraph<int> og(sizeof(v)/sizeof(*v),v,true);
	
	og.add_edge(1,2);
	og.add_edge(2,3);
	og.add_edge(1,4);
	og.add_edge(4,5);
	og.add_edge(4,6);
	og.add_edge(6,5);
	
	cout<<"是否有向:\t"<<boolalpha<<og.is_oriented()<<endl;
	cout<<"in_degree(1):\t"<<og.in_degree(1)<<endl;
	cout<<"out_degree(1):\t"<<og.out_degree(1)<<endl;
	cout<<"degree(1):\t"<<og.degree(1)<<endl<<endl;

	cout<<"in_degree(2):\t"<<og.in_degree(2)<<endl;
	cout<<"out_degree(2):\t"<<og.out_degree(2)<<endl;
	cout<<"degree(2):\t"<<og.degree(2)<<endl<<endl;
	
	cout<<"in_degree(3):\t"<<og.in_degree(3)<<endl;
	cout<<"out_degree(3):\t"<<og.out_degree(3)<<endl;
	cout<<"degree(3):\t"<<og.degree(3)<<endl<<endl;
	
	cout<<"in_degree(4):\t"<<og.in_degree(4)<<endl;
	cout<<"out_degree(4):\t"<<og.out_degree(4)<<endl;
	cout<<"degree(4):\t"<<og.degree(4)<<endl<<endl;


	return 0;
}

/*

1--2--3
\	 /
 4--5
 \
  6
-----------
*/

/*
	1-->2-->3
	|		
	-->4-->5
	   |   ^
	   V  /
	   6-/
*/
