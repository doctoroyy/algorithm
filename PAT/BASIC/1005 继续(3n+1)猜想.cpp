#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;
const int maxn = 1000;
int deletes[maxn * 10 + 10];
void f(int n) {
  while (n != 1) {
    if (n & 1) n = 3 * n + 1;
    n /= 2;
    deletes[n] = 1;
  }
}
int num[maxn + 10];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }
  for (int i = 0; i < n; i++) {
    if (deletes[num[i]] == 0) {
      f(num[i]);
    }
  }
  vector<int> out;
  for (int i = 0; i < n; i++) {
    if (deletes[num[i]] == 0) {
      out.push_back(num[i]);
//      cout << num[i] << " ";
    }
  }
  sort(out.begin(), out.end());
  cout << out[out.size() - 1];
  for (int i = out.size() - 2; i >= 0; i--) {
    cout << " " << out[i];
  }
  return 0;
}

