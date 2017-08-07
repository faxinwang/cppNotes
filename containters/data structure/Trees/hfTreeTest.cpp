#include<iostream>
#include<cstdlib>
#include<ctime>
#include"hfTree.hpp"
using namespace std;


int main(){
	const int N=26;
	char ch[]={"abcdefghijklmnopqrstuvwxyz"};
	int w[N];
	srand(time(0));
	for(int i=0;i<N;++i){
		w[i]=rand()%500;
	}
	hfTree<char> tree(ch,w,N);
	hfTree<char>::hfCode codes[N];
	tree.getCode(codes);
	
	for(int i=0;i<N;++i){
		cout<<codes[i].data<<"\t"<<w[i]<<"\t"<<codes[i].code<<endl;
	}
		
	return 0;
}
