#include<iostream>
#include<vector> 
#include<queue>
using namespace std;
int main() {
  int n;
  cin >> n;
  cin.get();
  string str;
  getline(cin, str);
  queue<char> q; 
  for (int i = 0; i < str.size(); i++) {
    q.push(str[i]);
  }
  int raw = n, col = str.size() / n + (str.size() % n != 0);
  char v[100][100];
  int index = 0;
  for (int j = col - 1; j >= 0; j--) {
    for (int i = 0; i < raw; i++) {
      if (!q.empty()) {
        v[i][j] = q.front();
        q.pop();
      }
      else v[i][j] = ' ';
    }
  }
  for (int i = 0; i < raw; i++) {
    for (int j = 0; j < col; j++) {
      cout << v[i][j];
    }
    cout << endl;
  }
  return 0;
}

