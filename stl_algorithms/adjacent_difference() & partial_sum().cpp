#include"algostuff.hpp"
using namespace std;
/*
The following example demonstrate how to use partial_sum() and adjacent_difference()
to convert a sequence of relative values into a sequence of absulote values,
and vice versa:
*/

int main(){
	vector<int> coll;
	
	coll.push_back(17);
	coll.push_back(-3);
	coll.push_back(22);
	coll.push_back(13);
	coll.push_back(13);
	coll.push_back(-9);
	PRINT_ELEMENTS(coll,"coll: ");
	
	//convert into relative values
	adjacent_difference(coll.begin(),coll.end(),
						coll.begin());
	PRINT_ELEMENTS(coll,"relative: ");
	
	//convert into absolute values
	partial_sum(coll.begin(),coll.end(),
				coll.begin());
	PRINT_ELEMENTS(coll,"absolute: ");
	
	return 0;
}
