/*
	binary predicates typically compare a special property of two arugments.
	For example,to sort elements according to your own criterion you could 
	provide it as a simple predicate function.This might be necessary because
	the elements do not provide operator< or because you wish to use a different
	criterion.
*/

#include<iostream>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;

class Person{
	public:
		Person(string fn,string ln):firstName(fn),lastName(ln){}
		string firstName,lastName;
};


bool personSortCriterion(const Person& p1,const Person& p2){
	/* a person is less than another person
	 * if the first name is less
	 * if the first name is equal and the last name is less
	 */
	return (p1.firstName < p2.firstName ||
			(!(p2.firstName<p1.firstName)) 
			&& p1.lastName<p2.lastName);
}

inline void print(Person& ps){
	cout<<ps.firstName<<' '<< ps.lastName<<endl;
}

int main(){
	deque<Person> deque1;
	deque1.push_back(Person("wang","faxin"));
	deque1.push_back(Person("xia","bei"));
	deque1.push_back(Person("wang","lifei"));
	deque1.push_back(Person("niu","qingkun"));
	deque1.push_back(Person("niu","huibing"));
	deque1.push_back(Person("zhao","fei"));
	deque1.push_back(Person("xiao","wan"));
	deque1.push_back(Person("cheng","lihong"));
	
	sort(deque1.begin(),deque1.end(),	//range
		personSortCriterion);			//sort criterion
	
	//print deque1
	for_each(deque1.begin(),deque1.end(),
			print);
	
	return 0;
}
