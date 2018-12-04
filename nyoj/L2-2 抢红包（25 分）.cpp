#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct Node {
  int red_packets, 
      money, 
      NO, 
      taked;
}node[10000];
bool cmp(const Node a, const Node b) {
  return (a.money > b.money) 
  || (a.money == b.money && a.red_packets > b.red_packets)
  || (a.money == b.money && a.red_packets == b.red_packets && a.NO < b.NO);
}
int main() {
  int n, k, code, money;
  while (~scanf("%d", &n)) {
    //成员初始化 
    for (int i = 1; i <= n; i++) {
      node[i].NO = i;
      node[i].money = 0;
      node[i].red_packets = 0;
      node[i].taked = 0;
    }
    
    for (int i = 1; i <= n; i++) {
//      cin >> k;
      scanf("%d", &k);
      node[i].NO = i;
      while (k--) {
//        cin >> code >> money;
        scanf("%d%d", &code, &money);
        if (node[code].taked == 0) {
          node[code].money += money;
          node[code].red_packets++;
          node[i].money -= money;
          node[i].taked = 1;
        }
      }
      node[i].taked = 0;
    }
    sort(node + 1, node + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
      printf("%d %.2lf\n", node[i].NO, double(node[i].money) / 100);
    }
  }
}
