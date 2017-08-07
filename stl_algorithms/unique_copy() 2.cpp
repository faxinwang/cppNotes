#include"algostuff.hpp"
using namespace std;

bool bothSpace(char elem1,char elem2){
	return elem1==' ' && elem2==' ';
}

int main(){
	//don't skip leading whitespaces by default
	cin.unsetf(ios::skipws);
	
	//copy standard input to standard output while compressing spaces
	unique_copy(istream_iterator<char>(cin),
				istream_iterator<char>(),
				ostream_iterator<char>(cout),
				bothSpace);
	
	return 0;
}

/*

Input:
Hellow, here are   sometimes more   and sometiems fewer    spaces.

Output:
Hellow, here are sometimes more and sometiems fewer spaces.

*/
