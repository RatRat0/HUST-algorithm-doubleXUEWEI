#include <iostream>
#include <fstream>
using namespace std;
const int inf = 99999;
const int maxn = 100;
const int row = 6; // 表示矩阵在W表示1-row行 
int W[maxn][maxn], D[row][row], II[row][row]; // 邻接矩阵 和 dp矩阵 和 前驱矩阵 

void FLOYD_WARSHALL(){
	// W, D 都在全局变量中，方便一些
	int n = row - 1;
	// 初始化D
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++){
			D[i][j] = W[i][j];
		}
	}
	for(int k = 0;k <= n;k++){
		// 在 D 矩阵中计算
		if(k != 0){
			for(int i = 1; i <= n;i++) {
				for(int j = 0;j <= n;j++){
					if(D[i][j] > D[i][k] + D[k][j]){
						D[i][j] = D[i][k] + D[k][j];
						II[i][j] = k;
					}
				}
			}
		}
	}
}

void dfs(int s, int d){
	if(s == d){
		cout << d << " ";
		return ;
	}else{
		cout << s << '-';
		if(II[s][d] != s)
			dfs(II[s][d], d);
		else
			dfs(d, d);
	}
}

int main()
{
	ifstream infile("fw.in", ios::in);
    int n;
	infile >> n;
	// 初始化W II
	for(int i = 0;i < maxn;i++){
		for(int j = 0;j < maxn;j++){
			if(i == j)
				W[i][j] = 0;
			else
				W[i][j] = inf;
		}
	}
	for(int i = 0;i <= row;i++){
		for(int j = 0;j <= row;j++){
			II[i][j] = -1;
		}
	}
	for(int i = 0;i < n;i ++){
		int a, b, c;
		infile >> a >> b >> c;
		W[a][b] = c;
		II[a][b] = a;
	}
	infile.close();
	FLOYD_WARSHALL();
	cout << "U201911432 李霖" <<endl;
	// 输出最短路径
	for(int i = 1;i <= row-1;i++) {
		for(int j = 1;j <= row-1;j++){
			dfs(i, j);
			cout << D[i][j] << endl;
		}
	}
    return 0;
}

