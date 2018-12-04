#include<iostream>
#include<cmath>
using namespace std;
int main() {
  int n;
  string str, ch[100];
  cin >> n;
  getchar();
  getline(cin, str);
  int col = ceil(double(str.length()) / n * 1.0), t = 0;
  for (int j = col - 1; j >= 0; j--) {
    for (int i = 0; i < n; i++) {
      if (t < str.length()) {
        ch[i][j] = str[t++];
      } else {
        ch[i][j] = ' ';
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < col; j++) {
      cout << ch[i][j];
    }
    cout << endl;
  }
}
