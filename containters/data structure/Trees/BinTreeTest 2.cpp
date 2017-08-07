#include<iostream>
#include"BinTree.hpp"
using namespace std;



int main(){
	BinTree<char> tree1;
	tree1.createTree('#');
	cout<<"tree1.height():"<<tree1.depth()<<endl;
	cout<<"tree1.size():"<<tree1.size()<<endl;
	cout<<"DLR order:";
	tree1.DLR();
	cout<<"\nLDR order:";
	tree1.LDR();
	cout<<"\nLRD order:";
	tree1.LRD();
	cout<<endl;
	
	BinTree<char> tree2(tree1);
	cout<<"\ntree2.height():"<<tree2.depth()<<endl;
	cout<<"tree2.size():"<<tree2.size()<<endl;
	cout<<"DLR order:";
	tree2.DLR();
	cout<<"\nLDR order:";
	tree2.LDR();
	cout<<"\nLRD order:";
	tree2.LRD();
	cout<<endl;
	
	cout<<boolalpha<<"tree1==tree2:"<<(tree1==tree2)<<endl;
	
	cout<<"tree2 Level Order:";
	tree2.levelOrder();
	
	cout<<"\ntree2 NoRecInordre:";
	tree2.NoRecInorder();
	

	cout<<"\nIterate Tree with Iterator:";
	BinTree<char>::InorderIterator pos;
	for(pos=tree2.begin();pos!=tree2.end();++pos){
		cout<<*pos<<' ';
	}
	cout<<endl;
	
	return 0;
} 
