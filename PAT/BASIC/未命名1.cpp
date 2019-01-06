#include<iostream>
#include<algorithm>
using namespace std;
int nums[100000 + 10];
int main() {
  int n;
  while (cin >> n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
      sum += nums[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (sum - 2 * nums[i] == 0) cnt++;
    }
    cout << (cnt == 0? -1 : cnt ) << endl;
  } 
  return 0;
}

