#ifndef hfTree_h
#define hfTree_h

#include<string>
#include<limits>


template<class T>
class hfTree{
	private:
		struct Node{
			T data;
			int weight;
			int parent,left,right;
		}*elem;
		int length;
	public:
		struct hfCode{
			T data;
			std::string code;
		};
		hfTree(const T* dat,const int* w,int size);
		void getCode(hfCode result[]);
		~hfTree(){delete []elem;}
};

template<class T>
hfTree<T>::hfTree(const T* dat,const int* w,int size){
	using namespace std;
	const int MAX_INT=numeric_limits<int>::max();
	
	int m1,m2;//分别保存最小的权值 
	int x,y;//分别保存次小树，最小树的下标 
	 
	length=size*2;
	elem = new Node[length];
	
	//初始化数组元素 
	for(int i=size;i<length;++i){
		elem[i].data=dat[i-size];
		elem[i].weight=w[i-size];
		elem[i].parent=elem[i].left=elem[i].right=0;
	}
	//归并森林中的树 
	int i,j;
	for(i=size-1;i>0;--i){
		m1=m2=MAX_INT;
		x=y=0;
		for(j=i+1;j<length;++j)
			if(elem[j].parent==0){
				if(elem[j].weight<m1){
					m2=m1;
					m1=elem[j].weight;
					x=y;//次小树下标 
					y=j;//最小树下标 
				}else if(elem[j].weight<m2){
					m2=elem[j].weight;
					x=j;//次小树下标 
				}
			}
		elem[i].weight=m1+m2;
		elem[i].left=x;
		elem[i].right=y;
		elem[x].parent=i;
		elem[y].parent=i;
		//elem[i].parent=0;
	}
}

template<class T>
void hfTree<T>::getCode(hfCode result[]){
	int size=length/2;
	int p,s;//s是追溯过程中正在处理节点的下标，p是s的父节点下标
	for(int i=size;i<length;++i){//对每个待编码的符号 
		result[i-size].data=elem[i].data;
		result[i-size].code="";
		p=elem[i].parent;
		s=i;
		while(p){//向根追溯 
			if(elem[p].right==s)
				result[i-size].code='0'+result[i-size].code;
			else
				result[i-size].code='1'+result[i-size].code;
			s=p;
			p=elem[p].parent; 
		}
	}
}




#endif
