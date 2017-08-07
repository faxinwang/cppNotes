#include<iostream>
#include"AATree.hpp"
using namespace std;


int main(){
	int a[]={10,8,6,21,87,56,4,0,11,3,22,7,5,34,1,2,9};
	AATree<int> stree;
	
	for(int i=0;i<17;++i)
		stree.insert(a[i]);
	
	cout<<boolalpha
		<<"find(2):"<<stree.find(2)<<endl
		<<"find(3):"<<stree.find(3)<<endl
		<<"find(21):"<<stree.find(21)<<endl;
	
	stree.remove(2);
	stree.remove(3);
	stree.remove(21);
	
	cout<<"after remove 2,3,21:"<<endl;
	cout<<boolalpha
		<<"find(2):"<<stree.find(2)<<endl
		<<"find(3):"<<stree.find(3)<<endl
		<<"find(21):"<<stree.find(21)<<endl;
	
	cout<<boolalpha
		<<"find(1):"<<stree.find(1)<<endl
		<<"find(22):"<<stree.find(22)<<endl
		<<"find(56):"<<stree.find(56)<<endl;
	
	return 0;
}
