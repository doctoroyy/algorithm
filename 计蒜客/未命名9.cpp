#include<iostream>
#include<cstring> 
using namespace std;
const int maxn = 150000 + 100;
int marked[maxn], vis[maxn];
int getSum(int num) {
  int res = 0;
  while (num) {
    res += (num % 10) * (num % 10); 
    num /= 10;
  }
  return res;
}
void init() {
  for (int i = 2; i < 810; i++) {
    int tmp = getSum(i);
    memset(vis, 0, sizeof(vis));
    while (tmp != 1 && !vis[tmp]) {
      vis[tmp] = 1;
      tmp = getSum(tmp);
    }
    if (tmp == 1) marked[i] = 1;
  }
  
  for (int i = 809; i <= maxn; i++) {
    int tmp = getSum(i);
    while (tmp != 1) {
      tmp = getSum(tmp);
      if (marked[tmp] == 1) {
        marked[i] = 1;
        break;
      } else if (marked[tmp] == 0 && tmp < i) {
        marked[i] = 0;
        break;
      }
    }
  }
}
int main() {
  init();
  for (int i = 1; i < 100; i++) {
    if (marked[i] == 1) cout << i << endl;
  }
  int q, k;
  
  return 0;
}

