#include<iostream>
#include"../myStack/linkStack.hpp"
#include"../../util/printInfo.hpp"
#define HH puts("")
using namespace std;




int main(){
	LinkStack<int> lstack;
	printInfo(lstack);
	HH;
	for(int i=0;i<10;++i){
		lstack.push(i);
	}
	printInfo(lstack);
	HH;
	for(int i=0;i<5;++i){
		cout<<lstack.peek()<<' ';
		lstack.pop();
	}
	HH;
	printInfo(lstack);
	HH;
	while(!lstack.empty()){
		lstack.pop();
	}
	printInfo(lstack);
	return 0;
}
