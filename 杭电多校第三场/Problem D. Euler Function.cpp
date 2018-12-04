#include<iostream>
#include<cmath>
#include<map>
using namespace std;
const int maxn = 1e9 + 10;
//int phi[maxn];
map<int, int> com;
map<int, int> phi;
bool isPrime(int num) {
  if (num < 2) return false;
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) return false;
  }
  return true;
}   
void init() {
  phi[1] = 1;
  for (int i = 2; i < maxn; i++) {
    if (!phi[i]) {
      for (int j = i; j < maxn; j += i) {
        if (!phi[j])
          phi[j] = j;
        phi[j] = phi[j] / i * (i - 1);
      }
    }
  }
  int count = 0;
  for (int i = 5; i < 2 * maxn; i++) {
    if (!isPrime(phi[i])) com[++count] = i;
  }
  
} 

int main() {
  init();
  int runs, n;
  cin >> runs;
  while (runs--) {
    cin >> n;
    cout << com[n] << endl;
  }
  return 0;
}
