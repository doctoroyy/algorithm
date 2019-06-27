#include<iostream>
#include<algorithm>
using namespace std;
int cmp(const int &a, const int &b) {
  return a > b;
}
int main() {
  int n, q, k;
  cin >> n >> q >> k;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }
  for (int i = 0; i < q; i++) {
    int a, b, t;
    cin >> a >> b >> t;
    if (t == 1)
      sort(v.begin() + a - 1, v.begin() + b, cmp);
    else
      sort(v.begin() + a - 1, v.begin() + b);
  }
  cout << v[k - 1] << endl;
  return 0;
}
