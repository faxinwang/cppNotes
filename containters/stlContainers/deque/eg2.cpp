/*
	the following example is a simple example that shows the abilities of deque
*/

#include<iostream>
#include<deque>
#include<algorithm>
#include<iterator>
#include<string>
using namespace std;

int main(){
	//create empty deque of string
	deque<string> deque1;
	
	//insert several elements
	deque1.assign(4,string("string"));
	deque1.push_back("last string");
	deque1.push_front("first string");
	
	//print elements separated by newlines
	copy(deque1.begin(),deque1.end(),
		ostream_iterator<string>(cout,"\n"));
	cout<<endl;
	
	//remove first and last element
	deque1.pop_front();
	deque1.pop_back();
	
	//insert "another " into every element but the first
	for(int i=1;i<deque1.size();++i){
		deque1[i]="another " + deque1[i];
	}
	
	//change size to size()+3
	deque1.resize(deque1.size()+3,"resized string");
	
	//print elements separated by newlines
	copy(deque1.begin(),deque1.end(),
		ostream_iterator<string>(cout,"\n"));
	
	return 0;
}
