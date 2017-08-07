#include<iostream>
#include"ListGraph.hpp"
using namespace std;

int main(){
	int v[]={1,2,3,4};
	ListGraph<int> g(sizeof(v)/sizeof(*v),v);
	//1
	g.add_edge(1,2,0);
	g.add_edge(1,3,0);
	g.add_edge(2,4,0);
	g.add_edge(3,4,0);
	g.BFS();
	cout<<endl; 
	
	//2
	g.add_node(5),
	g.add_node(6);
	g.add_edge(4,5,0);
	g.add_edge(3,6,0);
	g.BFS();
	cout<<endl;
	
	//3
	g.del_edge(2,4);
	g.BFS();
	cout<<endl;
	
	//4
	g.add_node(7);
	g.add_node(8);
	g.add_node(9);
	g.add_edge(2,7);
	g.add_edge(7,8);
	g.add_edge(6,9);
	g.BFS();
	cout<<endl;
	
	//5
	g.add_node(10);
	g.add_node(11);
	g.add_node(12);
	g.add_edge(8,10);
	g.add_edge(5,11);
	g.add_edge(9,12);
	g.BFS();
	cout<<endl;
	
	//6
	g.add_edge(5,8);
	g.add_edge(5,9);
	g.del_edge(4,5);
	g.del_edge(6,9);
	g.BFS();
	cout<<endl;
	
	//7
	g.del_edge(7,8);
	g.BFS();
	cout<<endl;
	
	//8
	g.add_node(13);
	g.add_node(14);
	g.add_edge(10,13);
	g.add_edge(12,14);
	g.BFS();
	cout<<endl;
	
	return 0;
}

/*
		1
	   / \
	  2   3
	   \ /
	    4 
1------------------1 2 3 4
	    1
	   / \
	  2   3
	   \ /\
	    4  6
	    \
	     5
2------------------1 2 3 4 6 5
		1
	   / \
	  2   3
	     /\
	    4  6
	    \
	     5
3------------------1 2 3 4 6 5
		1
	   / \
	  2   3
	 /   /\
	7   4  6
	\   \  \
	 8   5  9
4------------------1 2 3 7 4 6 8 5 9
		1
	   / \
	  2   3
	 /   /\
	7   4  6
	\   \  \
	 8   5  9
	/	/ 	\
   10  11	12
5---------------1 2 3 7 4 6 8 5 9 10 11 12
		1
	   / \
	  2   3
	 /   /\
	7   4  6
	\   
	 8--5--9
	/	/ 	\
   10  11	12
6-------------1 2 3 7 4 6 8 10 5 11 9 12
		1
	   / \
	  2   3
	 /   /\
	7   4  6
	
	 8--5--9
	/	/ 	\
   10  11	12
7----------------1 2 3 7 4 6
				 5 11 8 9 10 12

		1
	   / \
	  2   3
	 /   /\
	7   4  6
	
	 8--5--9
	/	/ 	\
   10  11	12
   	\		 \
   	13		 14
8---------------1 2 3 7 4 6
				5 11 8 9 10 12 13 14
*/
