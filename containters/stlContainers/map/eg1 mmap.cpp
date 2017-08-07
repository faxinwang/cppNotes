/*
	the following example shows the basic usage of mulitmap
*/

#include<iostream>
#include<map>
#include<string>
using namespace std;

typedef multimap<int,string> IntStrMMap;

int main(){
	IntStrMMap coll;
	
	//insert some elements in arbitrary order
	//the elements with key 1 gets inserted twice
	coll.insert(make_pair(5,"tagged"));
	coll.insert(make_pair(2,"a"));
	coll.insert(make_pair(1,"this"));
	coll.insert(make_pair(4,"of"));
	coll.insert(make_pair(6,"strings"));
	coll.insert(make_pair(1,"is"));
	coll.insert(make_pair(3,"multimap"));
	
	//print the value of all elements
	IntStrMMap::iterator pos;
	for(pos=coll.begin();pos != coll.end();++pos){
		cout << pos->second <<' ';
	}
	cout<<endl;
	
	return 0;
}
