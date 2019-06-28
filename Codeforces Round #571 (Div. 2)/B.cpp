#include<iostream>
using namespace std;
#define LL long long
int main() {
  ios::sync_with_stdio(false);
  LL n, m;
  cin >>n >> m;
//  cout << ((n+2)*(m+2)-12L)/8L + 1<< endl;
////  LL sum = (n + 1) / 2 * (m + 1) / 3;
////  if(m % 3 == 1) sum += (n + 1) / 3;
////  cout << sum << endl; 
  LL sum = 0;
  if(n % 2 == 0) {
    sum = (n - 2) / 2 * ((m + 1) / 3) + (m + 1) / 2;
    if(m % 3 == 1) sum += (n + 1) / 3;
  } else {
    sum = (n + 1) / 2 * ((m + 1) / 3);
    if(m % 3 == 1) sum += (n + 1) / 3;
  }
  cout << sum << endl;
  return 0;
}

