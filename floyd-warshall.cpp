#include <iostream>
#include <fstream>
using namespace std;
const int inf = 99999;
const int maxn = 100;
const int row = 6; // ��ʾ������W��ʾ1-row�� 
int W[maxn][maxn], D[row][row], II[row][row]; // �ڽӾ��� �� dp���� �� ǰ������ 

void FLOYD_WARSHALL(){
	// W, D ����ȫ�ֱ����У�����һЩ
	int n = row - 1;
	// ��ʼ��D
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++){
			D[i][j] = W[i][j];
		}
	}
	for(int k = 0;k <= n;k++){
		// �� D �����м���
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
	// ��ʼ��W II
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
	cout << "U201911432 ����" <<endl;
	// ������·��
	for(int i = 1;i <= row-1;i++) {
		for(int j = 1;j <= row-1;j++){
			dfs(i, j);
			cout << D[i][j] << endl;
		}
	}
    return 0;
}

