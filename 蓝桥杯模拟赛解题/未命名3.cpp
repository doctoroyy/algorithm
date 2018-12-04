#include<iostream>
using namespace std;
int main() {
  int cnt = 0;
  for (int i = 10; i < 100; i++) {
    for (int j = 10; j < 100; j++) {
      if (i == (j % 10 + j / 10) * 2 && j == (i % 10 + i / 10) * 3) {
        cout << i << " " << j << endl;
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}
