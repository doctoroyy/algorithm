#include<iostream>
#include<map>
#include<cmath>
#include<vector>
#include<cstdio>
using namespace std;
const int maxn = 1e6 + 10;
int vis[maxn], next0[maxn];
struct node {
  int now, val, next;
} nodes[maxn];
void print(vector<node> &v) {
  for (int i = 0; i < v.size(); i++) {
    printf("%05d %d ", v[i].now, v[i].val);
    if (i + 1 < v.size()) printf("%05d", v[i + 1].now);
    else printf("-1");
    if (i < v.size() - 1) printf("\n");
  }
}
int main() {
  int head, num;
  cin >> head >> num;
  while (num--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    next0[a] = c;
    nodes[a] = node {a, b, c};
  }
  vector<node> v1, v2;
  for (int i = head; i != -1; i = next0[i]) {
    if (!vis[abs(nodes[i].val)]) {
      v1.push_back(nodes[i]);
      vis[abs(nodes[i].val)] = 1;
    } else {
      v2.push_back(nodes[i]);
    }
  }
  print(v1);
  printf("\n");
  print(v2); 
  return 0;
}
