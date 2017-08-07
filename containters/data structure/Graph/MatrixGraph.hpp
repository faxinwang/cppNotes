#ifndef MatrixGraph_hpp
#define MatrixGraph_hpp

#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include"../DisJointSet/DisJointSet.hpp"

template<class T>
class MatrixGraph{
	private:
		//边结点,最小生成树算法使用到
		struct EdgeNode{
			int beg,end,weight;
			EdgeNode(int b,int e,int w):beg(b),end(e),weight(w){}
			bool operator<(const EdgeNode& edge)const{
				return weight<=edge.weight;
			}
		};
	private:
		int NumNode,NumEdge;
		const int NoEdge;
		std::vector<T> nodes;
		bool oriented;//true有向图,false无向图 
		std::vector<std::vector<int> > edge;
	public:
		MatrixGraph(int vSize,T* v,int NoEdgeFlag=-1,bool oriented=false);
		~MatrixGraph(){}
		void add_node(T nd);//添加一个顶点
		bool add_edge(int u,int v,int w=1);//添加一条边
		bool del_edge(int u,int v);//删除一个顶点(尚不完善,只是去掉了该顶点所有的边)
		bool exist_edge(int u,int v);//边是否存在
		int get_weight(int u,int v);//获取边权
		void print_matrix();//打印邻接矩阵
		int in_degree(int u);//求顶点的入度
		int out_degree(int u);//求顶点的出度
		int degree(int u);//求顶点的度
		bool is_oriented(){return oriented;}
		int get_vertex()const{return NumNode;};
		
		void DFS();//深度优先搜索驱动
		void BFS();//广度优先搜索驱动
		void TopoSort();//拓扑排序
		void ShortestPath(int u,double* dist);//单源最短路径
		void ShortestPathForAll(std::vector<std::vector<int> >& a);//多源最短路径
		int min_span_tree_kurskal();//最小生成树kurskal算法
		int min_span_tree_prim();//最小生成树prim算法
	private:
		void visit(int v);//访问顶点
		void DFS(bool* visited,int v);//深度优先搜索
		void BFS(bool* visited,int v);//广度优先搜索
		int choose(bool* s,double* dist);//单源最短路径辅助函数
};

//打印矩阵 
template<class T>
void MatrixGraph<T>::print_matrix() {
	for(int i=0;i<NumNode;++i){
		for(int j=0;j<NumNode;++j)
			printf("%4d ",edge[i][j]);
		printf("\n");
	}
}
//求顶点u的入度 
template<class T>
int MatrixGraph<T>::in_degree(int u){
	if(u<1 || u>NumNode) return -1;
	--u;
	int d=0;
	for(int i=0;i<NumNode;++i)
		if(edge[i][u] != NoEdge) ++d;
	return d-1;//a[i][i]==0 != NoEdge
}
//求顶点u的出度
template<class T>
int MatrixGraph<T>::out_degree(int u){
	if(u<1 || u>NumNode) return -1;
	--u;
	int d=0;
	for(int j=0;j<NumNode;++j)
		if(edge[u][j]!=NoEdge) ++d;
	return d-1;//a[i][i]==0 != NoEdge
}
//求顶点u的度
template<class T>
int MatrixGraph<T>::degree(int u){
	int d = in_degree(u)+out_degree(u);
	return oriented?d:d/2; 
}

//构造函数 
template<class T>
MatrixGraph<T>::MatrixGraph(int vSize,T* v,int NoEdgeFlag,bool oriented)
:NoEdge(NoEdgeFlag),NumNode(vSize),NumEdge(0),oriented(oriented){
	nodes.reserve(NumNode);
	for(int i=0;i<NumNode;++i)
		nodes.push_back(v[i]);
		
	edge.reserve(NumNode);
	for(int i=0;i<NumNode;++i){
		edge.push_back(std::vector<int>(NumNode));
		std::fill(edge[i].begin(),edge[i].end(),NoEdge);
		edge[i][i] = 0;
	}
}

//添加一条边 
template<class T>
bool MatrixGraph<T>::add_edge(int u,int v,int w){
	--u;--v;
	if(u<0 || u >= NumNode || v < 0 || v >= NumNode ){
		std::cout<<"Node not exist."<<std::endl;
		return false;//out of range
	} 
	if(edge[u][v]!=NoEdge){
		std::cout<<"edge("<<u<<','<<v<<") exist."<<std::endl;
		return false;//边存在 
	} 
	if(oriented){
		edge[u][v]=w;
	}else{
		edge[u][v]=edge[v][u]=w;
	}
	++NumEdge;
	return true;
}
//删除一条边 
template<class T>
bool MatrixGraph<T>::del_edge(int u,int v){
	--u;--v;
	if(u<0 || u >= NumNode || v < 0 || v >= NumNode ) return false;//out of range
	if(edge[u][v]==NoEdge) return false;//边不存在 
	if(oriented){
		edge[u][v]=NoEdge;
	}else{
		edge[u][v]=edge[v][u]=NoEdge;
	}
	--NumEdge;
	return true;
}
//检测边(u,v)是否存在 
template<class T>
bool MatrixGraph<T>::exist_edge(int u,int v){
	if(u<0 || u >= NumNode || v < 0 || v >= NumNode ) return false;//out of range
	return edge[u][v]!=NoEdge? true:false;
}
//获取边(u,v)的权值 
template<class T>
int MatrixGraph<T>::get_weight(int u,int v){
	if(u<0 || u >= NumNode || v < 0 || v >= NumNode ) return false;//out of range
//	if(edge[u][v]==NoEdge) return 0;
	return edge[u][v];
}
//添加一个顶点 
template<class T>
void MatrixGraph<T>::add_node(T nd){
	nodes.push_back(nd);
	edge.push_back(std::vector<int>());
	for(int i=0;i<NumNode;++i)
		edge[i].push_back(NoEdge);
	++NumNode;
	for(int i=0;i<NumNode;++i)
		edge[NumNode-1].push_back(NoEdge);
}
//访问节点u的数据 
template<class T>
void MatrixGraph<T>::visit(int u){
	std::cout<<nodes[u]<<' ';
}

//深度优先搜索驱动 
template<class T>
void MatrixGraph<T>::DFS(){
	bool visited[NumNode];
	std::fill(visited,visited+NumNode,false);
	
	for(int i=0;i<NumNode;++i)
		if(!visited[i]){
			DFS(visited,i);
			printf("\n");
		} 
}
//深度优先搜索
template<class T>
void MatrixGraph<T>::DFS(bool* visited,int v){
	visited[v]=true;
	visit(v);
	for(int j=0;j<NumNode;++j)
		if(!visited[j] && edge[v][j]!=NoEdge)  DFS(visited,j);
}

//广度优先搜索驱动 
template<class T> 
void MatrixGraph<T>::BFS(){
	 bool visited[NumNode];
	 std::fill(visited,visited+NumNode,false);
	 
	 for(int i=0;i<NumNode;++i)
	 	if(!visited[i]){
	 		BFS(visited,i);
	 		printf("\n");
	 	}
}
//广度优先搜索 
template<class T> 
void MatrixGraph<T>::BFS(bool* visited,int u){
	visited[u]=true;
	visit(u);
	std::queue<int> q;
	q.push(u);
	while(!q.empty()){
		u=q.front();
		q.pop();
		//for all vertices j adjacent to u
		for(int j=0;j<NumNode;++j)
			if(!visited[j] && edge[u][j]!=NoEdge){
				visited[j]=true;
				visit(j);
				q.push(j);
			}
	}
}

//拓扑排序 
/*
算法思想: 
1-首先求出各顶点的入度，并将入度为0的顶点入栈
2-只要栈不为空，则重复下列处理:
  a.将栈顶点i出栈并打印
  b.将顶点i的每一个邻接点k的入度减1，如果顶点k的入度变为0，则将顶点k入栈 
*/
template<class T>
void MatrixGraph<T>::TopoSort(){
	using namespace std; 
	if(oriented==false){
		cout<<"无向图不能做拓扑排序!"<<endl; 
		return;
	}	 
	stack<int> s;//也可以用queue 
	int count=0,cur;
	int indegree[NumNode];
	for(int i=0;i<NumNode;++i){
		indegree[i] = in_degree(i+1);//in_degree()的参数范围为[1,NumNode] 
		if(indegree[i] == 0) s.push(i);//将入度为0的顶点入栈 
	}
	while(!s.empty()){
		cur = s.top();
		s.pop();
		++count;
		cout<<nodes[cur]<<' ';
		//将与cur相连的每一个顶点入度减1 
		for(int i=0;i<NumNode;++i){
			if(edge[cur][i] != NoEdge)
				if(--indegree[i] == 0)
					s.push(i);//将入度为0的顶点入栈 
		}
	}
	if(count!=NumNode)
		cout<<"图中存在回路"<<endl; 
}


/*
求给定点u到其他各点的最短路径并存在dist中 
函数结束后 dist[i] 是u到节点 i 的最短距离 
infinity是一个比边权都大很多的数，并且在与其他边权向加的时候不会发生溢出 
*/
template<class T>
int MatrixGraph<T>::choose(bool* s,double *dist){
	int min,i;
	//找到一个不在s中的顶点赋给min 
	for(i=0;i<NumNode;++i)
		if(s[i]==false){
			min=i;
			break;
		}
	//将min更新为s[i]=false && dist[i] 最小的i 
	for(++i;i<NumNode;++i){
		if(s[i]==false && dist[min] > dist[i])
			min=i;
	}
	return min;
}

template<class T>
void MatrixGraph<T>::ShortestPath(int u,double* dist){
	--u;
	bool s[NumNode];
	for(int i=0;i<NumNode;++i){
		dist[i] = edge[u][i];
		s[i] = false;
	}
	s[u] = true;
	dist[u] = 0;
	
	for(int i=1;i<NumNode;++i){//determine n-1 paths from vertex u
		int v = choose(s,dist);	//choose returns a value v such that:
							//dist[v]=minimum dist[i] where s[i]=false
		s[v] = true;
		//更新不在s中的点到u的最短距离
		for(int w=0;w<NumNode; ++w)
			if(!s[w] && dist[v]+edge[v][w] < dist[w])
				dist[w] = dist[v] + edge[v][w];
	}
}

//求任意两个顶点间的最短距离
//多源最短路径
template<class T>
void MatrixGraph<T>::ShortestPathForAll(std::vector<std::vector<int> >& a){
	//a[i][j] is the length of the shortest path betweent i and j
	a.reserve(NumNode);
	for(int i=0;i<NumNode;++i)
		a.push_back(std::vector<int>(edge[i].begin(),edge[i].end()));
		
//	printf("copy finished!\n");
	
	for(int k=0;k<NumNode;++k)
		for(int i=0;i<NumNode;++i)
			for(int j=0;j<NumNode;++j)
				if(a[i][k] + a[k][j] < a[i][j])
					a[i][j] = a[i][k] + a[k][j];
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
int MatrixGraph<T>::min_span_tree_kurskal(){
	using namespace std;
	int min_span=0,used_edge=NumNode-1;
	set<EdgeNode> edgeSet;
	//将所有边放入edgeSet
	for(int i=0;i<NumNode;++i)
		for(int j=0;j<NumNode;++j)
			if(edge[i][j] != NoEdge && i!=j)
				edgeSet.insert(EdgeNode(i,j,edge[i][j]));
	DisJointSet djs(NumNode);//创建不相交集,NumNode个元素
	//开始遍历边结点，从中找出NumNode-1条边
	typename set<EdgeNode>::iterator pos=edgeSet.begin();
	cout<<"最小生成树使用到的边:"<<endl;
	while(used_edge){
		int u = djs.Find(pos->beg);
		int v = djs.Find(pos->end);
		if(u!=v){//u和v不在同一棵树中，即加入边(u,v)不会形成回路
			--used_edge;
			djs.Union(u,v);//合并u和v所在的树
			min_span += pos->weight;
			cout<<"( "<<nodes[pos->beg]
				<<" ,"<<nodes[pos->end]
				<<" ,"<<pos->weight
				<<" )"<<endl;
		}
		++pos;
	}
	return min_span;
}

/*
最小生成树:prim()算法
*/
template<class T>
int MatrixGraph<T>::min_span_tree_prim(){
	using namespace std;
	int min_span=0;
	set<int> nodeSet;       //存放生成树中的结点
	set<EdgeNode> edgeSet;//存放所有边结点
	//将所有边结点放入edgeSet集合中
	for(int i=0;i<NumNode;++i)
		for(int j=0;j<NumNode;++j)
			if(edge[i][j]!=NoEdge && i!=j)
				edgeSet.insert(EdgeNode(i,j,edge[i][j]));
				
	typename set<EdgeNode>::iterator pos=edgeSet.begin();
	nodeSet.insert(pos->beg);//首先随便选择一个顶点放入生成树点集中
	
	//在edgeSet中选择边权最小，且其中一个顶点不在生成树中的边
	//将不在生成树中的顶点加入到生成树中
	//直到所有的顶点都在生成树中为止
	cout<<"最小生成树用到的边:"<<endl;
	while(nodeSet.size()<NumNode){
        int u,v;
		for(pos=edgeSet.begin();pos!=edgeSet.end();++pos){
			u = pos->beg;
			v = pos->end;
			//如果一个点在生成树中，另一个点不在生成树中
	        if(nodeSet.find(u)!=nodeSet.end() && nodeSet.find(v)==nodeSet.end()){
	        	nodeSet.insert(v);
	        	min_span += pos->weight;
	        	cout<<"( "<<nodes[pos->beg]
					<<" ,"<<nodes[pos->end]
					<<" ,"<<pos->weight
					<<" )"<<endl;
				break;
				//注意这里的 break 不能漏掉，因为每次加入一个顶点后生成树都改变了
				//必须重先找符合条件的权值最小的边
	        }
		}
	}
	return min_span;
}


#endif
