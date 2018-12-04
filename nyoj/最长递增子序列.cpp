#include<iostream>
#include<cstring>
using namespace std;
const int N = 11000;
int count[N];
int LIS(char a[], int n) {
  int max_length = 1;
  count[0] = 1;
  for (int i = 1; i < n; i++) {
    count[i] = 1;
    for (int j = 0; j < i; j++)
      if (a[j] < a[i] && count[j] + 1 > count[i])
        count[i] = count[j] + 1;
    if (count[i] > max_length)
      max_length = count[i];
  }
  return max_length;
}
int main() {
  int T;
  char a[11000];
  cin >> T;
  while (T--) {
    cin >> a;
    cout << LIS(a, strlen(a)) << endl;
  }
}

