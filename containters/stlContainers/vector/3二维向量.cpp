#include<iostream>
#include<vector>
using namespace std;

/*
输入n个整数，将他们分别除以选定的一个正整数（称为模），按余数对这些整数进行分组
例如模(modulus)为5,整数是:35,27,18,33,100,130,214
按余数分组的结果是:
余数0:35 100 130
余数1:
余数2:27
余数3:18 33
余数4:214
定义两个向量
向量v：长度为n,存储待分组的n个整数
向量vv:长度为 modulus,它是一个二维向量,元素vv[j]存储向量v中v[i]% modulus等于
j的所有v[i].
函数remainder()用向量v的每个元素v[i]除以modulus,根据余数的值，将v[i]插入向量
vv的相应元素中 
*/

void remainder(vector<int>& v,int modulus,vector<vector<int> >& vv){
	for(vector<int>::const_iterator it=v.begin();it!=v.end();it++){
		int index=(*it)%modulus;
		vv[index].push_back(*it);	//将*it添加到向量vv[index]中 
	}
}

int main(){
 	int modulus,n;
 	cout<<"输入模modulus:";cin>>modulus;
 	vector<vector<int> > vv(modulus);
 	
 	cout<<"输入要处理的整数个数:"; cin>>n;
 	vector<int> v(n);
 	
 	cout<<"请输入"<<n<<"个整数:"<<endl;
 	for(int i=0;i<n;i++)
 		cin>>v[i];
 	
 	remainder(v,modulus,vv);
 	
 	for(int i=0;i<modulus;i++){
 		cout<<"余数"<<i<<": ";
 		if(vv[i].empty())
 			cout<<endl;
 		else{
 			for(vector<int>::const_iterator it=vv[i].begin();it!=vv[i].end();it++)
 				cout<<*it<<" ";
 			cout<<endl;
 		}
 	}
 	
	
	return 0;
}
