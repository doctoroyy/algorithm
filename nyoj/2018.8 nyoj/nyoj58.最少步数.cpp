#include<iostream>
using namespace std;
int x1, y1, x2, y2, min_steps;
int dir[4][4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int maze[9][9] = {
  1,1,1,1,1,1,1,1,1,
  1,0,0,1,0,0,1,0,1,
  1,0,0,1,1,0,0,0,1,
  1,0,1,0,1,1,0,1,1,
  1,0,0,0,0,1,0,0,1,
  1,1,0,1,0,1,0,0,1,
  1,1,0,1,0,1,0,0,1,
  1,1,0,1,0,0,0,0,1,
  1,1,1,1,1,1,1,1,1
};
void dfs(int x, int y, int steps) {
  if (maze[x][y] == 1) return;
  if (x == x2 && y == y2) {
    if (steps < min_steps) min_steps = steps;
    return;
  }
  for (int i = 0; i < 4; i++) {
    maze[x][y] = 1;
    dfs(x + dir[i][0], y + dir[i][1], steps + 1);
    maze[x][y] = 0;
  }
}
int main() {
  int runs;
  cin >> runs;
  while (runs--) {
    cin >> x1 >> y1 >> x2 >> y2;
    min_steps = 1e9 + 10;
    dfs(x1, y1, 0);
    cout << min_steps << endl;
  }
  return 0;
}
