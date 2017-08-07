/*
	the following example use the iterator to print the elements of the list
*/
#include<iostream>
#include<list>
using namespace std;

int main(){
	list<char> coll;
	
	//append element 'a' to 'z' 
	for(char c='a';c<='z';++c){
		coll.push_back(c);
	}
	//transform all elements into upper
	list<char>::iterator it;
	for(it=coll.begin();it != coll.end();++it){
		*it=toupper(*it);//transform elements into upper
		cout << *it <<' ';
	}
	cout << endl;
	
	return 0;
}
