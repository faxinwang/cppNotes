#include<iostream>
#include<string>
#include<iomanip>


/* this function print all elements of given collection */
template<class T>
void Print_coll(const T& coll,const std::string& str=""){
	using namespace std;
	typename T::const_iterator pos;
	
	cout<<str;
	for(pos=coll.begin();pos!=coll.end();++pos){
		cout<< *pos <<' ';
	}
	cout<<endl;
}

template<class T>
void Print_acoll(const T& coll,int width=10,const std::string& str=""){
	using namespace std;
	typename T::const_iterator pos;
	
	if(str==""){
		//do nothing
	}else{
		cout<<str<<endl;
	}
//	cout.setf(ios::right,ios::adjustfield);
	for(pos=coll.begin();pos!=coll.end();++pos){
		cout<< setw(width) <<pos->first<<" : "<<pos->second<<endl;
	}
	cout << endl;
}

