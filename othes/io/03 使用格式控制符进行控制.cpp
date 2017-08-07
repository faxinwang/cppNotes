#include<iostream>
#include<iomanip>
using namespace std;

/*
预定义格式控制符分为带参数和不带参数两种，带参数的在头文件iomanip中，不带参数的在iostream中 

dec		//十进制,设置后一直起作用，直到被修改为止 
hex 	//十六进制
oct		//八进制
ws		//仅用于输入时跳过开头的空白符
endl	//插入一个换行符并刷新输出流
ends	//插入一个空字符,以结束一个字符串,仅用于输出
flush	//仅用于刷新输出流
setbase(int n)//设置基数位(0 8 10 16)默认为0(十进制)
resetiosflags(long n)//关闭有参数指定的各式,用于输入或输出
setiosflags(long n)//设置有参数指定的各式，用于输入或输出
setfill(int c)	//设置填充字符,默认为空格，用于输入或输出
setprecision(int n)	//设置小数位,默认为6为，用于输入或输出,会进行四舍五入 
setw(int n)	//设置域宽，用于输入或输出,只对最近的一个输出起作用 
*/

//自定义各式控制符,
ostream &myout(ostream out){
	cout.setf(ios::right);
	cout<<setw(10)<<dec<<setfill('#');
	return out;	//必须返回参数中的对象 ,且参数必须是一个ostream对象 
}

int main3(){
	cout<<myout<<123<<endl;
	cout<<123<<setiosflags(ios::scientific)<<setw(15)<<123.456789<<endl;
	cout<<123<<"十六进制:"<<setw(10)<<hex<<123<<endl;
	cout<<123<<"八进制:"<<setw(10)<<oct<<123<<endl;
	cout<<123<<"十进制:"<<setw(10)<<dec<<123<<endl;
	cout<<resetiosflags(ios::scientific)<<setprecision(4)<<123.456789<<endl;
	cout<<setiosflags(ios::right)<<setfill('#')<<setw(10)<<12345<<endl;
	
	return 0;
}
 
