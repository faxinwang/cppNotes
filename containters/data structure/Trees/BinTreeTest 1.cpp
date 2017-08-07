#include<iostream>
#include"BinTree.hpp"
using namespace std;

int main(){
	BinTree<char> tree;
	char dlr[100],ldr[100];
	cin>>dlr>>ldr;
	tree.createTree(dlr,ldr,strlen(dlr));
	tree.LRD();
	
	return 0;
}
