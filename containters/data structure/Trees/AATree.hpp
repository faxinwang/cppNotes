#ifndef AATree_h
#define AATree_h

template<class T>
class AATree{
	private:
		struct AANode{
			T data;
			AANode *left,*right;
			int level;
			AANode(const T& x,AANode* l,AANode* r,int lv=1)
			:data(x),left(l),right(r),level(lv){}
		}*root;
	private:
		void insert(const T& x,AANode* &rt);
		void remove(const T& x,AANode* &rt);
		bool find(const T& x,AANode* rt)const;
		void clear(AANode *rt);
		void LL(AANode* &rt);
		void RR(AANode* &rt);
	public:
		AATree():root(0){}
		~AATree(){clear(root);}
		bool find(const T& x){return find(x,root);}
		void insert(const T& x){insert(x,root);}
		void remove(const T& x){remove(x,root);}
};

template<class T>
bool AATree<T>::find(const T& x,AANode* rt)const{
	if(rt==0)
		return false;
	else if(x < rt->data)
		return find(x,rt->left);
	else if(x > rt->data)
		return find(x,rt->right);
	else
		return true;
}

template<class T>
void AATree<T>::clear(AANode *rt){
	if(rt){
		clear(rt->left);
		clear(rt->right);
		delete rt;
		rt=0;
	}
}

template<class T>
void AATree<T>::LL(AANode* &rt){
	if(rt->left && rt->left->level == rt->level){
		AANode* tmp = rt->left;
		rt->left = tmp->right;
		tmp->right = rt;
		rt = tmp;
	}
}
template<class T>
void AATree<T>::RR(AANode* &rt){
	if(rt->right && rt->right->right){
		if(rt->right->right->level == rt->level){
			AANode* tmp = rt->right;
			rt->right = tmp->left;
			tmp->left = rt;
			rt = tmp;
			rt->level++;
		}
	}
}
template<class T>
void AATree<T>::insert(const T& x,AANode* &rt){
	if(rt==0)
		rt = new AANode(x,0,0);
	else if( x < rt->data){
		insert(x,rt->left);
	}
	else if( x > rt->data){
		insert(x, rt->right);
	}else return;
	
	LL(rt);
	RR(rt);
}

template<class T>
void AATree<T>::remove(const T& x,AANode* &rt){
	if(rt==0) return;
	if( x < rt->data) remove(x,rt->left);
	else if( x >rt->data) remove(x ,rt->right);
	else if( rt->left && rt->right){
		AANode *tmp = rt->right;
		while(tmp->left) tmp=tmp->left;
		rt->data = tmp->data;
		remove(rt->data,tmp->right);
	}else{
		AANode *old = rt;
		rt = (rt->left)?rt->left:rt->right;
		delete old;
		return;
	}
	
	LL(rt);
	if(rt->right) LL(rt->right);
	if(rt->right && rt->right->right) LL(rt->right->right);
	
	RR(rt);
	if(rt->right) RR(rt->right);
}



#endif 
