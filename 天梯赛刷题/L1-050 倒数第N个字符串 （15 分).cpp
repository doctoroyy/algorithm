#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main() {
  int n, num;
  cin >> n >> num;
  vector<char> v1;
  vector<int> v2;
  for (int i = 0; i < n; i++) {
    v1.push_back('z');
  }
  num -= 1;
  for (int i = 0; i < n; i++) {
    v2.push_back(num % 26);
    num /= 26;
  }

  for (int i = 0; i < n; i++) {
    v1[i] -= v2[i];
  }
  for (int i = v1.size() - 1; i >= 0; i--) {
    cout << v1[i];
  }
  return 0;
}
