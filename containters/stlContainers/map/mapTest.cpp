#pragma warning(disable:123)
#include<iostream>
#include<map>
#include<string>
#include<iomanip>

/*	
	<algorighm>头文件中有关于set的数学运算
	include()	如果一个有序集合是另一个有序集合的子集，返回true
	set_union()	生成两个有序集合的并集
	set_intersection()生成两个有序集合的交集
	set_difference() 生成两个有序集合的差集 

*/

using namespace std;
void readitem(map<string, int>&m);
int main(){
	map<string,int> mp;
	readitem(mp);
	int total=0;
	map<string,int>::iterator it;
	cout<<"统计结果:"<<endl;
	for(it=mp.begin();it!=mp.end();it++){
		total+=(*it).second;
		cout<<setw(12)<<(*it).first<<"\t"<<it->second<<endl;
	}
	cout<<"----------------total:"<<total<<endl;
	mp.erase(mp.begin());
	total=0;
	cout<<"after mp.erase(mp.begin()):\n";
	for(it=mp.begin();it!=mp.end();it++){
		total+=(*it).second;
		cout<<setw(12)<<(*it).first<<"\t"<<it->second<<endl;
	}
	cout<<"----------------total:"<<total<<endl;
	
	return 0;
}

void readitem(map<string,int>&mp){
	string word;
	int val;
	cout<<"读入数据：\n文具名		数量\n";
	while(cin>>word){
		cin>>val;
		mp[word]+=val;
	}
}
