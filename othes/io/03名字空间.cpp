#include<iostream>
#include"my_msg.h"
using std::cout;
using std::endl;
using namespace my_msg;
using namespace my_msg::get_msg;
 
int main3(){
	
	cout<<"name:"<<name<<endl;
	cout<<"sex:"<<Sex<<endl;
	cout<<"age:"<<age<<endl;
	cout<<"hight:"<<getHight()<<endl;
	cout<<"weight:"<<getWeight()<<endl; 
	
	return 0;
}
