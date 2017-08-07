/*
	the following examples shows how to use a multimap as a dictionary
*/

#include<iostream>
#include<map>
#include<string>
#include<iomanip>
#include"../../udga/Print_coll.hpp"
using namespace std;
typedef multimap<string,string> StrStrMMap;

int main(){
	//define multimap type as string/string dictionary
	StrStrMMap dict;
	
	//insert some elements in random order
	dict.insert(make_pair("day","Tag"));
	dict.insert(make_pair("strange","fremd"));
	dict.insert(make_pair("car","Auto"));
	dict.insert(make_pair("smart","elegant"));
	dict.insert(make_pair("trait","Merkmal"));
	dict.insert(make_pair("strange","seltsam"));
	dict.insert(make_pair("smart","raffiniert"));
	dict.insert(make_pair("smart","klug"));
	dict.insert(make_pair("clever","raffiniert"));
	
	//print all elements
	cout.setf(ios::left,ios::adjustfield);
	cout << ' ' <<setw(10)<<"english"<<"german"<<endl;
	cout << ' ' <<setfill('-')<<setw(20)<<""
		 << setfill(' ')<<endl;
	Print_acoll(dict);
	
	//print all values for key "smart"
	StrStrMMap::iterator pos;
	string word("smart");
	cout<<word<<":(values) "<<endl;
	for(pos=dict.lower_bound(word);
		pos!=dict.upper_bound(word);++pos){
		cout << "\t"<<pos->second<< endl;
	}
	
	//print all keys for value "raffiniert"
	word = "raffiniert";
	cout << word << " :(keys)" << endl;
	for(pos=dict.begin();pos!=dict.end();++pos){
		if(pos->second == word)
			cout<<"\t"<<pos->first<<endl;
	}
	
	
	return 0;
}
