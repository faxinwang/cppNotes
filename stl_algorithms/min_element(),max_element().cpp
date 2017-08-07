#include"algostuff.hpp"
using namespace std;

/*
	InputIter
	min_element(InputIter beg, InputIter end)
	
	InputIter
	min_element(InputIter beg, InputIter end, CompFunc op)
	
	InputIter
	max_element(InputIter beg, InputIter end)
	
	InputIter
	max_element(InputIter beg, InputIter end, CompFunc op)
	
	* all algorithms return the position of the min or max element in the range [beg,end)	
*/

bool absLess(int elem1,int elem2){
	return abs(elem1)<abs(elem2);
}


int main(){
	deque<int> coll;
	INSERT_ELEMENTS(coll,2,8);
	INSERT_ELEMENTS(coll,-3,5);
	
	PRINT_ELEMENTS(coll);
	
	//process and print minimum and maximum
	cout<<"minimum: "<<*min_element(coll.begin(),coll.end())<<endl;
	cout<<"maximum: "<<*max_element(coll.begin(),coll.end())<<endl;
	
	//process and print minimum and maximum of absolute values
	cout<<"minimum of absolute value: "<<*min_element(coll.begin(),coll.end(),absLess)<<endl;
	cout<<"maximum of absolute value: "<<*max_element(coll.begin(),coll.end(),absLess)<<endl;
	
	return 0;
}
