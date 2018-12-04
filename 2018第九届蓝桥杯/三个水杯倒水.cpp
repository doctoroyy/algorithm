/*
*@author doctoroyy
*@param V[3] 水杯容量
*@param E[3] 水杯目标状态
*@param vis[maxn][maxn][maxn] 节点访问状态
*@param node 包括三只水杯，倒水次数
*@param bottle 包含容量、当前水量
*/
#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn = 100;
int vis[maxn][maxn][maxn];
int V[3], E[3];
struct bottle {
  int capacity;
  int water;
};
struct node {
  bottle b[3];
  int step;
};
//模拟倒水(水杯i往水杯j倒水)
int pour(int i, int j, node &head) {
  if (head.b[i].water > 0 && head.b[j].water < head.b[j].capacity) {
    if (head.b[i].water <= head.b[j].capacity - head.b[j].water) {
      head.b[j].water += head.b[i].water;
      head.b[i].water = 0;
    } else {
      head.b[i].water -= head.b[j].capacity - head.b[j].water;
      head.b[j].water = head.b[j].capacity;
    }
    return 1;// 倒水成功返回状态 1
  }
  return 0;
}
int bfs() {
  queue <node> q;
  node root;
  for (int i = 0; i < 3; i++) {
    root.b[i].capacity = V[i];
    root.b[i].water = 0;
  }
  root.b[0].water = V[0];
  root.step = 0;
  q.push(root);
  vis[root.b[0].water][root.b[1].water][root.b[2].water] = 1;
  while (!q.empty()) {
    node head = q.front();
    q.pop();
    if (head.b[0].water == E[0] && head.b[1].water == E[1] && head.b[2].water == E[2]) {
      return head.step;
    }
    for (int i = 0; i < 2; i++) {
      for (int j = 1; j < 3; j++) {
        if (i == j) continue;
        node h1 = head, h2 = head;
        if (pour(i, j, h1)) {
          if (!vis[h1.b[0].water][h1.b[1].water][h1.b[2].water]) {
            h1.step = head.step + 1;
            q.push(h1);
            vis[h1.b[0].water][h1.b[1].water][h1.b[2].water] = 1;
          }
        }
        if (pour(j, i, h2)) {
          if (!vis[h2.b[0].water][h2.b[1].water][h2.b[2].water]) {
            h2.step = head.step + 1;
            q.push(h2);
            vis[h2.b[0].water][h2.b[1].water][h2.b[2].water] = 1;
          }
        }
      }
    }
  }
  return -1;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < 3; i++) scanf("%d", &V[i]);
    for (int j = 0; j < 3; j++) scanf("%d", &E[j]);
    printf("%d\n", bfs());
  }
}
