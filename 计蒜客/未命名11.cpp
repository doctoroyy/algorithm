#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  cout << a[k - 1] << endl;
  return 0; 
}
/*
1
1

2
1 2
*/
