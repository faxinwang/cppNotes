#include<iostream>
#include"linkQueue.hpp"
#include"../../util/printInfo.hpp"
#define HH puts("")
using namespace std;


int main(){
	LinkQueue<int> queue;
	printInfo(queue);
	for(int i=0;i<10;++i){
		queue.enQueue(i);
	}
	HH;
	printInfo(queue);
	HH;
	for(int i=0;i<5;++i)
		cout<<queue.deQueue()<<' ';
	HH;
	printInfo(queue);
	
	return 0;
}
