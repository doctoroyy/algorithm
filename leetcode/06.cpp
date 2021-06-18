// https://leetcode.com/problems/zigzag-conversion/

#include<iostream>
#include<vector>
#include<cmath>
#include<set>
using namespace std;

string convert(string s, int numRows) {
  // vector<string> store(numRows);
  int dir[2][2] = {{1, 0}, {-1, 1}};
  int d = 0;
  int row = 0, col = 0;
  for (int i = 0; i < s.size(); i++) {
    // store[row][col] = s[i];
    row += dir[d][0];
    col += dir[d][1];
    if (row == numRows - 1 || row == 0) d = !d; 
  }
  char store[numRows][col + 1];

  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j <= col; j++) {
      store[i][j] = '0';
    }
  }
  
  row = 0, col = 0, d = 0;
  for (int i = 0; i < s.size(); i++) {
    store[row][col] = s[i];
    row += dir[d][0];
    col += dir[d][1];
    if (row == numRows - 1 || row == 0) d = !d; 
  }

  string res = "";
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j <= col; j++) {
      if (store[i][j] != '0') {
        res += store[i][j];
      }
    }
  }
  return res;
}

int main() {
  string s;
  cin >> s;
  cout << convert(s, 3) << endl;
}