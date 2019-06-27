#include<iostream>
using namespace std;
string maze[3];
int f() {
  int cnt = 0;
  for (int i = 0; i < 3; i++) {
    if (maze[0][i] + maze[1][i] + maze[2][i] == 'W' + 'W' + '#') cnt++;
    if (maze[i][0] + maze[i][1] + maze[i][2] == 'W' + 'W' + '#') cnt++;
  }
  if (maze[0][0] + maze[1][1] + maze[2][2] == 'W' + 'W' + '#') cnt++;
  if (maze[0][2] + maze[1][1] + maze[2][0] == 'W' + 'W' + '#') cnt++;
  return cnt; 
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    for (int i = 0; i < 3; i++) cin >> maze[i];
    if (f() >= 2) {
      cout << "Alice";
    } else if (f() >= 1) {
      cout << "Emmm";
    } else {
      cout << "Bob";
    }
    cout << endl;
  }
  return 0;
}
