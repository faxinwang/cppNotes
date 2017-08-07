#include<iostream>
#include"ListGraph.hpp"
using namespace std;

int main(){
	int v[]={1,2,3,4};
	ListGraph<int> g(sizeof(v)/sizeof(*v),v);
	
	g.add_edge(1,2,0);
	g.add_edge(1,3,0);
	g.add_edge(2,4,0);
	g.add_edge(3,4,0);

	g.DFS();
	cout<<endl; 
	
	g.add_node(5),
	g.add_node(6);
	g.add_edge(4,5,0);
	g.add_edge(3,6,0);
	
	g.DFS();
	cout<<endl;
	
	g.del_edge(2,4);
	g.DFS();
	cout<<endl;
	
	g.add_node(7);
	g.add_node(8);
	g.add_edge(3,7);
	g.add_edge(7,8);
	g.DFS();
	cout<<endl;
	
	g.del_edge(3,7);
	g.DFS();
	cout<<endl;
	
	
	return 0;
}

/*
		1
	   / \
	  2   3
	   \ /
	    4 
------------------1 2 4 3
	    1
	   / \
	  2   3
	   \ /\
	    4  6
	    \
	     5
------------------1 2 4 3 6 5
		1
	   / \
	  2   3 
	     /\
	    4  6
	    \
	     5
-------------------1 2 3 4 5 6
		1
	   / \
	  2   3-7-8
	     /\
	    4  6
	    \
	     5
-------------------1 2 3 4 5 6 7 8

		1
	   / \
	  2   3  7-8
	     /\
	    4  6
	    \
	     5
-------------------1 2 3 4 5 6
				   7 8				   
				   
*/
