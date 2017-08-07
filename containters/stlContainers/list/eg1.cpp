/*
	the following example creates an empty list of characters,insert all characters 
	from 'a' to 'z',and prints all elements by suing a loop that actually prints 
	and remove the first elements of the collection.
*/

#include<iostream>
#include<list>
using namespace std;


int main(){
	list<char> coll;
	
	//append elements from 'a' to 'z'
	for(char c='a';c<='z';++c){
		coll.push_back(c);
	}
	
	/* print all elements
	 * while there are elements
	   print and remove the first elements
	 */
	while(!coll.empty()){
		cout << coll.front() << " ";
		coll.pop_front(); 
	}
	cout << endl;
	
	return 0;
}
