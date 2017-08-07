/*
二叉查找树也称为二叉排序树，它或者是一颗空树，或者是一颗同时满足下列条件的树：
1 若左子树不为空，则左子树中的所有元素的键值都比根节点的键值小
2 若右子树不为空，则右子树中的所有元素的键值都比根节点的键值大
3 它的左右子树叶都是一个二叉查找树
二叉查找树主要包括insert,find,delete操作
这些操作在最好情况下的时间复杂度是 O(logN)
在最坏情况下，二叉查找树退化为一个线性表，时间复杂度是O(n)
*/


#ifndef BSTree_H
#define BSTree_H

#include<iostream>

template<class T>
class BSTree{
	private:
		struct Node{
			T data;
			Node *left,*right;
			Node(const T& dat=T(),Node* l=0,Node* r=0):
				data(dat),left(l),right(r){}
		}*root,*parent;
	private:
		void insert(Node* &rt,const T& x);
		void remove(Node* rt,const T& x);
		bool find(Node* rt,const T& x)const;
		void clear(Node* &rt);
		void visit(Node* r);//访问节点 
		void LDR(Node*);//中序遍历
		T getTop();//获取根节点的数据 
	public:
		BSTree():root(0){}
		~BSTree(){clear();}
		bool find(const T& x)const;
		void insert(const T& x);
		void remove(const T& x);
		void clear();
		bool empty(){return root==0;}
		void LDR(){LDR(root);};
		void operator=(const BSTree<T>& t);
		
		void ThreeWayJoin(const BSTree<T>& small,T mid,const BSTree<T>& big);
		void TwoWayJoin(BSTree<T>& small,BSTree<T>& big);
		void Split(T mid,BSTree<T>& small,BSTree<T>& big);
		
};

template<class T>
void BSTree<T>::operator=(const BSTree<T>& t){
	parent=root=t.root;
}
//三路合并 
template<class T>
void BSTree<T>::ThreeWayJoin(const BSTree<T>& small,T mid,const BSTree<T>& big){
	clear();
	root=new Node(mid,small.root,big.root);
}
template<class T>
T BSTree<T>::getTop(){
	if(empty()){
		throw "Int getTop : root==0 error!";
	}else{
		return root->data;
	}
}
//二路合并 
template<class T>
void BSTree<T>::TwoWayJoin(BSTree<T>& small,BSTree<T>& big){
	clear();
	T mid = big.getTop();
	big.remove(mid);
	root = new Node(mid,small.root,big.root);
}
template<class T>
void BSTree<T>::Split(T mid,BSTree<T>& small,BSTree<T>& big){
	//split the binary search tree with respect to key k
	if(!root){
		small.root=big.root=0;
		return;
	}
	//create header nodes for small and big
	Node *sHead=new Node(),
		 *s=sHead,
		 *bHead=new Node(),
		 *b=bHead,
		 *curNode=root;
		 	
	while(curNode){
		if(curNode->data >=mid ){	//add to big
			b->left = curNode;
			b=curNode;
			curNode=curNode->left;
		}else{	//add to small
			s->right=curNode;
			s=curNode;
			curNode=curNode->right;
		}
	}
		
	s->right = b->left = 0;
	
	small.root = sHead->right;
	delete sHead;
	big.root = bHead->left;
	delete bHead;
	
	return ;
}


template<class T>
void BSTree<T>::clear(){
	clear(root);
}

template<class T>
void BSTree<T>::visit(Node* r){
	std::cout<< r->data <<' '; 
}

template<class T>
void BSTree<T>::clear(Node* &rt){
	if(rt->left != 0)
		clear(rt->left);
	if(rt->right != 0)
		clear(rt->right);
	delete rt;
	rt=0;
}

template<class T>
void BSTree<T>::LDR(Node* r){
	if(r){
		LDR(r->left);
		visit(r);
		LDR(r->right);
	}
}

template<class T>
bool BSTree<T>::find(const T& x)const{
	return find(root,x);
}
template<class T>
bool BSTree<T>::find(Node *rt,const T& x)const{
	Node* curNode=root;
	while(curNode){
		if(x < curNode->data)
			curNode=curNode->left;
		else if(x > curNode->data)
			curNode=curNode->right;
		else return true;
	}
	return false;
}

template<class T>
void BSTree<T>::insert(const T& x){
	insert(root,x);
}
template<class T>
void BSTree<T>::insert(Node* &rt,const T& x){
	if(rt==0)
		rt=new Node(x);
	else if(x < rt->data)
		insert(rt->left,x);
	else if(x > rt->data)
		insert(rt->right,x);
}

template<class T>
void BSTree<T>::remove(const T& x){
	remove(root,x);
}
/*
//删除节点的递归算法 
template<class T>
void BSTree<T>::remove(Node* rt,const T& x){
	if(rt==0) return ;
	if(rt->data != x)
		parent=rt;
	if(x < rt->data)//目标在左子树中 
		remove(rt->left,x);
	else if(x > rt->data)//目标在右子树中 
		remove(rt->right,x);
	else if(rt->left && rt->right){//被删除的节点有两个儿子 
		Node* tmp=rt->right;//在目标的右子树中寻找替身 
		while(tmp->left) tmp=tmp->left;
		rt->data=tmp->data;
		remove(rt->right,tmp->data);//删除替身 
	}else if(rt->left){//被删除的节点只有一个左儿子 
		if(parent->left==rt)
			parent->left=rt->left;
		if(parent->right==rt)
			parent->right=rt->left;
		delete rt;
	}else if(rt->right){//被删除的节点只有一个右儿子 
		if(parent->left==rt)
			parent->left=rt->right;
		if(parent->right==rt)
			parent->right=rt->right;
		delete rt;
	}else{//被删除的节点是叶节点，直接删除 
		if(parent->left==rt)
			parent->left=0;
		else
			parent->right=0; 
		delete rt;
	}
}
*/

//删除节点的非递归算法 
template<class T>
void BSTree<T>::remove(Node* curNode,const T& x){
	Node* p=curNode;
	 
	//若被删节点不是第一个节点，p指向被删除节点的上一个节点 
	while(curNode && curNode->data != x){
		p=curNode;
		curNode=(x < curNode->data)?curNode->left:curNode->right;
	}
	if(curNode==0) return;//待删除元素不存在 
	if(curNode->left && curNode->right){		//待删节点有两个儿子 
		Node* tmp=curNode->right;
		while(tmp->left){//查找替身 
			p=tmp;
			tmp=tmp->left;
		}	
		curNode->data=tmp->data;
		if(tmp->right){//替身有右子树，将上一节点指向右子树 
			p->left=tmp->right;
			delete tmp;//删除替身 
		}else{//替身是叶节点，直接删除 
			p->left=0;
			delete tmp;
		}
	}else if(curNode->left){//待删节点只有左子树 
		if(p->left==curNode)
			p->left=curNode->left;
		else
			p->right=curNode->left;
		delete curNode; 
	}else if(curNode->right){//待删节点只有右子树 
		if(p->left==curNode)
			p->left=curNode->right;
		else
			p->right=curNode->right;
		delete curNode;
	}else{//待删节点是叶节点 
		if(p->left==curNode)
			p->left=0;
		else
			p->right=0;
		delete curNode;
	} 
}





#endif 
