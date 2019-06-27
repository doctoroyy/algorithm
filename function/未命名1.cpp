#include<iostream>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    long long cnt = 0, score;
    for (int i = 0; i < n; i++) {
      cin >> score;
      if (score < 60) cnt++;
    }
    cout << cnt * 400 << endl;
  }
  return 0;
}

