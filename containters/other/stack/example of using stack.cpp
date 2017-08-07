#include<iostream>
#include<stack>
using namespace std;
/*
The core interface of stack
push()
top()
pop()
*/

int main(){
	stack<int> stk;
	//push three elements into stk
	stk.push(1);
	stk.push(2);
	stk.push(3);
	//pop and print two elements from the stack
	cout<<stk.top()<<' ';
	stk.pop();
	cout<<stk.top()<<' ';
	stk.pop();
	//modify top element
	stk.top()=77;
	//push two new elements
	stk.push(4);
	stk.push(5);
	
	//pop and print remaining elements
	while(!stk.empty()){
		cout<<stk.top()<<' ';
		stk.pop();
	}
	cout<<endl;
	
	return 0;
}
