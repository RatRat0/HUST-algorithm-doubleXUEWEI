#include <iostream>
#include <fstream>
using namespace std;
const int inf = 99999999;
// 假设输入只有小写字母 
// 因为结点表示只涉及数字与字母，所以最大的节点数为10+26=36 
const int maxn = 36;
int G[maxn][maxn];	// G[4][6] = -2 表示节点4->6的权重是-2 
int dis[maxn];  // dis[4] 表示源节点到目标节点4的距离 
int pre[maxn];  // pre[4] 表示源节点到目标节点的最短路径上的前驱节点 
char alnum[37] = "0123456789abcdefghijklmnopqrstuvwxyz"; // 将对应index转换为字母 

// 将输入的字符串转换为对应的索引
// 比如 getIndex('4')=4, getIndex('b')=11 
int getIndex(char c){
	if(c <= '9'){
		return c - '0';
	}else{
		return c - 'a' + 10;
	}
}

void INITIALIZE_SINGLE_SOURCE(int s){
	fill(dis, dis + maxn, inf);
	fill(pre, pre + maxn, -1);
	dis[s] = 0; 
}

void RELAX(int i, int j){
	// 如果s->j的距离 大于 s->i->j 的距离，那么更新距离 
	if(dis[j] > dis[i] + G[i][j]){
		dis[j] = dis[i] + G[i][j];
		pre[j] = i;
	}
}

bool BELLMAN_FORD(int s) {
	// s 表示源节点的标号
	INITIALIZE_SINGLE_SOURCE(s);
	// 对每一条边进行松弛 (实际上有两个方向，所以一条边松弛了两次)
	for(int k = 0;k < maxn - 1;k++){
		for(int i = 0;i < maxn-1;i ++){
			for(int j = 0;j < maxn;j ++){
				if(G[i][j] != inf && dis[i] != inf)
					RELAX(i, j);
			}
		}
	}
	// 检查图中是否存在权重为负值的环路
	for(int i = 0;i < maxn; i++){
		for(int j = 0;j < maxn; j++){
			if(G[i][j] != inf && dis[j] > dis[i] + G[i][j]){
				return false;
			}
		}
	}
	return true;
}

bool visit[maxn];
void dfs(int s, int d){
	if(s == d){
		cout << alnum[s];
		return ;
	}else{
		if(pre[d] == s)
			dfs(s, s);
		else{
			dfs(s, pre[d]);
		}
		cout << "-" << alnum[d];
	} 
}

int main()
{
	ifstream infile("bf.in", ios::in);
    int n;
	char source;
	infile >> n >> source;
	int s = getIndex(source);
	// 初始化源节点到所有节点的最短路径是inf 
	fill(G[0], G[0] + maxn * maxn, inf) ;
	for(int i = 0;i < n;i++){
		char a, b;
		int w;
		infile >> a >> b >> w;
		G[getIndex(a)][getIndex(b)] = w;
	}
	infile.close();
	cout << "U201911432 李霖" <<endl;
	if(BELLMAN_FORD(s)){
		// dfs输出 
		for(int i = 0;i < maxn;i++){
			if(dis[i] != inf){
				dfs(s, i);
				cout << " " << dis[i] << endl;
			}
		}
	}else{
		cout<<"No Solution!";
	}
    return 0;
}


// 邻接矩阵输出 
//	cout << " ";
//	for(int i = 0;i < 36;i++){
//		cout << " " << alnum[i];
//	}
//	cout << endl;
//	for(int i = 0;i < 36;i++){
//		cout << alnum[i];
//		for(int j = 0;j < 36;j++){
//			cout << " " << G[i][j];
//		}
//		cout << endl;
//	}
