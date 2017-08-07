#include<iostream>
#include"Ring.hpp"
using namespace std;

template<typename T>
void josephu(Ring<T>& r1,Ring<T>& r2,int k){
	typename Ring<T>::iterator it=r1.begin();
	while(r1.size()){
		for(int i=1;i<k;++i,++it);
		r2.push_back(*it);
		it=it.erase();
	}
}


int main(){
	const int N = 30;
	Ring<int> r1,r2;
	Ring<int>::iterator it;

	for(int i=1;i<=N;i++)
		r1.push_back(i);	
	
	josephu<int>(r1,r2,3);
	
	cout<<"³öÁÐË³Ðò:"<<endl;
	for(it=r2.begin();r2.size();){
		cout<<*it<<' ';
		it=it.erase();
	}
	cout<<endl;
	return 0;
}
