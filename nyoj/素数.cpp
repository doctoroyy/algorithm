#include<iostream>
#include<cstring>
#include<cmath> 
using namespace std;
bool prime[100000];
int main() {
  memset(prime, true, sizeof(prime));
  for (int i = 2; i <= sqrt(100000); i++) {
    if (prime[i]) {
      for (int j = i*i; j <= 100000; j+=i) {
        prime[j] = false;
      }
    }
  }
  for (int i = 2; i <= 10000; i++) {
    if (prime[i]) {
      cout << i << endl;
    }
  }
}
