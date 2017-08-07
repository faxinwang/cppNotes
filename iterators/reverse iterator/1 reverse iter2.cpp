#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

void print(int elem){
	cout<<elem<<' ';
}

int main(){
	list<int> list;
	//insert elements from 1 to 9
	for(int i=1;i<=9;++i){
		list.push_back(i);
	}
	//print all elements in norml order
	for_each(list.begin(),list.end(),print);
	cout<<endl;
	//print all elements in reverse order
	for_each(list.rbegin(),list.rend(),print);
	cout<<endl;
	
	return 0;
}
