#include<iostream>
#include"../../util/Test.hpp"
#include"Vector.hpp"
#define HH puts("") 
using namespace std;


int main(){
	Vector<int> v1; 
	int i;
	for(i=0;i<10;++i){
		v1.push_back(i);
	}
	for(i=0;i<v1.size();++i){
		cout<<v1[i]<<' ';
	}
	HH;
	for(i=0;i<10;++i){
		v1.insert(1,i);
	}
	for(i=0;i<v1.size();++i){
		cout<<v1[i]<<' ';
	}
	HH;
	
	Vector<Test> v2;
	for(i=0;i<5;++i){
		Test test;
		v2.push_back(test);
	}
	for(i=0;i<3;++i){
		cout<<v2[i]<<endl;
	}
	
	return 0;
}
