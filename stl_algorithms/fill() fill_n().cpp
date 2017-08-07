#include"algostuff.hpp"
using namespace std;

/*
Assigning the Same Value
	void
	fill(ForwardIter beg, ForwardIter end, const T& newValue)
	
	void
	fill_n(OutputIter beg, Size num, const T& newValue)
	
	* fill() assign newValue to each element in the range [beg,end)
	* fill_n() assign newValue to the first num elements start from beg
*/

int main(){
	//print ten times 7.7
	fill_n(ostream_iterator<int>(cout," "),10,7.7);
	cout<<endl;
	
	list<string> coll;
	
	//insert "hello" nine times
	fill_n(back_inserter(coll),9,"hello");
	PRINT_ELEMENTS(coll,"coll: ");
	
	//overwrite all elements with "again"
	fill(coll.begin(),coll.end(),"again");
	PRINT_ELEMENTS(coll,"coll: ");
	
	//replace all but two elements with "hi"
	fill_n(coll.begin(),coll.size()-2,"hi");
	PRINT_ELEMENTS(coll,"coll: ");
	
	//replace the second and up to the last element but one with "hmmm"
	list<string>::iterator pos1,pos2;
	pos1=coll.begin();
	pos2=coll.end();
	fill(++pos1,--pos2,"hmmm");
	
	PRINT_ELEMENTS(coll,"coll: ");
	
	return 0;
}
