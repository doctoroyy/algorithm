#include<iostream>
using namespace std;
int main() {
  int n, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a & 1) cnt++;
  } 
  cout << cnt << " " << n - cnt;
  
  return 0;
}

