#ifndef ListGraph_hpp
#define ListGraph_hpp

#include<iostream>
#include<deque>
#include<list>
#include<queue>
#include<stack>
#include<set>
#include"../DisJointSet/DisJointSet.hpp"

/*图:用链接表实现*/
template<class T>
class ListGraph{
	private:
		struct EdgeNode{
			int beg;
			int end;
			double weight;
			EdgeNode(int s,int e,int w):beg(s),end(e),weight(w){}
			//这里必须使用weight<=e.weight，否则当weight==e.weight时边e不会被
			//放入到结合中(因为集合使用!(a<b) && !(b<a)来判断相等) 
			bool operator<(const EdgeNode& e)const{return weight<=e.weight;}
			bool operator==(const EdgeNode& e)const{
				return (beg==e.beg && end==e.end && weight==e.weight);
			}
		};
		std::deque<std::list<EdgeNode>* > array;
		std::deque<T> nodes;
		int NumNode;
		bool oriented;
	public:
		ListGraph(int size,T* v,bool orient=false);
		~ListGraph();
		void add_node(T nd);//添加结点 
		void add_edge(int u,int v,double w=0);//添加边 
		void del_edge(int u,int v);//删除边 
		bool exist_edge(int u,int v);//边(u,v)是否存在 
		double get_weight(int u,int v);//获取边(u,v)的权 
		int in_degree(int u);//结点u的入度 
		int out_degree(int u);//结点u的出度 
		int degree(int u);//结点u的度 
		bool is_oriented()const{return oriented;}//是否为有向图 
		int get_vertex(){return NumNode;}//获取结点数量 
		
		void DFS();//深度优先搜索 
		void BFS();//广度优先搜索 
		double min_span_tree_kurskal();//最小生成树 kurskal算法 
		double min_span_tree_prim();//最小生成树prim算法
		void TopoSort();//拓扑排序 
		//计算从v到其他n-1个节点的最短距离存到dist中
		void ShortestPath(int v,double *dist,double infinite);
		
	private:
		void visit(int u);//访问结点数据 
		void DFS(bool *visited,int u);
		void BFS(bool* visited,int u);
		void find_indegree_for_all(int* indegree);//计算所有结点的入度存入数组 
		int choose(bool *s,double *dist);//ShortestPath()的辅助函数 
		double dist_vw(int u,int w,double infinite);//ShortestPath()辅助函数 
};

/* 构造函数 */
//size-现有的结点数 v-现有结点数组, orient-false无向，true有向 
template<class T>
ListGraph<T>::ListGraph(int size,T* v,bool orient)
:NumNode(size),oriented(orient){
	//空出第一个位置
	nodes.push_back(T());
	for(int i=0;i<size;++i){
		nodes.push_back(v[i]);
	}
	//添加了size+1个元素,空出第一个位置
	for(int i=0;i<=size;++i){
		array.push_back(new std::list<EdgeNode>);
	}
}
/*析构函数*/ 
template<class T>
ListGraph<T>::~ListGraph(){
	for(int i=0;i<=NumNode;++i)
		delete array[i];
}
/*添加结点*/
template<class T>
void ListGraph<T>::add_node(T nd){
	++NumNode;
	nodes.push_back(nd);
	array.push_back(new std::list<EdgeNode>);
}
/*边(u,v)是否存在*/ 
template<class T>
bool ListGraph<T>::exist_edge(int u,int v){
	if(u<1 || u>NumNode || v<1 || v>NumNode ){
		std::cout<<"Node not exist."<<std::endl;
		return false;
	}
	//在第u个链表中寻找以v为终点的边节点 
	typename std::list<EdgeNode>::iterator pos;
	for(pos=array[u]->begin();pos!=array[u]->end();++pos){
		if(v == pos->end) return true;
	}
	return false;
}
/*添加边(u,v,w)*/
template<class T>
void ListGraph<T>::add_edge(int u,int v,double w){
	if(u<1 || u>NumNode || v<1 || v>NumNode ){
		std::cout<<"Node not exist."<<std::endl;
		return;
	}
	//如果边存在，不重复添加 
	if(exist_edge(u,v)){
		std::cout<<"Edge("<<u<<','<<v<<") exist."<<std::endl;
		return;
	}
	
	if(oriented){//有向图，只需添加边edge(u,v,w) 
		array[u]->push_back(EdgeNode(u,v,w));
	}else{//无向图,需要添加反向的两条边(u,v,w)和(v,u,w) 
		array[u]->push_back(EdgeNode(u,v,w));
		array[v]->push_back(EdgeNode(v,u,w));
	}
}
/*删除边(u,v,w)*/
template<class T>
void ListGraph<T>::del_edge(int u,int v){
	if(u<1 || u>NumNode || v<1 || v>NumNode ){
		std::cout<<"Node not exist."<<std::endl;
		return;
	}
	typename std::list<EdgeNode>::iterator pos;
	//有向图，只需删除从 u 到 v 的边 
	if(oriented){
		for(pos=array[u]->begin();pos!=array[u]->end();++pos){
			if(v == pos->end)
				array[u]->erase(pos);
		}
	//无向图，需要删除两个边节点 
	}else{
		//删除 u 中的以 v 为终点的边 
		for(pos=array[u]->begin();pos!=array[u]->end();++pos){
			if(v == pos->end){
				array[u]->erase(pos);
				break;
			}
		}
		//删除 v 中的以 u 为终点的边
		for(pos=array[v]->begin();pos!=array[v]->end();++pos){
			if(u == pos->end){
				array[v]->erase(pos);
				break;
			}
		}
	}
}
/*获取边(u,v)的权，边不存在则返回0*/
template<class T>
double ListGraph<T>::get_weight(int u,int v){
	typename std::list<EdgeNode>::iterator pos;
	for(pos=array[u]->begin();pos!=array[u]->end();++pos){
		if(v == pos->end)
			return pos->weight;
	}
	return 0;
}
/*结点u的入度 */ 
template<class T>
int ListGraph<T>::in_degree(int u){
	if(u<1 || u>NumNode){
		std::cout<<"Node not exist."<<std::endl;
		return -1;
	}
	
	//在所有边结点中寻找以u为终点的边 
	int d=0;
	for(int i=1;i<=NumNode;++i){
		typename std::list<EdgeNode>::iterator pos;
		for(pos=array[i]->begin(); pos!=array[i]->end();++pos){
			if(pos->end == u) ++d;
		}
	}
	return d;
}
/*结点的出度*/ 
template<class T>
int ListGraph<T>::out_degree(int u){
	if(u<1 || u>NumNode ){
		std::cout<<"Node not exist."<<std::endl;
		return -1;
	}
	
	return array[u]->size();
}
/*结点的度=入度+出度*/ 
template<class T>
int ListGraph<T>::degree(int u){
	int d = in_degree(u) + out_degree(u);
	//如果是无向图，则计算中有重复 
	return oriented? d:d/2;
}
/*访问结点u的数据*/
template<class T>
void ListGraph<T>::visit(int u){
	if(u<1 || u>NumNode) return;
	std::cout<<nodes[u]<<' ';
}

/*深度优先搜索驱动*/
template<class T>
void ListGraph<T>::DFS(){
	bool visited[NumNode+1];
	std::fill(visited,visited+NumNode+1,false);
	
	for(int u=1;u<=NumNode;++u){
		if(!visited[u]){
			DFS(visited,u);
			printf("\n");
		}
	}
}
/*深度优先搜索*/
template<class T>
void ListGraph<T>::DFS(bool *visited,int u){
	visited[u]=true;
	visit(u);
	typename std::list<EdgeNode>::iterator pos;
	for(pos=array[u]->begin(); pos!=array[u]->end(); ++pos){
		if(!visited[pos->end])
			DFS(visited,pos->end);
	}
}

/*广度优先搜索驱动*/
template<class T>
void ListGraph<T>::BFS(){
	bool visited[NumNode+1];
	std::fill(visited,visited+NumNode+1,false);
	
	for(int u=1;u<=NumNode;++u){
		if(!visited[u]){
			BFS(visited,u);
			printf("\n");
		}
	}
}
/*广度优先搜索*/
template<class T>
void ListGraph<T>::BFS(bool* visited,int u){
	visited[u]=true;
	visit(u);
	std::queue<int> q;
	q.push(u);
	while(!q.empty()){
		u=q.front();
		q.pop();
		//for all u's adjacent vertex
		typename std::list<EdgeNode>::iterator pos;
		for(pos=array[u]->begin(); pos!=array[u]->end(); ++pos){
			if(!visited[pos->end]){
				visited[pos->end]=true;
				visit(pos->end);
				q.push(pos->end);
			}
		}
	}
}

/*kurskal（克鲁斯卡尔）算法找最小生成树*/
/*
可以将kurskal算法形式化地描述为：设G=(V,E)是一个加权无向连通图，F=(v,e)是正在
构造中的生成树，初始状态下，F 的边集为空，v=V. 图的n个顶点就是n课独立的树。即
这个生成森林包含了n棵只有n棵根结点的树，没有边。然后在E中选择一条权值最小的边，
并把它从E中删除。如果在F中加入这条边不会引起回路，即这条边的两个顶点属于森林中
不同的树，则将其加入到F中，这样，这两棵树就归并成了一颗树。重复上述过程，直到
选择了n-1条边，此时F中只剩下一棵树，这棵树就是最小生成树。 
*/
template<class T>
double ListGraph<T>::min_span_tree_kurskal(){
	using namespace std;
	int used_edge=NumNode-1;//总共需要n-1条边(n为顶点数) 
	double min_span=0; 
	set<EdgeNode> edgeSet;
	//将所有边节点放入set集合中
	for(int i=1;i<=NumNode;++i){
		typename list<EdgeNode>::iterator pos;
		for(pos=array[i]->begin(); pos!=array[i]->end(); ++pos){
			edgeSet.insert(EdgeNode(pos->beg,pos->end,pos->weight));
		}
	}
//	cout<<"edgeSet.size():"<<edgeSet.size()<<endl;
	DisJointSet djs(NumNode+1);//数组大小应为NumNode+1,因为elem[NumNode]会被使用 
	typename set<EdgeNode>::iterator pos=edgeSet.begin();
	cout<<"最小生成树使用到的边:"<<endl;
	while(used_edge){
		int u=djs.Find(pos->beg);
		int v=djs.Find(pos->end);
		if(u!=v){//加入边(u,v)不会形成回路 
			djs.Union(u,v);
			min_span += pos->weight;
			--used_edge;
			cout<<"( "<<nodes[pos->beg]
					 <<" , "<<nodes[pos->end]
					 <<" , "<<pos->weight
					 <<" )"<<endl; 
		}
		++pos;
	}
	return min_span;
}

/*prim（普里姆）算法找最小生成树*/
/*
prim算法性能比kurskal性能差，其迭代次数比kurskal(线性时间)多

*/
template<class T>
double ListGraph<T>::min_span_tree_prim(){
	using namespace std;
	double min_span=0;
	set<int> nodeSet;//保存已在生成树中的节点 
	set<EdgeNode> edgeSet;
	//将所有边节点放入edgeset集合中
	for(int i=1;i<=NumNode;++i){
		typename list<EdgeNode>::iterator pos;
		for(pos=array[i]->begin(); pos!=array[i]->end(); ++pos){
			edgeSet.insert(EdgeNode(pos->beg,pos->end,pos->weight));
		}
	}
//	cout<<"edgeSet.size():"<<edgeSet.size()<<endl;

	typename set<EdgeNode>::iterator pos = edgeSet.begin();
	//先将任意一个顶点加入到生成树点集中 
	nodeSet.insert(pos->beg);
	//一直到生成树中有n个节点 
	while(nodeSet.size()<NumNode){
		int u,v;
		//每次加入一个顶点到生成树中后，都要从头开始在所有的边中寻找权值最小
		//并且只有其中一个顶点在生成树中的边，并将不在生成树中的另一个顶点加入到生成树中 
		for(pos = edgeSet.begin(); pos != edgeSet.end(); ++pos){
			u = pos->beg;
			v = pos->end;
			//如果u在最小生成树中，并且v不在最小生成树中，则将v加入到最小生成树中 
			if(nodeSet.find(u)!=nodeSet.end()&& nodeSet.find(v)==nodeSet.end()){
				nodeSet.insert(v);//将v加入到生成树中 
				min_span += pos->weight;
				cout<<"( "<<nodes[u]
					<<" , "<<nodes[v]
					<<" , "<<pos->weight
					<<" )"<<endl;
					break;
			//注意这里的 break 不能漏掉，因为每次加入一个顶点后生成树都改变了
			//必须重现找符合条件的权值最小的边 
			}
		}
	}
	return min_span;
}

//拓扑排序 
/*
算法思想: 
1-首先求出各顶点的入度，并将入度为0的顶点入栈
2-只要栈不为空，则重复下列处理:
  a.将栈顶点i出栈并打印
  b.将顶点i的每一个邻接点k的入度减1，如果顶点k的入度变为0，则将顶点k入栈 
*/
//计算所有顶点的入度 
template<class T>
void ListGraph<T>::find_indegree_for_all(int *indegree){
	using namespace  std;
	typename list<EdgeNode>::iterator pos;
	for(int i=1;i<=NumNode;++i)
		for(pos=array[i]->begin(); pos!=array[i]->end(); ++pos)
			++indegree[pos->end]; 
} 
template<class T>
void ListGraph<T>::TopoSort(){
	using namespace std;
	if(oriented==false){
		cout<<"无向图不能做拓扑排序!"<<endl;
		return ;
	}
	stack<int> s;
	int indegree[NumNode+1];
	//indegree数组必须全部初始化为0 
	for(int i=1;i<=NumNode;++i) indegree[i]=0;
	int cur,count=0;
	//indegree[i]保存第i个顶点的入度
	find_indegree_for_all(indegree);
	for(int i=1;i<=NumNode;++i){
		if(indegree[i]==0)
			s.push(i);//将入度为0的结点入栈 
	}
	typename list<EdgeNode>::iterator pos;
	while(!s.empty()){
		cur = s.top();
		s.pop();
		++count;
		cout<<nodes[cur]<<' ';//将出栈的结点输出 
		//将所有与cur相连的结点的入度减1 
		for(pos=array[cur]->begin(); pos!=array[cur]->end(); ++pos){
			if(--indegree[pos->end] == 0)
				s.push(pos->end);//将入度变为0的结点入栈 
		}
	}
	if(count!=NumNode){
		cout<<"图中存在回路!"<<endl; 
	}
}

/*
ShortestPath()的辅助函数 
寻找不在s中的且dist[u]最小的u并返回 
s为已经正确计算出到定点u的最短距离的点的集合 
*/ 

template<class T>
int ListGraph<T>::choose(bool* s,double *dist){
	int min=0,i;
	//找到一个不在s中的顶点赋给min 
	for(i=1;i<=NumNode;++i)
		if(s[i]==false){
			min=i;
			break;
		}
	//将min更新为s[i]=false && dist[i]最小 的i 
	for(++i;i<=NumNode;++i){
		if(s[i]==false && dist[min] > dist[i])
			min=i;
	}
	return min;
}
//取得顶点uw之间的距离,如果uw之间没有边，则返回参数infinite 
template<class T>
double ListGraph<T>::dist_vw(int v,int w,double infinite){
	typename std::list<EdgeNode>::iterator pos;
	for(pos=array[v]->begin(); pos!=array[v]->end(); ++pos)
		if(pos->end == w)
			return pos->weight;
	return infinite;
}
/*
参数infinite表示一个比所有边权都大很多的数，但要保证在与边权相加时不
发生溢出 
*/
template<class T>
void ListGraph<T>::ShortestPath(int u,double *dist,double infinite){
	//dist[j] (1<= j < n) is set to the length of the shortest path from v to j	
	using namespace std;
	bool s[NumNode+1];
	//将s的元素都初始化为false 
	fill(s,s+NumNode+1,false);
	//初始化dist的元素为各结点与u之间的边权 
	typename list<EdgeNode>::iterator pos;
	for(pos=array[u]->begin();pos!=array[u]->end();++pos)
		dist[pos->end] = pos->weight;
	//将u加入s中 
	s[u] = true;
	dist[u] = 0;
	
	for(int i=1; i < NumNode ; ++i){//determine n-1 paths from vertex v
		int v=choose(s,dist);	//min_dist returns a value v such that:
								//dist[v] = minimum dist[i] where s[i]=false
		s[v] = true;
		//upate the dist between u and w where s[w] = false
		for(int w=1;w<=NumNode; ++w){
			double distvw = dist_vw(v,w,infinite);
			if(!s[w] && dist[v]+ distvw < dist[w])
				dist[w]=dist[v]+ distvw; 
		}
	}
}



#endif 
