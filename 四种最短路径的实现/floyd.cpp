#include<iostream>
#include<vector>
using namespace std;
const int &INF=100000000;
void floyd(vector<vector<int> > &distmap,//可被更新的邻接矩阵，更新后不能确定原有边
		   vector<vector<int> > &path)//路径上到达该点的中转点
//福利：这个函数没有用除INF外的任何全局量，可以直接复制！
{
	const int &NODE=distmap.size();//用邻接矩阵的大小传递顶点个数，减少参数传递
	path.assign(NODE,vector<int>(NODE,-1));//初始化路径数组 
	for(int k=1; k!=NODE; ++k)//对于每一个中转点
		for(int i=0; i!=NODE; ++i)//枚举源点
			for(int j=0; j!=NODE; ++j)//枚举终点
				if(distmap[i][j]>distmap[i][k]+distmap[k][j])//不满足三角不等式
				{
					distmap[i][j]=distmap[i][k]+distmap[k][j];//更新
					path[i][j]=k;//记录路径
				}
}
void print(const int &beg,const int &end, const vector<vector<int> > &path)//传引用，避免拷贝，不占用内存空间
{
	if(path[beg][end]>=0)
	{
		print(beg,path[beg][end],path);
		print(path[beg][end],end,path);
	}
	else cout<<"->"<<end;
}

void insert(int a, int b, vector<vector<int> > &distmap) {
	int m_distance = rand() % 5 + 1;
	cout<<"第"<< 5 <<"条边的起点、终点、长度：" << a << " " << b << " " << m_distance << endl;
	distmap[a][b] = m_distance;
}

int main()
{
	int n_num,e_num,beg,end,m_distance,p,q;//含义见下
	cout << "点数、边数为： 5, 6 " << endl;
	n_num = 5;
	e_num = 6;
	vector<vector<int> > path, 
		distmap(n_num,vector<int>(n_num,INF));//默认初始化邻接矩阵
	for(int i=0; i < 4; i++)
	{
		m_distance = rand() % 5 + 1;
		p = i + 1;
		q = p + 1;
		cout<<"第"<< i+1 <<"条边的起点、终点、长度：" << p << " " << q << " " << m_distance << endl;
		distmap[p][q] = m_distance;
	}
	insert(1, 3, distmap);
	insert(1, 4, distmap);
	
	floyd(distmap,path);
	while(cin) {
		cout<<"请输入出发点和终点：";
		cin>>beg>>end;
		cout<<"最短距离为"<< distmap[beg][end]<<"，打印路径："<< beg;
		print(beg,end,path);
		cout << endl;
	}

}
