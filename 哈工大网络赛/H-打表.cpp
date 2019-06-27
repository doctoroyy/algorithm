#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1e6 + 10;
int num[maxn], sum[maxn];
void init() {
  for (int i = 2; i <= maxn; i++) {
    for (int j = i; j <= maxn; j += i) {
      num[j] = num[j] ^ 1;
    }
  }
  sum[0] = 0;
  for (int i = 1; i <= maxn; i++) sum[i] = sum[i - 1] + num[i];
}
int main() {
  init();
  int runs, n, a, b;
  cin >> runs;
  while (runs--) {
    cin >> n >> a >> b;
    cout << sum[b] - sum[a - 1] << endl;
  }
  return 0;
}

