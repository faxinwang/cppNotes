#include<iostream>
#include<queue>
#include<string>
using namespace std;
/*
The core interface of queue
push()		insert an element into the queue
front()		returns the next element in the queue(the element that was inserted first)
back()		returns the last element in the queue(the element what was inserted last)
top()		remove an element from the queue
*/

int main(){
	queue<string> q;
	q.push("These ");
	q.push("are ");
	q.push("more than ");
	//read and print two element from the queue
	cout<<q.front();
	q.pop();
	cout<<q.front();
	q.pop();
	
	//insert two new elements
	q.push("four ");
	q.push("words!");
	
	//skip one element
	q.pop();
	
	//read and print two elements
	cout<<q.front();
	q.pop();
	cout<<q.front()<<endl;
	q.pop();
	
	//print number of elements in the queue
	cout<<"number of elements in the queue: "<<q.size()
		<<endl;
	
	return 0;
}
