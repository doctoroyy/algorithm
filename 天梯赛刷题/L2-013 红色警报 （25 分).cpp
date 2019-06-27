#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 5000 + 10;
int pre[maxn], e[maxn][maxn], des[maxn];
int n, m, k;
int find(int x) {
  return x == pre[x] ? x : pre[x] = find(pre[x]);
}
void Union(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) pre[fx] = fy;
}

int find_blocks() {
  set<int> s;
  for (int i = 0; i < n; i++) {
    s.insert(find(i));
  }
  return (int) s.size();
}
int surviving() {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (des[i]) cnt++;
  }
  return n - cnt;
}
void init() {
  for (int i = 0; i < maxn; i++) pre[i] = i;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (e[i][j] && !des[i] && !des[j]) Union(i, j);
    }
  }
}
int main() {
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    e[a][b] = 1;
  }
  init();
  int tot = find_blocks();
//  cout << tot << endl;
  cin >> k;
  while (k--) {
    int num;
    cin >> num;
    des[num] = 1;
    init();
    int tmp = find_blocks();
//    cout << tmp << endl;
    if (tmp - tot >= 2) {
      printf("Red Alert: City %d is lost!", num);
    } else {
      printf("City %d is lost.", num);
    }
    puts("");
    tot = tmp;
  }
  if (surviving() == 0) {
    printf("Game Over.");
  }
  return 0;
}
