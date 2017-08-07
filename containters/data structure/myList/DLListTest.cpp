#include<iostream>
#include"DLList.hpp"
#define HH puts("")
using namespace std;


int main(){
	int i;
	DLList<int> l1;
	for(i=0;i<10;++i){
		l1.push_back(i);
	}
	l1.insert(3,3);
	l1.insert(7,7);
	cout<<"size:"<<l1.size()<<endl;
	cout<<"is empty():"<<boolalpha<<l1.empty()<<endl;
	
	for(i=1;i<=l1.size();++i){
		cout<<l1.at(i)<<' ';
	}
	HH;
	
	return 0;
}
