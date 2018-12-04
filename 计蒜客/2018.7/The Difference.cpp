#include<iostream>
#include<algorithm>
using namespace std;
int main() {
  int runs;
  long long num[4];
  cin >> runs;
  while (runs--) {
    for (int i = 0; i < 4; i++) {
      cin >> num[i];
    }
    sort(num, num + 4);
    cout << num[3] * num[2] - num[1] * num[0] << endl;
  } 
  return 0;
}
