#include<iostream>
using namespace std;

void redirect(ostream& strm){
	
	ofstream file("redirect.txt");
	
	//save output buffer of the stream
	streambuf* strm_buffer=strm.rdbuf();
	
	//redirect output into the file
	strm.rdbuf(file.rdbut());
	file<<"one row for the file"<<endl;
	strm<<"one row for the stream"<<endl;
	
	//restore old output buffer
	strm.rdbuf(strm_buffer);
}//close file AND its buffer automatically


int main(){
	cout<<"the first row"<<endl;
	
	redirect(cout);
	
	cout<<"the last row"<<endl;
	
	return 0;
} 
