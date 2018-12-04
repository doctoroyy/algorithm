#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
ofstream fout("e:/out.txt");
int cnt = 0;
int used[10];
int visited[3][4];
int map[3][4];
int dis[8][2] = {-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};
void dfs(int index) {
	int x = index / 4, y = index % 4;
	if (index > 10+1) return;
	if (index == 10+1) {
		if (map[0][0] > 0) return;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				if (i == 0 && j == 0 || i == 2 && j == 3) continue;
				for (int k = 0; k < 8; k++) {
					x = i + dis[k][0];
					y = j + dis[k][1];
					if (x == 0 && y == 0 || x == 2 && y == 3) continue;
					if (abs(map[i][j] - map[x][y]) == 1) return;
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				fout << map[i][j] << " ";
			}
			fout << endl;
		}
		cnt++;
		fout << endl;
		return;
	}
	for (int k = 0; k < 10; k++) {
		if (x == 0 && y == 0 || x == 2 && y == 3) {
			dfs(index+1);
		}
		if (visited[x][y] == 0 && used[k] == 0) {

			map[x][y] = k;
			visited[x][y] = 1;
			used[k] = 1;
			dfs(index+1);

			visited[x][y] = 0;
			used[k] = 0;
		}
	}
}

int main() {
	dfs(0);
	cout << cnt;
}
