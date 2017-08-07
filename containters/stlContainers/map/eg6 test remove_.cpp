#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include"../../../udga/Print_coll.hpp"
#include"../../../udga/remove_.hpp"
using namespace std;

typedef multimap<string,float> StrFloatMMap;


int main(){
	//coll:multimap
	//key:stirng
	//value:float
	StrFloatMMap stocks;
	
	//stocks["sina"]=500.9;	//mulitmap without subscript[] operator 
	stocks.insert(make_pair("sina",500.9));
	stocks.insert(make_pair("baidu",800.8));
	stocks.insert(make_pair("tengxun",902.5));
	stocks.insert(make_pair("alibaba",950.8));
	stocks.insert(make_pair("sina",555.9));
	stocks.insert(make_pair("aaa",111));
	stocks.insert(make_pair("bbb",111));
	stocks.insert(make_pair("ccc",111));
	Print_acoll(stocks,10,"stocks initialized:");
	
	//remove all elements with the passed key
//	stocks.erase("sina");
	Print_acoll(stocks,10,"after removed first \"sina\":");
	
	remove_all(stocks,111);
	Print_acoll(stocks,10,"after removed all elements with value 111");
	
	
	return 0;
}
