#include<iostream>
#include"BSTree.hpp"
using namespace std;


int main(){
	int a[]={10,8,6,21,87,56,4,0,11,3,22,7,5,34,1,2,9};
	BSTree<int> stree;
	
	for(int i=0;i<17;++i)
		stree.insert(a[i]);
	cout<<"中序遍历序列: "<<endl; 
	stree.LDR();
	cout<<endl;
	
	cout<<boolalpha
		<<"stree.find(2):"<<stree.find(2)<<endl
		<<"stree.find(3):"<<stree.find(3)<<endl
		<<"stree.find(21):"<<stree.find(21)<<endl;
	
	stree.remove(2);
	stree.remove(3);
	stree.remove(21);
	
	cout<<"after remove 2,3,21 from stree:"<<endl;
	cout<<boolalpha
		<<"stree.find(2):"<<stree.find(2)<<endl
		<<"stree.find(3):"<<stree.find(3)<<endl
		<<"stree.find(21):"<<stree.find(21)<<endl;
	
	cout<<boolalpha
		<<"stree.find(1):"<<stree.find(1)<<endl
		<<"stree.find(22):"<<stree.find(22)<<endl
		<<"stree.find(56):"<<stree.find(56)<<endl;
	
	cout<<"stree中序遍历序列: "<<endl; 
	stree.LDR();
	cout<<endl;
	
	BSTree<int> small,big;
	stree.Split(10,small,big);
	cout<<"after stree.split(10,small,big):"<<endl;
	cout<<"stree: ";
	stree.LDR();
	cout<<"\nsmall: ";
	small.LDR();
	cout<<"\nbig: ";
	big.LDR();
	
	return 0;
}
