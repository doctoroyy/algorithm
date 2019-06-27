#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[13];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int ele_in_buff(int ele, vector<int> v) {//判断元素是否在容器中
  for (int i = 0; i < v.size(); i++) {
    if (ele == v[i]) return 1;
  }
  return 0;
}

void buildAjacencyList(vector<int> v[], vector<int> buff) { //建立邻接表
  for (int i = 0; i < buff.size(); i++) {
    int num = buff[i];
    int x = num / 4, y = num % 4; //根据点的序号计算坐标 
    for (int k = 0; k < 4; k++) {
      int nx = x + dir[k][0], ny = y + dir[k][1];
      if (nx < 0 || nx > 3 - 1 || ny < 0 || ny > 4 - 1) continue;
      int ele = nx * 4 + ny;//重新生成序号 
      if (ele_in_buff(ele, buff))
        v[num].push_back(ele);
    }
  }
}

int main() {
  int ans = 0;
  for (int a = 0; a < 8; a++) {
    for (int b = a + 1; b < 9; b++) {
      for (int c = b + 1; c < 10; c++) {
        for (int d = c + 1; d < 11; d++) {
          for (int e = d + 1; e < 12; e++) {
            vector<int> buff;
            buff.push_back(a);
            buff.push_back(b);
            buff.push_back(c);
            buff.push_back(d);
            buff.push_back(e);
            vector<int> v[12];
            buildAjacencyList(v, buff); //建立这5个点的邻接表

            //开始搜索
            queue<int> q;
            int vis[12] = {0};
            q.push(buff[0]);
            int tot = 0;
            vis[buff[0]] = 1;//注意第一个点也是走过的
            while (!q.empty()) {
              int k = q.front();
              q.pop();
              tot++;//记录出队操作
              for (int i = 0; i < v[k].size(); i++) {
                if (vis[v[k][i]] == 0) {
                  q.push(v[k][i]);
                  vis[v[k][i]] = 1;//走过的点记录一下
                }
              }
            }
            if (tot == 5) ans++;//如果能有5次出队，说明从第一个点出发能走完所有点
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
