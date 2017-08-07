#include<iostream> 
#include"MatrixGraph.hpp"
using namespace std;

int main(){
	int v[]={1,2,3,4,5,6};
	MatrixGraph<int> g(sizeof(v)/sizeof(*v),v);
	g.add_edge(1,2);
	g.add_edge(1,4);
	g.add_edge(2,3);
	g.add_edge(3,5);
	g.add_edge(4,5);
	g.add_edge(4,6);
	
	cout<<"是否有向: "<<boolalpha<<g.is_oriented()<<endl;
	g.print_matrix();
	cout<<"in_degree(1): "<<g.in_degree(1)<<endl;
	cout<<"out_degree(1): "<<g.out_degree(1)<<endl;
	cout<<"degree(1): "<<g.degree(1)<<endl<<endl;
	
	cout<<"in_degree(4): "<<g.in_degree(4)<<endl;
	cout<<"out_degree(4): "<<g.out_degree(4)<<endl;
	cout<<"degree(4): "<<g.degree(4)<<endl<<endl;	


	MatrixGraph<int> og(sizeof(v)/sizeof(*v),v,-1,true);
	
	og.add_edge(1,2);
	og.add_edge(2,3);
	og.add_edge(1,4);
	og.add_edge(4,5);
	og.add_edge(4,6);
	og.add_edge(6,5);
	
	cout<<"是否有向: "<<boolalpha<<og.is_oriented()<<endl;
	og.print_matrix();
	cout<<"in_degree(1): "<<og.in_degree(1)<<endl;
	cout<<"out_degree(1): "<<og.out_degree(1)<<endl;
	cout<<"degree(1): "<<og.degree(1)<<endl<<endl;

	cout<<"in_degree(2): "<<og.in_degree(2)<<endl;
	cout<<"out_degree(2): "<<og.out_degree(2)<<endl;
	cout<<"degree(2): "<<og.degree(2)<<endl<<endl;
	
	cout<<"in_degree(3): "<<og.in_degree(3)<<endl;
	cout<<"out_degree(3): "<<og.out_degree(3)<<endl;
	cout<<"degree(3): "<<og.degree(3)<<endl<<endl;
	
	cout<<"in_degree(4): "<<og.in_degree(4)<<endl;
	cout<<"out_degree(4): "<<og.out_degree(4)<<endl;
	cout<<"degree(4): "<<og.degree(4)<<endl<<endl;


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
