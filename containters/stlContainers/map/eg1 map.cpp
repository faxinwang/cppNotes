/*
	the following example shows the basic usage of a map
*/

#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
	
	/* container : map
	   key : string
	   value : flaot
	*/
	typedef map<string,float> StrFloatMap;
	StrFloatMap coll;
	//insert some elements into the collection
	coll["vat"]=0.5;
	coll["pi"]=3.1415;
	coll["an arbitrary number"]=123.45;
	coll["null"]=0;//gets converted into float
	
	//print all elements
	StrFloatMap::iterator pos;
	for(pos = coll.begin();pos != coll.end();++pos){
		cout << "key:\"" << pos->first << "\" "
			 << "value:" << pos->second << endl;
	}
	
	return 0;
}

