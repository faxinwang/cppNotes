#ifndef PriorityQueue_h
#define PriorityQueue_h

template<class T>
class PriorityQueue{
	private:
		int currSize;
		int capacity;
		T* elem;
	private:
		void doubleSpace();
		void buildHeap();
		void percolateDown(int hole);//向下渗透 
	public:
		PriorityQueue(int cap=100):capacity(cap),currSize(0){
			elem=new T[capacity];
		}
		PriorityQueue(const T* dat,int size);
		~PriorityQueue(){delete []elem;}
		
		bool empty(){return !currSize;}
		void enQueue(const T& x);
		T deQueue();
		T getHead()const{return elem[1];}
};

template<class T>
void PriorityQueue<T>::enQueue(const T& x){
	if(currSize==capacity) doubleSpace();
	//向上过滤
	int hole=++currSize;
	for(;hole>1 && x < elem[hole/2];hole/=2){
		elem[hole]=elem[hole/2];
	}
	elem[hole]=x;
}
template<class T>
T PriorityQueue<T>::deQueue(){
	T data=elem[1];//elem[1]为第一个元素，elem[0]未使用 
	elem[1]=elem[currSize--];
	percolateDown(1);//参数为空节点的位置
	return data; 
}
template<class T>
void PriorityQueue<T>::percolateDown(int hole){
	int child;
	T tmp=elem[hole];
	for(;hole*2<=currSize;hole=child){
		child=hole*2;
		if(child+1 <= currSize && elem[child] > elem[child+1])
			++child;//使child指向子节点中较小的一个
		if(elem[child]<tmp)
			elem[hole]=elem[child];
		else
			break;
	}
	elem[hole]=tmp;
}
template<class T>
void PriorityQueue<T>::buildHeap(){
	//从第一个非叶节点开始调整元素，建立堆的有序性 
	for(int i=currSize/2;i>0;--i){
		percolateDown(i);
	}
}
template<class T>
PriorityQueue<T>::PriorityQueue(const T* dat,int size):capacity(size*2),currSize(size){
	elem=new T[capacity];
	for(int i=0;i<size;++i)
		elem[i]=dat[i];
	buildHeap();
}
template<class T>
void PriorityQueue<T> ::doubleSpace(){
	capacity*=2;
	T* tmp=new T[capacity];
	for(int i=0;i<currSize;++i)
		tmp[i]=elem[i];
	delete elem;
	elem=tmp;
}
#endif
