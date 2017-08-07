#include<iostream>
#include<cstdlib>
#include<ctime>
#include"OpenHashTable.hpp"
using namespace std;



int main(){
	const int N=20;
	int data[N],i;
	OpenHashTable<int> tb(2*N);
	
	srand(time(0));
	for(i=0;i<N;++i){
		data[i]= rand() % 1000;
	//	cout<<i<<" : "<<data[i]<<endl;
		tb.insert(data[i]);
	}
	tb.remove(data[1]);
	tb.remove(data[4]);
	tb.remove(data[7]);
	tb.remove(data[10]);
	tb.remove(data[13]);
	tb.remove(data[16]);
	tb.remove(data[19]);
	
	cout<<"----------------------------------"<<endl;
	
	for(i=0;i<N;++i){
		if(tb.find(data[i]))
			cout<<"find: "<<data[i]<<endl;
		else 
			cout<<data[i]<<" is not in the table!"<<endl;
	}
	
	
	return 0;
}
