// https://leetcode.com/problems/integer-to-roman/

#include<iostream>
#include<vector>
#include<cmath>
#include<set>
#include<map>
using namespace std;

// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000



int v[14] = {0, 1, 4,5,9, 10,40, 50,90, 100,400, 500,900,1000};

map<int, string> str_map = {
  {1, "I"},
  {4, "IV"},
  {5, "V"},
  {9, "IX"},
  {10, "X"},
  {40, "XL"},
  {50, "L"},
  {90, "XC"},
  {100, "C"},
  {400, "CD"},
  {500, "D"},
  {900, "CM"},
  {1000, "M"}
};

string intToRoman(int num) {
  string res = "";
  while (num) {
    for (int i = 13; i >= 1; i--) {
      int cnt = num / v[i];
      if (cnt > 0) {
        int tmp = cnt * v[i];
        num -= tmp;
        for (int j = 0; j < cnt; j++) res += str_map[v[i]];
      }
    }
  }
  return res;
}

int main() {
  int num = 3;
  cout << intToRoman(num) << endl;
}