#include<iostream>
#include<fstream>
#include<iterator>
#include<set>
#include<string>
#include"../../../udga/require.hpp"
using namespace std;

int main(){
	const char* fname="eg1 map and multimap.cpp";
	ifstream in(fname);
	assure(in,fname);
	multiset<string> wordmset;
	string word;
	while(in>>word)
		wordmset.insert(word);
	typedef multiset<string>::iterator It;
	It it=wordmset.begin();
	while(it!=wordmset.end()){
		pair<It,It> p=wordmset.equal_range(*it);
		int count=distance(p.first,p.second);
		cout<<*it<<" : "<<count<<endl;
		it=p.second;//move to the next word
	}
	return 0;
}
