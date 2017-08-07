#include<iostream>
using namespace std;

/*
	ostream &operator<<(ostream &out,ClassName obj)
	{
		操作代码 
		return out;
	}
	istream &operator(istram &in,ClassName& obj)//注意第二个参数必须是引用类型，否侧会出错 
	{
		操作代码
		return in; 
	}
	重载输入输出运算符函数不能是类的成员函数,一般应将其定于为类的
	友元函数,另外，第一个参数必须是ostream istream的引用，不然输入的数据不会被送到目标处 
*/
class Student{
	private :
		char name[20];
		char numID[10];
		int score[3];
	public:
		friend ostream& operator<<(ostream &out,Student st);
		friend istream& operator>>(istream &in,Student& st);
}; 
ostream& operator<<(ostream &out,Student st){
	out<<endl<<"学生信息如下:"<<endl 
		<<"姓名:"<<st.name<<endl
		<<"学号:"<<st.numID<<endl
		<<"三门成绩:"<<st.score[0]<<" "<<st.score[1]<<" "<<st.score[2]
		<<endl;
		
		return out;
}
istream& operator>>(istream &in,Student& st){
	cout<<"请输入学生信息:"<<endl;
	cout<<"姓名:"; in>>st.name;
	cout<<"学号:"; in>>st.numID;
	cout<<"三门成绩:"; in>>st.score[0]>>st.score[1]>>st.score[2]; 
	return in;
}
int main4(){
	Student std;
	cin>>std;
	cout<<std; 
	
	return 0;
}
