#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

void print(int elem){
	cout<<elem<<' ';
}
int main(){
	typedef deque<int> IntDeque;
	IntDeque deque;
	//insert elements from 1 to 9
	for(int i=1;i<=9;++i){
		deque.push_back(i);
	}
	for_each(deque.begin(),deque.end(),print);
	cout<<endl;
	
	//find position of element with value 2
	IntDeque::iterator pos1;
	pos1=find(deque.begin(),deque.end(),2);
	//find position of element with value 7
	IntDeque::iterator pos2;
	pos2=find(deque.begin(),deque.end(),7);
	
	//print all elements in range[pos1,pos2)
	for_each(pos1,pos2,print);
	cout<<endl;
	
	//convert iterators to reverse iterators
	IntDeque::reverse_iterator rpos1(pos1);
	IntDeque::reverse_iterator rpos2(pos2);
	
	//print all elements in range[rpos1,rpos2) in reverse order
	//note:rpos2 is in front of rpos1
	for_each(rpos2,rpos1,print);
	cout<<endl;
	
	return 0;
}
