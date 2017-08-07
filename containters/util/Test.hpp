#ifndef Test_H
#define Test_H

#include<iostream>


class Test{
	static int count;
	int id;
	public:
		Test():id(count++){std::cout<<"constructing object "<<id<<std::endl;}
		Test(const Test& test){
			id=test.id;
			std::cout<<"copying object "<<id<<std::endl;
		}
		~Test(){
			std::cout<<"destructing object "<<id<<std::endl;
		}
		void operator=(const Test& test){
			id=test.id;
			std::cout<<"assigning object "<<id<<std::endl;
		} 
		friend std::ostream& operator<<(std::ostream& out,const Test& test);
		bool operator==(const Test& t2){
			return id==t2.id;
		}
		bool operator!=(const Test& t2){
			return id!=t2.id;
		}
};
int Test::count=1;
std::ostream& operator<<(std::ostream& out,const Test& test){
	return out<<"Test id="<<test.id;
}

#endif
