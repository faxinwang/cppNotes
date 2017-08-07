#include"algostuff.hpp"
using namespace std;

//checks whether an elements is even or odd
bool checkEven(int elem,bool even){
	if(even){
		return elem%2==0;
	}else{
		return elem%2==1;
	}
}

int main(){
	vector<int> coll;
	INSERT_ELEMENTS(coll,1,9);
	PRINT_ELEMENTS(coll,"coll: ");
	
	//arguments for checkEven()
	bool checkEvenArgs[3]={true,false,true};
	
	//search first subrange in coll
	vector<int>::iterator pos;
	pos = search(coll.begin(),coll.end(),
				checkEvenArgs,checkEvenArgs+3,
				checkEven);
	//loop while subrange found
	while(pos!=coll.end()){
		//print position of first element
		cout<<"subrange found starting with "
			<<distance(coll.begin(),pos)+1
			<<"th element"
			<<endl;
		pos = search(++pos,coll.end(),
				checkEvenArgs,checkEvenArgs+3,
				checkEven);
	}
	
	
	return 0;
}
