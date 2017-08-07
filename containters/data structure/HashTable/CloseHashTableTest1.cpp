#include<iostream>
#include<string>
#include"CloseHashTable.hpp"
using namespace std;

class Person{
	private:
		string name;
		int age;
	public:
		Person():age(0),name(""){}
		Person(string str,int a):name(str),age(a){}
		Person(const Person& p){name=p.name;age=p.age;}
		int getAge(){return age;}
		string getName(){return name;}
		bool operator==(const Person& p2){
			return (age==p2.age && name==p2.name);
		}
		friend ostream& operator<<(ostream& out,const Person& p);
		friend int getKey(const Person& p);
};

ostream& operator<<(ostream& out,const Person& p){
	out<<"[ "<<p.name<<" , "<<p.age<<" ]";
	return out;
}

int getKey(const Person& p){
	int key=p.age;
	for(int i=0;i<p.name.size();++i){
		key+=p.name[i]-'a'+1;
	}
	return key;
}



int main(){
	const int N=12;
	CloseHashTable<Person> tb(12,getKey);
	Person ps[N]={Person("wfx",20),Person("xcy",19),Person("hs",18),
				 Person("xw",19),Person("nqk",19),Person("zd",18),
				 Person("xm",19),Person("xlf",20),Person("lkx",17),
				 Person("zq",18),Person("wty",20),Person("wcx",18)
				 };
				 
	for(int i=0;i<N;++i)
		tb.insert(ps[i]);
	

	for(int i=0;i<N;++i){
		if( tb.find(ps[i]) )
			cout<<"find: "<<ps[i]<<endl;
	}
	tb.remove(ps[1]);
	tb.remove(ps[4]);
	tb.remove(ps[7]);
	tb.remove(ps[9]);
	tb.remove(ps[11]);
	cout<<"----------------------------------"<<endl;
	for(int i=0;i<N;++i){
		if( tb.find(ps[i]) )
			cout<<"find: "<<ps[i]<<endl;
		else
			cout<<ps[i]<<" is not in the table!"<<endl;
	}
	
	return 0;
}
