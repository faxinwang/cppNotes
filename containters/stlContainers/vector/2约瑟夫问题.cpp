#include<iostream>
#include<vector>
using namespace std;
/*
有n个人（序号从1到n）围成一圈，从第s个人开始从1报数,报到m的人出局，接着从下一个人开始报数,直到所有人都出列
出列的人的序号称为一个josephu排列 

*/

template<typename T>
void myjosephu(int s,int m,vector<T> &v1,vector<T> &v2)
{
	vector<T>::iterator it1=v1.begin(),it2=v2.begin();
	for(int i=1;i<s;i++)
		if(it1==v1.end()) it1=v1.begin();
	while(!v1.empty()){
		for(int i=1;i<m;i++)		//模拟报数 
			if(++it1==v1.end())
				it1=v1.begin();
		v2.insert(it2++,*it1);
		v1.erase(it1);
		//若出列者为最后一个，则下一个报数的人是第一个人 
		if(it1==v1.end()) it1=v1.begin();
	}
}


int main(){
	vector<int> L,M;
	int n,s,m,val;
	cout<<"请输入人数:"<<endl; cin>>n;
	L.reserve(n);
	M.reserve(n);
	cout<<"输入"<<n<<"个元素，用空格隔开"<<endl;
	for(int i=0;i<n;i++){
		cin>>val;
		L.push_back(val);
	} 
	cout<<"输入报数的起始位置和报数值s,m:"<<endl; cin>>s>>m;
	myjosephu(s,m,L,M);
	cout<<"\n出列顺序：\n";
	for(vector<int>::iterator it=M.begin();it!= M.end();it++)
		cout<<*it<<" ";
	
	
	return 0;
}


