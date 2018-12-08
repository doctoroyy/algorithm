//
// Created by doctoroyy on 2018/12/8.
//
#include<iostream>
#include<map>
#include<vector>
using namespace std;
vector<string> split(string str, string regx) {
  vector<string> arr;
  int offset = 0;
  for (int i = 0; str[i]; ++i) {
    if (str[i] == regx[0]) {
      arr.push_back(str.substr(offset, i - 1 - offset + 1));
      offset = i + 1;
    }
  }
  arr.push_back(str.substr(offset));
  return arr;
}
map<string, int> dic;

long long  hex2ten(vector<string> arr) {
  long long  res = 0;
  for (int i = 0; i < arr.size(); i++) {
    res = res * 16 + dic[arr[i]];
  }
  return res;
}
int main() {
  dic["zero"] = 0;
  dic["one"] = 1;
  dic["two"] = 2;
  dic["three"] = 3;
  dic["four"] = 4;
  dic["five"] = 5;
  dic["six"] = 6;
  dic["seven"] = 7;
  dic["eight"] = 8;
  dic["nine"] = 9;
  dic["ten"] = 10;
  dic["eleven"] = 11;
  dic["twelve"] = 12;
  dic["thirteen"] = 13;
  dic["fourteen"] = 14;
  dic["fifteen"] = 15;
  string s1, s2;
  while (getline(cin, s1)) {
    getline(cin, s2);
    vector<string>arr1, arr2;
    arr1 = split(s1, " ");
    arr2 = split(s2, " ");
    long long num1 = hex2ten(arr1), num2 = hex2ten(arr2);
//    cout << "num1 = " << num1 << " num2 = " << num2 << endl;
    cout << num1 * num2 << endl;
  }
  return 0;
}

