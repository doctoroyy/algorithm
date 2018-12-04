#include<iostream>
#include<deque>

using namespace std;

struct node {
  int x, y;
};
deque<node> data;
int dir[4][2] = {
                {0,  -1},
                 {-1, 0},
                 {0,  1},
                 {1,  0}};
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

int valid(int x, int y) {
  if (x < 0 || x >= 8 || y < 0 || y >= 8) return false;
  return true;
}

int vis[10][10];
int flag;

void dfs(int x, int y) {
  if (x == 7 && y == 7) {
    while (!data.empty()) {
      node tmp = data.front();
      cout << "(" << tmp.x << "," << tmp.y << ")" << endl;
      data.pop_front();

    }

    flag = true;
    return;
  }
  if (!flag) {

    for (int i = 0; i < 4; i++) {
      if (valid(x + dir[i][0], y + dir[i][1])
      && vis[x + dir[i][0]][y + dir[i][1]] == 0
      && maze[x + dir[i][0]][y + dir[i][1]] == 0) {
        vis[x + dir[i][0]][y + dir[i][1]] = 1;
        node tmp;
        tmp.x = x + dir[i][0];
        tmp.y = y + dir[i][1];
//        cout << tmp.x << " " << tmp.y << endl;
        data.push_back(tmp);
        dfs(x + dir[i][0], y + dir[i][1]);
        vis[x + dir[i][0]][y + dir[i][1]] = 0;
//        while (!data.empty())
          data.pop_back();
      }
    }
  }

}

int main() {

  flag = false;
  node tmp;
  tmp.x = tmp.y = 0;
  vis[0][0] = 1;
  data.push_back(tmp);
  dfs(0, 0);
}
