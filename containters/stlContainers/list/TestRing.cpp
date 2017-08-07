#include<iostream> 
#include<iterator>
#include<list>
#include<string>
#include"Ring.hpp"
using namespace std;


int main(){
	Ring<string> ring;
	ring.push_back("one");
	ring.push_back("two");
	ring.push_back("three");
	ring.push_back("four");
	ring.push_back("five");
	ring.push_back("six");
	Ring<string>::iterator it=ring.begin();
	++it;++it;
	it.insert("seven");
	it=ring.begin();
	//twice around the ring
	for(int i=0;i<ring.size()*2;++i,++it)
		cout<<*it<<endl;
	cout<<endl;
	it=ring.begin();
	++it;++it;
	it=it.erase();
	for(int i=0;i<ring.size()*2;++i,++it)
		cout<<*it<<endl;
	return 0;
}
