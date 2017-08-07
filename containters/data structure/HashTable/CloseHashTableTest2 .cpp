#include<iostream>
#include<cstdlib>
#include<ctime>
#include"CloseHashTable.hpp"
using namespace std;




int main(){
	const int N=20;
	int data[N],i;
	CloseHashTable<int> tb(N);
	
	srand(time(0));
	for(i=0;i<N;++i){
		data[i]= rand() % 500;
		cout<<data[i]<<endl;
		tb.insert(data[i]);
	}
	tb.remove(data[1]);
	tb.remove(data[3]);
	tb.remove(data[5]);
	tb.remove(data[7]);
	tb.remove(data[9]);
	tb.remove(data[11]);
	tb.remove(data[12]);
	
	cout<<"----------------------------------"<<endl;
	
	for(i=0;i<N;++i){
		if(tb.find(data[i]))
			cout<<"find: "<<data[i]<<endl;
		else 
			cout<<data[i]<<" is not in the table!"<<endl;
	}
	
	
	return 0;
}
