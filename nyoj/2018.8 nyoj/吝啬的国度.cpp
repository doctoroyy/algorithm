#include<iostream>
using namespace std;
const int maxn = 1e5 + 10;
int parent[maxn];

int Find(int x) {
  if (x == parent[x]) {
    return x;
  }
  return parent[x] = Find(parent[x]);
}
void Union(int x, int y) {
  int fx = Find(x);
  int fy = Find(y);
  if (fx != fy) {
    parent[fx] = fy;
  }
}
int main() { 
  int runs, n, s, a[maxn], b[maxn];
  cin >> runs;
  while (runs--) {
//    int parent[maxn];
    cin >> n >> s;
    for (int i = 0; i < n - 1; i++) {
      cin >> a[i] >> b[i];
      Union(a[i], b[i]);
    }
    for (int i = 1; i <= n; i++) {
      cout << Find(i) << " ";
    }
    cout << endl;
  }
}
