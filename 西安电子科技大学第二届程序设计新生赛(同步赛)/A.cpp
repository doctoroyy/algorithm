#include<iostream>
#include<cmath>
#include<algorithm> 
using namespace std;
long long binarySearch(long long num, long long key) {
  while (num * num > key) num /= 2;
  long long l = num, r = num * 2, mid = (l + r) / 2;
  while (mid * mid != key) {
    mid = (l + r) / 2;
    if (mid < (long long)sqrt(key)) {
      l = mid + 1;
    } else if (mid > (long long)sqrt(key)){
      r = mid - 1;
    } else {
      return mid;
    }
  }
  return mid;
}
int main() {
  
  
  long long n;
//  while (cin >> n) {
     for (int i = 1; i <= 100; i++) cout << binarySearch(i, i) << endl; 
//  }
  return 0;
}

