/*
	the follow example shows how to use the global find_if() algorithm to find 
	an element with a certain value
*/

#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

//function object to check the value of a map element
template<class K,class V>
class value_equal{
	private:
		V value;
	public:
		//constructor(initialize value to compare with)
		value_equal(const V& v):value(v){
		}
		//comparison
		bool operator()(pair<const K,V> elem){
			return elem.second == value;
		}
};

typedef map<float,float> FloatFloatMap;

int main(){
	//coll:map
	//key:float
	//value:float
	FloatFloatMap map;
	FloatFloatMap::iterator pos;
	
	//fill container
	map[1]=7;
	map[2]=4;
	map[3]=2;
	map[4]=3;
	map[5]=6;
	map[6]=1;
	map[7]=3;
	
	//search an element with key 3.0
	//logarithmic complexity
	pos=map.find(3.0);
	if(pos!=map.end()){
		cout << pos->first<<":"
			 << pos->second<<endl;
	}
	
	//search an element with value 3.0
	//linear complexity
	pos=find_if(map.begin(),map.end(),
				value_equal<float,float>(3.0));
	if(pos!=map.end()){
		cout << pos->first << ":"
			 << pos->second << endl; 
	}
	return 0;
}
