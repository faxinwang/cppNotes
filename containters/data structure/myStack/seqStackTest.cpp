#include<iostream>
#include"seqStack.hpp"
#include"../../util/printInfo.hpp" 
#define HH puts("") 
using namespace std;


int main(){
	seqStack<int> sstack(15);
	printInfo(sstack);
	
	for(int i=0;i<20;i++){
		sstack.push(i);
	}
	printInfo(sstack);
	
	for(int i=0;i<5;++i){
		sstack.pop();
	}
	
	while(!sstack.empty()){
		cout<<sstack.peek()<<' ';
		sstack.pop();
	} 
	HH;
	printInfo(sstack);
	
	return 0;
}
