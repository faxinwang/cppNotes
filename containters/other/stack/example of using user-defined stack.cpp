#include<iostream>
#include"Stack.hpp"
using namespace std;

int main(){
	Stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	try{
		cout<<st.pop()<<' ';
		cout<<st.pop()<<' ';
		st.top()=77;
		st.push(4);
		st.push(5);
		st.pop();
		cout<<st.pop()<<' ';
		cout<<st.pop()<<endl;
		cout<<st.pop()<<endl;
	}catch(const exception& e){
		cerr<<"EXCEPTION:"<<e.what()<<endl;
	}
	
	return 0;
}
