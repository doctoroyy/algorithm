#include<iostream>
using namespace std;
int main() {
  int t;
  cin >>t;
  while (t--) {
    int n;
    cin >> n;
    int sum = 0; 
    if (n % 2 == 0) { // 如果n是偶数 就将其变为奇数 但是 操作次数要加1 
      sum = 1;
      n--;
    }
    while (n > 2) {
      n /= 2;
      sum++;
    }
    sum += n;
    cout << sum << endl;
  }

  return 0;
}

