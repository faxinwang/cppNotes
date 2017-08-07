#include"algostuff.hpp"
using namespace std;

int main(){
	//initialize source collection with "..........abcdef.........."
	vector<char> source(5,'.');
	source.push_back('1');
	source.push_back('2');
	source.push_back('3');
	for(char c='a';c<='f';++c){
		source.push_back(c);
	}
	source.push_back('3');
	source.push_back('2');
	source.push_back('1');
	source.insert(source.end(),5,'.');
	PRINT_ELEMENTS(source,"source: ");
	
	//copy all letters three elements in front of 'a'
	vector<char> c1(source.begin(),source.end());
	copy(c1.begin()+10,c1.begin()+16,
		 c1.begin()+7);
	PRINT_ELEMENTS(c1,"c1: ");
	
	//copy all letters three elements behind the 'f'
	vector<char> c2(source.begin(),source.end());
	copy_backward(c2.begin()+10,c2.begin()+16,
				  c2.begin()+19);
	PRINT_ELEMENTS(c2,"c2: ");
	
	return 0;
}
