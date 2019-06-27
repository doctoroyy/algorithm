#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main() {
  int k;
  cin >> k;
  string str;
  vector<string> v;
  while (cin >> str && str != "End") {
    v.push_back(str);
  }
  map<string, string> mmap;
  mmap["ChuiZi"] = "Bu";
  mmap["JianDao"] = "ChuiZi";
  mmap["Bu"] = "JianDao";
  for (int i = 0; i < v.size(); i++) {
    if ((i + 1) % (k + 1) == 0) {
      cout << v[i] << endl;
    } else {
      cout << mmap[v[i]] << endl;
    }
  }

  return 0;
}

