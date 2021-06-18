// https://leetcode.com/problems/zigzag-conversion/

#include<iostream>
#include<vector>
#include<cmath>
#include<set>
using namespace std;

string convert(string s, int numRows) {
  if (numRows == 1) return s;
  
  int dir[2] = {1, -1};
  int d = 0;
  int row = 0;

  string res = "";

  vector<string> buff(numRows, "");

  for (int i = 0; i < s.size(); i++) {
    buff[row] += s[i];
    row += dir[d];
    if (row == numRows - 1 || row == 0) d = !d; 
  }

  for (int i = 0; i < numRows; i++) {
    res += buff[i];
  }

  return res;
}

int main() {
  string s;
  cin >> s;
  cout << convert(s, 3) << endl;
}