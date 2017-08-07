/*
	example of specifying the sorting criterion of runtime
*/
#include<iostream>
#include<set>
#include"../../../udga/Print_coll.h"
using namespace std;

template<class T>
class RuntimeCmp{
	public:
		enum cmp_mode{ normal, reverse};
	private:
		cmp_mode mode;
	public:
		//constructor for sorting criterion
		//default criterion uses value normal
		RuntimeCmp(cmp_mode m=normal):mode(m){}
		
		//comparision of elements
		bool operator()(const T& t1,const T& t2)const{
			return mode==normal?t1<t2:t2<t1;
		}
		//comparision of sorting criteria
		bool operator==(const RuntimeCmp& rc){
			return mode == rc.mode;
		}
};
//type of a set that uses this sorting criterion
typedef set<int,RuntimeCmp<int> > IntSet;

void fill(IntSet& set){
	//insert elements in random order
	set.insert(4);
	set.insert(7);
	set.insert(5);
	set.insert(1);
	set.insert(6);
	set.insert(2);
	set.insert(5);
}

int main(){
	//crreate,fill,print set1 with normal elements order
	//-use default sorting criterion
	IntSet set1;
	fill(set1);
	Print_coll(set1,"set1: ");
	
	//create sorting criterion with reverse element order
	RuntimeCmp<int> reverse_order(RuntimeCmp<int>::reverse);
	
	//create,fill,print set2 with reverse elements order
	IntSet set2(reverse_order);
	fill(set2);
	Print_coll(set2,"set2: ");
	
	if(set1.value_comp() == set2.value_comp()){
		cout << "set1 and set2 have same sorting criterion" << endl;
	}else{
		cout << "set1 and set2 have different sorting criterion" << endl;		
	}
	
	//assign set2 to set1(and sorting criterion)
	set1=set2;
	set1.insert(3);
	Print_coll(set1,"set1: ");
	
	if(set1.value_comp() == set2.value_comp()){
		cout << "set1 and set2 have same sorting criterion" << endl;
	}else{
		cout << "set1 and set2 have different sorting criterion" << endl;		
	}
	
	return 0;
}
