#include<iostream>
#include<cstdlib>
#include<ctime>
#include"PriorityQueue.hpp"
using namespace std;


int main(){
	const int N=20;
	int a[N];
	srand(time(0));
	for(int i=0;i<N;++i)
		a[i]=rand()%100;
	PriorityQueue<int> que(a,N);
	while(!que.empty()){
		cout<<que.deQueue()<<' ';
	}
	cout<<endl;
	
	int tmp;
	while(cin>>tmp){
		que.enQueue(tmp);
	}
	while(!que.empty()){
		cout<<que.deQueue()<<' ';
	}
	cout<<endl;
	
	return 0;
}
