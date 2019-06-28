#include<iostream>
#include<cmath>
using namespace std;
const int N = 1e5+5;
int vis[N], a[N];
double Arr[N];
int sum;
int main() {
  ios::sync_with_stdio(false);

  int n, t1, t2;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> Arr[i];
    t1 = floor(Arr[i]);
    t2 = ceil(Arr[i]);
    if(t1 == t2) vis[i] = 1;
    a[i] = t2;
    sum += a[i];
  }
  for (int i = 0; i < n; i++) {
    if(vis[i]) continue;
    if(sum == 0) break;
    a[i]--;
    sum--;
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << "\n";
  }
}
