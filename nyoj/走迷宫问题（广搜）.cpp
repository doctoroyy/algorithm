#include<iostream>
#include<queue>
#include<deque>
using namespace std;
struct node {
  int x, y;
  int pre;
};
int dir[4][2] = {
  {0,  -1},
  {-1, 0},
  {0,  1},
  {1,  0}
};
int maze[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 1, 1, 1, 0, 1, 0},
  {0, 0, 0, 0, 1, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 0, 1, 1, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 1},
  {0, 1, 0, 0, 1, 0, 0, 0},
  {0, 1, 1, 1, 1, 1, 1, 0}
};
int vis[10][10];
int valid(int x, int y) {
  if (x < 0 || x >= 8 || y < 0 || y >= 8) return false;
  return true;
}
queue<node> nodes, data;
void bfs() {
  node tmp, next;
  tmp.x = tmp.y = 0;
  nodes.push(tmp);
  data.push(tmp);
  vis[0][0] = 1;
  while (!nodes.empty()) {
    if (next.x == 7 && next.y == 7) return;
    tmp = nodes.front();
    for (int i = 0; i < 4; i++) {
      next.x = tmp.x + dir[i][0], next.y = tmp.y + dir[i][1];
      if (valid(next.x, next.y)
          && vis[next.x][next.y] == 0
          && maze[next.x][next.y] == 0) {
        
        nodes.push(next);
        data.push(next);
        vis[next.x][next.y] = 1;
      }
    }
    nodes.pop();
  }
}
int main() {
  
  bfs();

  while (!data.empty()) {
    node tmp = data.front();
    cout << "(" << tmp.x << "," << tmp.y << ")" << endl;
    data.pop();
  }
  return 0;
}

