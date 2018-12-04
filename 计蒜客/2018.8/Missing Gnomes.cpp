#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 10;
int order[maxn], used[maxn];
int main() {
  int n, m;
  while (cin >> n >> m) {
    memset(used, 0, sizeof(used));
    memset(order, 0, sizeof(order));
    for (int i = 0; i < m; i++) {
      cin >> order[i];
      used[order[i]] = 1;
    }
    int tmp = n + 1, index = 0;
    for (int i = 1; i <= n; i++) {
      if (used[i] == 0) {
        cout << i << " ";
      } else if (used[i] == 1 && i != order[index]) {
        
        continue;
      } else if (i == order[index]) {
        cout << order[index] << " ";
        index++;
      } else if (used[order[index]] == 1) {
        cout << order[index] << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
// 7 3
// 4 1 7
// 2 3    4 1     5 6      7    
