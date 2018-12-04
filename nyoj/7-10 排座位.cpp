#include<iostream>
using namespace std;
int enemy[110][110];
int father[110];
int find(int x) {
  if (father[x] != x) {
    return father[x] = find(father[x]);
  }
  return x;
}
void Union(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) {
    father[fx] = fy;
  }
}

int main() {
  int n, m, k, a, b, t;
  while (cin >> n >> m >> k) {
    for (int i = 1; i <= n; i++) {
      father[i] = i;
    }
    for (int i = 0; i < m; i++) {
      cin >> a >> b >> t;
      if (t == 1) {
        Union(a, b);
      } else {
        enemy[a][b] = enemy[b][a] = 1;
      }
    }
    for (int i = 0; i < k; i++) {
      cin >> a >> b;
      if (find(a) == find(b) && enemy[a][b] == 0) {
        cout << "No problem";
      } else if (find(a) != find(b) && enemy[a][b] == 0) {
        cout << "OK";
      } else if (find(a) == find(b) && enemy[a][b] == 1) {
        cout << "OK but...";
      } else {
        cout << "No way";
      }
      cout << endl;
    }
  } 
}
