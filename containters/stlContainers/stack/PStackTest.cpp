#include<iostream>
#include"../util/Test.h"
#include"PStack.h"
using namespace std;



int main(){
	PStack<Test> stack;
	for(int i=1;i<=20;++i){
		stack.push(new Test());
	}
	cout<<"elements number:"<<stack.getSize()<<endl; 
	for(int i=1;i<=10;++i){
		cout<<*stack.peek()<<endl;
		stack.pop() ;
	}
	cout<<"elements number:"<<stack.getSize()<<endl; 
	
	return 0;
}
