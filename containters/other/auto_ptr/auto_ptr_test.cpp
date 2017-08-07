#include<iostream>
#include"auto_ptr.h"
using std::ostream;
using std::cout;
using std::endl;
using namespace mylib;

template<class T>
ostream& operator<<(ostream& out,const auto_ptr<T>& p){
	if(p.get()==NULL)
		out<<"NULL\n";
	else
		out<<*p<<endl;
	return out;
}

int main(){
	auto_ptr<int> m(new int(42));
	auto_ptr<int> n;
	
	cout<<"after initialization:"<<endl;
	cout<<"m:"<<m<<endl;
	cout<<"n:"<<n<<endl;
	
	n=m;
	cout<<"after assignment auto pointers:"<<endl;
	cout<<"m:"<<m<<endl;
	cout<<"n:"<<n<<endl;
	
	*n+=13;
	m=n;
	cout<<"after change and reassignment:"<<endl;
	cout<<"m:"<<m<<endl;
	cout<<"n:"<<n<<endl;
	
	return 0;
}
