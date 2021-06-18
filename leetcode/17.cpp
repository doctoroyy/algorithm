// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
  vector<string> res;
  string one_of_res;
  
  map<char, string> num_to_str = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
  };
  
  void dfs(vector<string> &num_str_set, int digits_len, int cur) {
    if (one_of_res.size() == digits_len) {
      res.push_back(one_of_res);
      return;
    }
    for (int i = cur; i < digits_len; i++) {
      string num_str = num_str_set[i];
      for (int j = 0; j < num_str.size(); j++) {
        one_of_res.push_back(num_str[j]);
        dfs(num_str_set, digits_len, i + 1);
        one_of_res.pop_back();
      }
    }
  }

  vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) return res;
    vector<string> num_str_set;

    for (int i = 0; i < digits.size(); i++) {
      num_str_set.push_back(num_to_str[(char)digits[i]]);
    }
    dfs(num_str_set, digits.size(), 0);
    return res;
  }
};