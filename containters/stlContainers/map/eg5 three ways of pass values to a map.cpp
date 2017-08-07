#include<iostream>
#include<string>
#include<map>
#include"../../udga/Print_coll.hpp"
using namespace std;

typedef map<string,int> StrIntMap;

int main(){
	//coll:map
	//key:string
	//value:int
	StrIntMap map;
	
	/* three ways to pass a value into a map*/
	//1.pass the correct type explicitly by using value_type
	map.insert(StrIntMap::value_type("wangfaxin",21));
	
	//2.use pair<> directly
	//implicit conversion
	map.insert(pair<string,float>("hushuchang",21));
	//no inplicit conversion
	map.insert(pair<string,float>("xiabei",21));
	
	//3.use the make_pair() function
	//the most convenient way
	map.insert(make_pair("wangsheng",24));
	
	Print_acoll(map,10,"name and age:");
	
	return 0;
}
