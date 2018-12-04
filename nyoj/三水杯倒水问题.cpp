#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
typedef struct{
  int w[4];
  int step;
}node;
int N;
int V[4], E[4];
bool visited[100][100];
void pour(int i, int k, node* next) {
  if (next->w[i] <= V[k] - next->w[k]) {
    next->w[k] += next->w[i];
    next->w[i] = 0;
  } else {
    next->w[i] -= (V[k] - next->w[k]);
    next->w[k] = V[k];
  }
  return;
}
void BFS() {
  queue<node> q;
  node start, pr;
  memset(visited, false, sizeof(visited));
  start.step = 0;
  start.w[1] = V[1];
  start.w[2] = 0;
  start.w[3] = 0;
  visited[start.w[1]][start.w[2]][start.w[3]]=true
  q.push(start);
  while (!q.empty()) {
    pr = q.front();
    q.pop();
    if (pr.w[1] == E[1] && pr.w[2] = E[2] && pr.w[3] == E[3]) {
      cout << pr.step << endl;
      return;
    }
    node next;
    for (int i = 0; i < 3; i++) {
      for (int j = 1; j < 3; j++) {
        int k = (i+j) % 3;
        next = pr;
        pour(i+1, k+1, &next);
        next.step += 1;
        if (!visited[start.w[1]][start.w[2]][start.w[3]]) {
          visited[start.w[1]][start.w[2]][start.w[3]] = true;
          q.push(next);
        }
      }
    }
  }
  cout << "-1" << endl;
  return;
}
int main() {
  cin >> N;
  while (N--) {
    cin >> V[1] >> V[2] >> V[3];
    cin >> E[1] >> E[2] >> E[3];
    BFS();
  }
  return 0;
}
