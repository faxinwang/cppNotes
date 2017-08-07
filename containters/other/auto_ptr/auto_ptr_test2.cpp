#include<iostream>
#include"auto_ptr.h"
using std::ostream;
using std::cout;
using std::endl;
using namespace mylib;

template<class T>
ostream& operator<<(ostream& out,const auto_ptr<T> &p){
	if(p.get()==NULL)
		out<<"NULL";
	else
		out<<*p;
	return out;
}

int main(){
	const auto_ptr<int> m(new int(42));
	const auto_ptr<int> n(new int(0));
	const auto_ptr<int> r;
	
	cout<<"after initialization"<<endl;
	cout<<"m:"<<m<<endl;
	cout<<"n:"<<n<<endl;
	cout<<"r:"<<r<<endl;
	
	*m=*n;
//	*r=*n;	//errror
	*n=-77;
	cout<<"after assignment values:"<<endl;
	cout<<"m:"<<m<<endl;
	cout<<"n:"<<n<<endl;
	cout<<"r:"<<r<<endl;
	
//	m=n;	//error at compile time
//	r=n;	//error at compile time
}
