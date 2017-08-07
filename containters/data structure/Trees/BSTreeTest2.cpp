#include<iostream>
#include"BSTree.hpp"
using namespace std;

int main(){
	int a[]={5,2,8,1,3,1,6,9};
	BSTree<int> tree,small,big;
	for(int i=0;i<8;++i){
		tree.insert(a[i]);
	}
	cout<<"tree.LDR():"; 
	tree.LDR();
	cout<<endl;
	
	tree.Split(4,small,big);
	cout<<"after tree.Split(4,small,big)"<<endl;
	cout<<"tree.LDR():";
	tree.LDR();
	cout<<"\nsamll.LDR():";
	small.LDR();
	cout<<"\nbig.LDR():";
	big.LDR();
	cout<<endl;
	
	BSTree<int> Union1;
	Union1.ThreeWayJoin(small,4,big);
	cout<<"after Union1.ThreeWayJoin(small,4,big):"; 
	cout<<"Union1.LDR():";
	Union1.LDR();
	cout<<endl;
	
	BSTree<int> Union2;
	Union2.TwoWayJoin(small,big);
	cout<<"after Union2.TwoWayJoin(small,big):"<<endl; 
	cout<<"Union2.LDR():"; 
	Union2.LDR();
	cout<<endl;
	
	return 0;
}
