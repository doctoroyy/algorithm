#include<iostream>
using namespace std;
int a[100], num;
void dfs(int n, int r) {
  for (int i = n; i > 0; i--) {
    a[r] = i;
    if (r > 1) {
      dfs(i - 1, r - 1);
    } else {
      for (int i = num; i > 0; i--) {
        cout << a[i];
      }
      cout << endl;
    }
  }
}
int main() {
  int n, r;
  while (cin >> n >> r) {
    num = r;
    dfs(n, r);
//    cout << endl;
  }
}
