#include<iostream> 
#include"ListGraph.hpp"
using namespace std;


int main(){
	double min_span;
	char v[]={'a','b','c','d','e','f'};
	ListGraph<char> lg1(sizeof(v)/sizeof(*v),v);//构造无向图
	lg1.add_edge(1,2,5);//a-b
	lg1.add_edge(1,3,4);//a-c
	lg1.add_edge(2,4,7);//b-d
	lg1.add_edge(3,4,6);//c-d
	lg1.add_edge(1,5,2);//a-e
	lg1.add_edge(3,5,9);//c-e
	lg1.add_edge(5,6,6);//e-f
	lg1.add_edge(2,6,3);//b-f
	lg1.add_edge(4,6,8);//d-f
	min_span =  lg1.min_span_tree_prim();//构造最小生成树 
	cout<<"min_span: "<<min_span<<endl<<endl;
	
	ListGraph<char> lg2(sizeof(v)/sizeof(*v),v);//构造无向图
	lg2.add_edge(1,2,6);//a-b
	lg2.add_edge(1,3,7);//a-c
	lg2.add_edge(2,4,9);//b-d
	lg2.add_edge(3,4,8);//c-d
	lg2.add_edge(1,5,1);//a-e
	lg2.add_edge(3,5,2);//c-e
	lg2.add_edge(5,6,3);//e-f
	lg2.add_edge(2,6,5);//b-f
	lg2.add_edge(4,6,4);//d-f
	min_span = lg2.min_span_tree_prim();//构造最小生成树 
	cout<<"min_span: "<<min_span<<endl<<endl;
	
	char v2[]={'a','b','c','d','e','f','g'};
	ListGraph<char> lg3(sizeof(v2)/sizeof(*v2),v2);//构造无向图
	lg3.add_edge(1,2,10);//a-b
	lg3.add_edge(2,3,25);//b-c
	lg3.add_edge(3,4,22);//c-d
	lg3.add_edge(4,5,12);//d-e
	lg3.add_edge(5,6,16);//e-f
	lg3.add_edge(6,7,14);//f-g
	lg3.add_edge(7,3,24);//f-c
	lg3.add_edge(7,4,18);//f-d
	lg3.add_edge(6,1,28);//f-a
	min_span = lg3.min_span_tree_prim();//构造最小生成树并返回最小代价 
	cout<<"min_span: "<<min_span<<endl;
	
	return 0;
}


/*
		5
	a---------b
	|\2  6  3/|
   4| e-----f |7
	|/9	    8\|
	c---------d
		6	
运行结果: 
 		5
	a---------b
	|\2     3/
   4| e     f 
	|	      
	c---------d
		6
--------------------

		6
	a---------b
	|\1     5/|
   7| e-----f |9
	|/2	 3  4\|
	c---------d
		8
运行结果:
		
	a         b
	 \1     5/
      e-----f 
	 /2	 3  4\
	c         d
		
--------------------
		  a
	  10/  \ 28
	   /    f
      b  14/ \16
      \   g  e
     25\ /|18/		(c,g,24)
        c | /12
       22\|/
          d
运行结果: min_span=99

		  a
	  10/  
	   /    f
      b  14/ \16
      \   g  e
     25\     /		
        c   /12
       22\ /
          d
*/
