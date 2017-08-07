#include<iostream>
#include<map>

template<class T,class K>
void remove_first(const T& coll,const K& key){
	using namespace std;
	typename T::iterator pos;
	//remove first element with passed key
	pos = coll.find(key);
	if(pos!=coll.end()){
		coll.erase(pos);
	}
}

template<class T,class V>
void remove_all(const T& coll,const V& value){
	using namespace std;
	typename T::iterator pos;
	//remove all element with passed value
	for(pos = coll.begin(); pos != coll.end(); ){
		if(pos->second == value){
			//pos = coll.erase(pos);//compile time error
			coll.erase(pos++); 
		}else{
			++pos;
		}
	}
}

