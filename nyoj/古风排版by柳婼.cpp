#include<iostream>
#include<vector>
using namespace std;
int main() {
  int row;
  cin >> row;
  getchar();
  string str;
  getline(cin, str);
  int col = (str.length() - 1) / row + 1;
  vector<vector<char> > v(row, vector<char>(col, ' '));
  int index = 0;
  for (int j = col - 1; j >= 0; j--) {
    for (int i = 0; i < row; i++) {
      if (index < str.length()) {
        v[i][j] = str[index++];
      }
    }
  }
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << v[i][j];
    }
    cout << endl;
  }
}
