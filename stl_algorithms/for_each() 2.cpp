#include"algostuff.hpp"
using namespace std;

//function object that adds the value with witch it is initialized
template<class T>
class AddValue{
	private:
		T theValue;	//value ot add
	public:
		//constructor initializes the value to add
		AddValue(const T& v):theValue(v){}
		//the function call for the element adds the value
		void operator()(T& elem)const{
			elem+=theValue;
		}
};

int main(){
	vector<int> coll;
	INSERT_ELEMENTS(coll,1,9);
	//add ten to each element
	for_each(coll.begin(),coll.end(),AddValue<int>(10));
	PRINT_ELEMENTS(coll);
	
	//add value of first element to each element
	for_each(coll.begin(),coll.end(),AddValue<int>(*coll.begin()));
	PRINT_ELEMENTS(coll);
	
	return 0;
}
