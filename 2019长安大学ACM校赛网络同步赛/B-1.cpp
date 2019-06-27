#include<iostream>
#include<cmath> 
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << ceil(log2(n + 1)) << endl;
  }
  return 0;
}

