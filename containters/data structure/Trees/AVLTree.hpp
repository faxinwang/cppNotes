#ifndef AVLTree_h
#define AVLTree_h

template<class T>
class AVLTree{
	private:
		struct avlNode{
			T data;
			avlNode *left,*right;
			int height;
			avlNode(const T& x,avlNode* l,avlNode* r,int h=0)
			:data(x),left(l),right(r),height(h){}
		}*root;
	public:
		AVLTree():root(0){}
		~AVLTree(){clear(root);}
		bool find(const T& x)const;
		void insert(const T& x){insert(x,root);}
		void remove(const T& x){remove(x,root);}
	private:
		void insert(const T& x,avlNode* &rt);
		bool remove(const T& x,avlNode* &rt);
		void clear(avlNode* &rt);
		int height(avlNode* rt)const{return rt==0?-1:rt->height;}
		void LL(avlNode* &rt);
		void LR(avlNode* &rt);
		void RL(avlNode* &rt);
		void RR(avlNode* &rt);
		int max(int a,int b){return a>b?a:b;}
};
template<class T>
void AVLTree<T>::clear(avlNode* &rt){
	if(rt->left)
		clear(rt->left);
	if(rt->right)
		clear(rt->right);
	delete rt;
	rt=0;
}

template<class T>
bool AVLTree<T>::find(const T& x)const{
	avlNode* rt=root;
	while(rt && rt->data!=x){
		if(x < rt->data) rt=rt->left;
		else rt=rt->right;
	}
	return (rt!=0);
}

template<class T>
void AVLTree<T>::insert(const T& x,avlNode* &rt){
	if(rt==0)
		rt=new avlNode(x,0,0);
	else if(x < rt->data){
		insert(x,rt->left);
		if( height(rt->left) - height(rt->right) == 2 ){//失衡 
			if( x < rt->left->data) LL(rt);
			else LR(rt);
		}
	}
	else if( x > rt->data){
		insert(x,rt->right);
		if( height(rt->left) - height(rt->right) == 2 ){
			if(x > rt->right->data) RR(rt);
			else RL(rt);
		}
	}
	//重新计算该节点的高度 
	rt->height=max( height(rt->left) , height(rt->right) ) + 1;
}

template<class T>
void AVLTree<T>::LL(avlNode* &rt){
	avlNode* tmp = rt->left;
	rt->left = tmp->right;
	tmp->right = rt;
	rt->height = max( height(rt->left) , height(rt->right) ) + 1;
	tmp->height = max( height(tmp->left) , height(tmp->right) ) + 1;
	rt=tmp;
}
template<class T>
void AVLTree<T>::RR(avlNode* &rt){
	avlNode* tmp = rt->right;
	rt->right = tmp->left;
	tmp->left = rt;
	rt->height = max( height(rt->left) , height(rt->right) ) + 1;
	tmp->height = max( height(tmp->left) , height(tmp->right) ) + 1;
	rt=tmp;
}
template<class T>
void AVLTree<T>::LR(avlNode* &rt){
	RR(rt->left);
	LL(rt);
}
template<class T>
void AVLTree<T>::RL(avlNode* &rt){
	LL(rt->right);
	RR(rt);
}

template<class T>
bool AVLTree<T>::remove(const T& x,avlNode* &rt){
	bool stop = false;
	int subTree;//1表示删除发生在左子树上，2表示删除发生在右子树上 
	
	if(rt==0) return true;
	if( x < rt->data ){
		stop = remove( x, rt->left );
		subTree = 1;
	}else if( x > rt->data){
		stop = remove( x ,rt->right );
		subTree = 2;
	}else if( rt->left && rt->right){
		avlNode* tmp = rt->right;
		while(tmp->left) tmp=tmp->left;
		rt->data = tmp->data;
		stop = remove( tmp->data, rt->right);
		subTree = 2;
	}else{
		avlNode* old = rt;
		rt = (rt->left)?rt->left:rt->right;
		delete old;
		return false;
	}
	
	if(stop) return true;
	int bf;
	switch(subTree){
		case 1:	bf = height(rt->left) - height(rt->right) + 1;
				if( bf == 0 ) return true;
				if( bf == 1 ) return false;
				if( bf == -1 ){
					int bfr = height(rt->right->left) - height(rt->right->right);
					switch(bfr){
						case 0:	RR(rt);return true;
						case -1:RR(rt);return false;
						default:RL(rt);return false;
					}
				}
			break;
		case 2: bf = height(rt->left) - height(rt->right) - 1;
				if( bf == 0 ) return true;
				if( bf == -1 ) return false;
				if( bf == 1){
					int bfl = height(rt->right->left) - height(rt->right->right);
					switch(bfl){
						case 0:LL(rt);return true;
						case 1:LL(rt);return false;
						default:LR(rt);return false;
					}
				}
			
	}
}



#endif
