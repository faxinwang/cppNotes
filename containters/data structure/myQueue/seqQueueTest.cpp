#include<iostream>
#include"seqQueue.hpp"
#include"../../util/printInfo.hpp"
#define HH puts("")
using namespace std;




int main(){
	seqQueue<int> queue(20);
	printInfo(queue);
	HH;
	for(int i=0;i<20;++i){
		queue.enQueue(i);
	}
	printInfo(queue);
	HH;
	for(int i=0;i<10;++i){
		cout<<queue.deQueue()<<' ';
	}
	HH;
	printInfo(queue);
	
	return 0;
}
