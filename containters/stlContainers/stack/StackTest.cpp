#include"../util/Test.h"
#include"Stack.h"
#include<iostream>
#include<string>
using namespace std;

int main(){
	Stack<Test> stack;
	for(int i=1;i<=20;++i){
		Test test;
		stack.push(test);
	}
	//pop 10 elem,the rest will be destructed by the destructor 
	for(int i=1;i<=10;++i){
		if(stack.size()){
			cout<<stack.peek()<<endl;
			stack.pop();
		}
	}
	return 0;
}
