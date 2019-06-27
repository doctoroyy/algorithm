#include<iostream>
#include<cstdio>
#include<deque>
using namespace std;
const int maxn = 1e6 + 10;
int next0[maxn];
struct node {
  int now, val, next;
} nodes[maxn];
int main() {
  int head, num;
  cin >> head >> num;
  while (num--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    next0[a] = c;
    nodes[a] = node {a, b, c};
  }
  deque<node> dq;
  for (int i = head; i != -1; i = next0[i]) {
    dq.push_back(nodes[i]);
  }
  while (!dq.empty()) {
    node l, r;
    r = dq.back();
    if (dq.size() == 1) {
      printf("%05d %d -1\n", r.now, r.val);
    } else {
      printf("%05d %d ", r.now, r.val);
      printf("%05d\n", dq.front().now);
    }
    dq.pop_back();
    if (!dq.empty()) {
      l = dq.front();
      if (dq.size() == 1) {
        printf("%05d %d -1\n", l.now, l.val);
      } else {
        printf("%05d %d ", l.now, l.val);
        printf("%05d\n", dq.back().now);
      }
      dq.pop_front();
    }
  }
  return 0;
}
