#include <bits/stdc++.h>
using namespace std;
struct Node {
  char name[200];
  int id, num;
} peo[150005];
bool operator <(Node a,Node b) {
  if(a.num == b.num) return a.id > b.id;
  return a.num < b.num;
}
struct Node1 {
  int t, p;
} door[150005];
bool cmp(Node1 a, Node1 b) {
  return a.t < b.t;
}
priority_queue<Node> myq;
int main() {
  int T, k, m, q, x;
  cin >> T;
  while(T--) {
    int ans[150005];
    int now = 1, count = 1;
    scanf("%d %d %d", &k, &m, &q);
    for(int i = 1; i <= k; i++) {
      scanf("%s %d", peo[i].name, &peo[i].num);
      peo[i].id = i;
    }
    for(int i = 1; i <= m; i++) {
      scanf("%d%d", &door[i].t, &door[i].p);
    }
    sort(door+1, door+m+1, cmp);
    for(int i = 1; i <= m; i++) {
      for(int j = now; j <= door[i].t; j++) {
        if(now > k) {
          continue;
        }
        myq.push(peo[now++]);
      }
      if(now > k) {
        while(!myq.empty()) {
          Node w = myq.top();
          ans[count++] = w.id;
          myq.pop();
        }
      } else {
        for(int j = 1; j <= door[i].p; j++) {
          if(!myq.empty()) {
            Node w = myq.top();
            ans[count++] = w.id;
            myq.pop();
          }
        }
      }
    }
    while(now <= k) {
      myq.push(peo[now++]);
    }
    while(!myq.empty()) {
      Node w = myq.top();
      ans[count++] = w.id;
      myq.pop();
    }
    for(int i = 1; i <= q; i++) {
      scanf("%d", &x);
      printf("%s", peo[ans[x]].name);
      if(i != q) printf(" ");
      else printf("\n");
    }
  }
  return 0;
}
