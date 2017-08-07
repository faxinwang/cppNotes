#ifndef BinTree_h
#define BinTree_h

#include<iostream>
#include<cstring>
#include<queue>
#include<stack>

/*
	n 个 节点能组成的二叉树的数目为 c(2n,n)/(n+1)
	n 个 元素通过不同的进出栈顺序可以得到的排列数也为这个数字
	n+1 个矩阵相乘的方法数也是这个数字 
	类似问题:http://blog.csdn.net/jinhongdu/article/details/8065003 
*/ 


int max(int a,int b){
	return a>b?a:b;
}

template<class T>
class BinTree{
	private: 
		struct Node{
			T data;
			Node *left,*right;
			Node(const T& d,Node *l=0,Node* r=0)
			:data(d),left(l),right(r){}
		}*root;
		int n0,n1,n2;	//叶结点，1度节点，2度结点的数量 
		T noFlag,tmpdata;//空指针符号；建树时使用的临时变量，避免产生大量临时变量 
	private:
		int depth(Node* r);	//求树的深度 
		int size(Node* r);//求节点总数 
		void count(Node* r);//计算各度结点的数量 
		void dlr(Node* r);//先序遍历 
		void ldr(Node* r);//中序遍历 
		void lrd(Node* r);//后序遍历 
		void clear(Node* r);//清空结点 
		void visit(Node* r);//访问一个节点 
		Node* create();//先序建树
		Node* recover(T* dlr,T* ldr,int len);//用先序和中序恢复树 
		Node* copy(Node* r);//用于拷贝构造函数复制一颗树 
		bool Equal(const Node* a,const Node* b);//检测相等 
	public:
		BinTree(T flag):root(0),noFlag(flag){}
		BinTree():root(0){}
		BinTree(const BinTree<T> &t);//拷贝构造函数 
		~BinTree();
		void createTree();//create()驱动函数 
		void createTree(const T t);//按层序建树 
		void createTree(const T* a,int n);//用顺序数组建树
		void createTree(T* dlr,T* ldr,int len);//recover(Node*)驱动函数 
		void DLR(){dlr(root); }//dlr(Node*)驱动函数 
		void LDR(){ldr(root); }//ldr(Node*)驱动函数 
		void LRD(){lrd(root); }//lrd(Node*)驱动函数
		void NoRecInorder();//迭代中序遍历 
		void levelOrder();//层序遍历 
		int depth(){return depth(root);}//depth()包裹函数 
		int size();//size(Node* r)驱动函数 
		void countNodes();//count(Node*)包裹函数 
		int getN0(){return n0;}//获取叶结点数量 
		int getN1(){return n1;}//获取1度结点数量 
		int getN2(){return n2;}//获取2度结点数量 
		bool operator==(const BinTree& t);//检测相等 
		void rotate();//rotate(Node* rt)函数驱动 
		void rotate(Node* rt);//镜像旋转 
		
	public:
		typedef T* elem_ptr;
		Node* begin(){return root;}
		Node* end(){return 0;}
		class InorderIterator{
			public:
				InorderIterator():curNode(0){}
				Node* operator++();
				Node* operator++(int);//postfix
				void operator=(Node* r){curNode=r;}
				T operator*(){return curNode->data;}
				bool operator!=(const Node* r){return curNode!=r;}
				
			private:
				Node* next();
			private:
				std::stack<Node*> s;
				Node* curNode; 
		};
		
		
};
template<class T>
BinTree<T>::~BinTree(){
	clear(root);
}
template<class T>
void BinTree<T>::clear(Node* r){
	if(r){
		clear(r->left);
		clear(r->right);
		
		delete r;
		r=0;
	}
}
template<class T>
inline void BinTree<T>::visit(Node* r){
	std::cout<< r->data << ' ';
}
template<class T>
int BinTree<T>::depth(Node* r){
	if(r==0) return 0;
	else return max(depth(r->left),depth(r->right))+1;
}
template<class T>
int BinTree<T>::size(){
	return size(root);
}
template<class T>
int BinTree<T>::size(Node* r){
	if(r==0) return 0;
	return 1+size(r->left)+size(r->right);
}



template<class T>
void BinTree<T>::dlr(Node* r){
	if(r){
		visit(r);
		dlr(r->left);
		dlr(r->right);
	}
}

template<class T>
void BinTree<T>::ldr(Node* r){
	if(r){
		ldr(r->left);
		visit(r);
		ldr(r->right);
	}
}
template<class T>
void BinTree<T>::lrd(Node* r){
	if(r){
		lrd(r->left);
		lrd(r->right);
		visit(r);
	}
}

template<class T>
void BinTree<T>::count(Node *r){
	if(r->left && r->right){
	//	cout<<"++n2"<<endl;
		++n2;
		count(r->left);
		count(r->right);
	}else if(r->left){
	//	cout<<"++n1 left"<<endl;
		++n1;
		count(r->left);
	}else if(r->right){
	//	cout<<"++n1 right"<<endl;
		++n1;
		count(r->right);
	}else{
	//	cout<<"++n0"<<endl;
		++n0;
	}
}
template<class T>
void BinTree<T>::countNodes(){
	n0=n1=n2=0;
	count(root);
}

//用先序序列建树
template<class T>
void BinTree<T>::createTree(){
	root=create();
}
template<class T>
typename BinTree<T>::Node* BinTree<T>::create(){
	std::cin>>tmpdata;
	if(tmpdata==noFlag) return 0;
		Node* t=new Node(tmpdata);
	t->left=create();
	t->right=create();
	return t;
}

//层序建树 
template<class T>
void BinTree<T>::createTree(const T* a,int n){
	std::queue<Node*> q;
	Node* tmp;
	root = new Node(a[0]);
	q.push(root);
	for(int i=0;i<n && !q.empty();){
		tmp=q.front();
		q.pop();
		
		//如果当前结点的父节点为空，那么当前结点也是空节点，往后找父结点非空的结点 
		if( a[++i] == noFlag )
			while(a[(i-1)/2]==noFlag && i<n) ++i;
		if(a[i] != noFlag && i<n )//i<n
			q.push(tmp->left=new Node(a[i]));
			
		//如果当前结点的父节点为空，那么当前结点也是空节点，往后找父结点非空的结点 
		if( a[++i] == noFlag )
			while(a[(i-1)/2]==noFlag && i<n) ++i;
		if(a[i] != noFlag && i<n )//i<n 
			q.push(tmp->right=new Node(a[i]));
	}
}

//用先序和中序恢复一颗二叉树
template<class T> 
void BinTree<T>::createTree(T* dlr,T* ldr,int len){
	root=recover(dlr,ldr,len);
}
template<class T>
typename BinTree<T>::Node* BinTree<T>::recover(T* dlr,T* ldr,int len){
	
	if(len<=0) return 0;
	Node* rt = new Node(dlr[0]);
	T *p,*q;
	int i;
	for(i=0;ldr[i]!=dlr[0]&& i<len;++i);
	p=dlr+1;	//确定左子树的先序序列指针 
	q=ldr;		//确定左子树的中序序列指针 
	rt->left=recover(p,q,i);//递归构建左子树
	
	p=dlr+i+1; 	//确定右子树的先序序列指针
	q=ldr+i+1;	//确定右子树的中序序列指针
	rt->right=recover(p,q,len-i-1);//递归构建右子树
	return rt;
}

//按层序建树 
template<class T>
void BinTree<T>::createTree(T flag){
	using namespace std;
	queue<Node*> que;
	Node* tmp;
	T x,ldata,rdata;
	//创建树，输入flag表中空 
	std::cout<<"输入根节点:";
	std::cin>>x;
	root=new Node(x);
	que.push(root);
	while(!que.empty()){
		tmp=que.front();
		que.pop();
		std::cout<<"\n输入"<<tmp->data<<"的两个儿子("<<flag<<"表示空节点):"; 
		std::cin>>ldata>>rdata;
		if(ldata!=flag)
			que.push(tmp->left=new Node(ldata));
		if(rdata!=flag)
			que.push(tmp->right=new Node(rdata));
	}
	std::cout<<"create completed!"<<std::endl;
}

//copy constructor
template<class T>
BinTree<T>::BinTree(const BinTree<T>& t){
	noFlag=t.noFlag;
	root=copy(t.root);
}
template<class T>
typename BinTree<T>::Node* BinTree<T>::copy(Node* oldTree){
	if(oldTree==0)return 0;
	return new Node(oldTree->data,
					copy(oldTree->left),
					copy(oldTree->right));
} 

// test equalence
template<class T>
bool BinTree<T>::operator==(const BinTree<T>& t){
	return Equal(root,t.root);
}
template<class T>
bool BinTree<T>::Equal(const Node* a,const Node* b){
	if(!a && !b) return true;				//both a and b are 0
	return ( a && b							//both a adn b are non-zero
			&& (a->data == b->data)			//data is the same
			&& Equal(a->left,b->left)		//left subtree equal
			&& Equal(a->right,b->right));	//right subtree equal
}
//二叉树的层序遍历 
template<class T>
void BinTree<T>::levelOrder(){
	std::queue<Node*> q;
	Node* curNode=root;
	while(curNode){
		visit(curNode);
		if(curNode->left) q.push(curNode->left);
		if(curNode->right) q.push(curNode->right);
		if(q.empty()) return ;
		curNode=q.front();
		q.pop();
	}
}

//迭代中序遍历 
template<class T> 
void BinTree<T>::NoRecInorder(){
	//Norecursive inorder traversal using a stack
	std::stack<Node*> s;
	Node* curNode=root;
	while(1){
		while(curNode){
			s.push(curNode);
			curNode=curNode->left;
		}
		if(s.empty())return;
		curNode = s.top();
		s.pop();
		visit(curNode);
		curNode=curNode->right;
	}
}

//镜像旋转驱动函数 
template<class T> 
void BinTree<T>::rotate(){
	rotate(root);
}
//镜像旋转函数 
template<class T>
void BinTree<T>::rotate(Node* rt){
	if(rt){
		rotate(rt->left);//镜像旋转左子树 
		rotate(rt->right);//镜像旋转右子树
		
		Node* tmp=rt->left;
		rt->left = rt->right;
		rt->right = tmp;
	}
}

//中序遍历迭代器的Next()函数
template<class T> 
typename BinTree<T>::Node* BinTree<T>::InorderIterator::next(){
	while(curNode){
		s.push(curNode);
		curNode=curNode->left;
	}
	if(s.empty()) return 0;
	curNode=s.top();
	s.pop();
	Node* tmp = curNode; 
	curNode=curNode->right;
	return tmp;
}

template<class T>
typename BinTree<T>::Node* BinTree<T>::InorderIterator::operator++(){
	curNode = next();
	return curNode;
}
template<class T>
typename BinTree<T>::Node* BinTree<T>::InorderIterator::operator++(int){
	Node* tmp=curNode;
	curNode = next();
	return tmp;
}


#endif



