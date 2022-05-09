#include <iostream>
#include <fstream>
using namespace std;
const int inf = 99999999;
// ��������ֻ��Сд��ĸ 
// ��Ϊ����ʾֻ�漰��������ĸ���������Ľڵ���Ϊ10+26=36 
const int maxn = 36;
int G[maxn][maxn];	// G[4][6] = -2 ��ʾ�ڵ�4->6��Ȩ����-2 
int dis[maxn];  // dis[4] ��ʾԴ�ڵ㵽Ŀ��ڵ�4�ľ��� 
int pre[maxn];  // pre[4] ��ʾԴ�ڵ㵽Ŀ��ڵ�����·���ϵ�ǰ���ڵ� 
char alnum[37] = "0123456789abcdefghijklmnopqrstuvwxyz"; // ����Ӧindexת��Ϊ��ĸ 

// ��������ַ���ת��Ϊ��Ӧ������
// ���� getIndex('4')=4, getIndex('b')=11 
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
	// ���s->j�ľ��� ���� s->i->j �ľ��룬��ô���¾��� 
	if(dis[j] > dis[i] + G[i][j]){
		dis[j] = dis[i] + G[i][j];
		pre[j] = i;
	}
}

bool BELLMAN_FORD(int s) {
	// s ��ʾԴ�ڵ�ı��
	INITIALIZE_SINGLE_SOURCE(s);
	// ��ÿһ���߽����ɳ� (ʵ������������������һ�����ɳ�������)
	for(int k = 0;k < maxn - 1;k++){
		for(int i = 0;i < maxn-1;i ++){
			for(int j = 0;j < maxn;j ++){
				if(G[i][j] != inf && dis[i] != inf)
					RELAX(i, j);
			}
		}
	}
	// ���ͼ���Ƿ����Ȩ��Ϊ��ֵ�Ļ�·
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
	// ��ʼ��Դ�ڵ㵽���нڵ�����·����inf 
	fill(G[0], G[0] + maxn * maxn, inf) ;
	for(int i = 0;i < n;i++){
		char a, b;
		int w;
		infile >> a >> b >> w;
		G[getIndex(a)][getIndex(b)] = w;
	}
	infile.close();
	cout << "U201911432 ����" <<endl;
	if(BELLMAN_FORD(s)){
		// dfs��� 
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


// �ڽӾ������ 
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
