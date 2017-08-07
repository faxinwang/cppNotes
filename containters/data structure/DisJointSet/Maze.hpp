#ifndef Maze_h
#define Maze_h

#include<vector>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include"DisJointSet.hpp"


class Maze{
	private:
		struct Pair{
			int x,y;
			Pair(int a,int b):x(a),y(b){}
			Pair(){}
		};
		
		const int M,N;
		int Length;
		int **maze;
		int startX,startY,endX,endY;
		
	public:
		Maze(int m,int n,int sx,int sy,int ex,int ey):M(m),N(n),Length(M*N){
			if(sx>0 && sx<=M) startX=sx-1;
			else exit(1);
			if(sy>0 && sy<=N) startY=sy-1;
			else exit(1);
			if(ex>0 && ex<=M) endX=ex-1;
			else exit(1);
			if(ey>0 && ey<=N) endY=ey-1;
			else exit(1);
		//	printf("%d %d %d %d\n",startX,startY,endX,endY);
			maze = new int*[M];
			for(int i=0;i<M;++i)
				maze[i]=new int[N];
			init();
		}
		void createMaze();
		void show();
		void init();
		
};

void Maze::init(){
	for(int i=0;i<M;++i)
		for(int j=0;j<N;++j)
			maze[i][j]=1;
}

void Maze::createMaze(){
	using std::cout;
	using std::endl;
	
	int num1,num2;
	int start = M*startX+startY;
	int end = M*endX+endY;
	
	DisJointSet ds(Length);
	std::vector<Pair> v;
	
	srand(time(0));
	while(ds.Find(start) != ds.Find(end)){
		while(1){
			num1 = rand()%Length;
			num2=num1-M;					//检查上方单元格 
			if(num2>=0)
				if(ds.Find(start) != ds.Find(end)) break;
			num2=num1-1;					//检查左边的单元格 
			if(num2>=0)
				if(ds.Find(start) != ds.Find(end)) break;
			num2=num1+M;					//检查下边的单元格 
			if(num2<Length)
				if(ds.Find(start) != ds.Find(end)) break;
			num2=num1+1;					//检查右边的单元格 
			if(num2<N)
				if(ds.Find(start) != ds.Find(end)) break;
		}
		cout<<'<'<<num1<<','<<num2<<'>'<<endl;
		
		ds.Union(ds.Find(num1),ds.Find(num2));
		
		v.push_back(Pair(num1,num2));
 	}
 	
 //	init();
 	int x1,y1,x2,y2;
 	
 	cout<<"-----------------------------------"<<endl;
 	for(int i=0;i<v.size();++i){
 		cout<<'<'<<v[i].x<<','<<v[i].y<<'>'<<endl;
 		x1=v[i].x / N;
 		y1=v[i].x % N - 1;
 		maze[x1][y1] = 0;
 		x2=v[i].y / N;
 		y2=v[i].y % N - 1;
 		maze[x2][y2]=0;
 	}
}

void Maze::show(){
	for(int i=0;i<M;++i){
		for(int j=0;j<N;++j)
			printf("%3d",maze[i][j]);
		puts("");
	}
}




#endif
