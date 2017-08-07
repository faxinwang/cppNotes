#include"algostuff.hpp"
using namespace std;

/*
Testing for "Less Than"
	bool
	lexicographical_compare(InputIter1 beg1, InputIter1 end1,
							InputIter2 beg2, InputIter2 end2)
	bool
	lexicographical_compare(InputIter1 beg1, InputIter1 end1,
							InputIter2 beg2, InputIter2 end2,
							CompFunc op)
	* both forms return whether the elements in the range [beg1,end1) are "lexicographically
	  less than(compareing element-by-element)" the elements in the range[beg2,end2) 
*/

void printCollection(const list<int>& l){
	PRINT_ELEMENTS(l);
}

bool lessForCollection(const list<int>& l1,const list<int>& l2){
	return lexicographical_compare(l1.begin(),l1.end(),
								   l2.begin(),l2.end());
}

int main(){
	list<int> c1,c2,c3,c4;
	//fill all collection with the same starting values
	INSERT_ELEMENTS(c1,1,5);
	c4=c3=c2=c1;
	
	//and now some differences
	c1.push_back(7);
	c3.push_back(2);
	c3.push_back(0);
	c4.push_back(2);
	
	//create collection of collections
	vector<list<int> > cc;
	cc.push_back(c1);
	cc.push_back(c2);
	cc.push_back(c3);
	cc.push_back(c4);
	cc.push_back(c3);
	cc.push_back(c1);
	cc.push_back(c4);
	cc.push_back(c2);
	
	for_each(cc.begin(),cc.end(),printCollection);
	cout<<endl;
	
	//sort collection lexicographically
	sort(cc.begin(),cc.end(),lessForCollection);
	
	//print all collection again
	for_each(cc.begin(),cc.end(),printCollection);
	cout<<endl;
	
	return 0;
}
