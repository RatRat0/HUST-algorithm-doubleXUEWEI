#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<vector<int>>solution;

void dfs(int m, int row, vector<bool>&col, vector<bool>&dia1, vector<bool>&dia2, vector<int>&s){
	if(row == m){
		solution.push_back(s);
		return;
	}
	// row 是目前的行
	for(int i = 0;i < m;i++){
		// 目前的位置是row, i 
		if(col[i] == false && dia1[row + i] == false && dia2[m - 1 - row + i] == false){
			col[i] = true;
			dia1[row + i] = true;
			dia2[m - 1 - row + i] = true;
			s.push_back(i+1);
			dfs(m, row+1, col, dia1, dia2, s);
			col[i] = false;
			dia1[row + i] = false;
			dia2[m - 1 - row + i] = false;
			s.pop_back();
		}
	}
}

void QUEEN(int m){
	// 使用三个数组判断每一列，两个斜线上是否有皇后, 初始化值都为false 
	vector<vector<bool>>judge;
	vector<bool>col(m,false);
	vector<bool>dia1(2*m-1, false);
	vector<bool>dia2(2*m-1, false);
	solution.clear();
	vector<int>s; 
	dfs(m, 0, col, dia1, dia2, s);
}

int main(){
	ifstream infile("queen.in", ios::in);
	ofstream outfile("queen_U201911432.out", ios::out);
	int n;
	infile >> n;
	for(int i = 0;i < n;i++){
		int m;
		infile >> m;
		QUEEN(m);
		outfile << m << " " << solution.size() << endl;
		for(int i = 0;i < solution.size();i++){
			for(int j = 0;j < m;j++){
				outfile << solution[i][j] << ' ';
			}
			outfile << endl;
		}
	}
	infile.close();
	outfile.close();
	
	return 0;
}
