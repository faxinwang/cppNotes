#include<iostream>
#include"Queue.hpp"
using namespace std;


int main(){
	Queue<string> q;
	
	//insert three elements into the queue
	q.push("Three ");
	q.push("are ");
	q.push("more than ");
	//read and print two elements from the queue
	cout<<q.pop();
	cout<<q.pop();
	
	//push two new elements
	q.push("four ");
	q.push("words!");
	
	//skip one element
	q.pop();
	
	//read and print two elements from the queue
	cout<<q.pop();
	cout<<q.pop()<<endl;
	
	cout<<"number of elements in the queue: "<<q.size()<<endl;
	
	return 0;
}
