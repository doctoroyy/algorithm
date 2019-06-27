#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
  string name;
  int times;
};
bool cmp(const string &a, const string &b) {
  return a > b;
}
int main() {
  int n;
  cin >> n;
  map<string, int> mmap;
  while (n--) {
    string name;
    cin >> name;
    mmap[name] = 1;
  }
  int k;
  cin >> k;
  int tmp = k;
  vector<node> v;
  double sum = 0;
  while (k--) {
    string name;
    int times;
    cin >> name >> times;
    v.push_back(node {name, times});
    sum += times;
  }
  vector<string> v1;
  for (int i = 0; i < v.size(); i++) {
    if (mmap.find(v[i].name) == mmap.end() && v[i].times > sum / tmp) {
      v1.push_back(v[i].name);
    }
  }
  if (v1.empty()) {
    cout << "Bing Mei You";
  } else {
    sort(v1.begin(), v1.end());
    for (int i = 0; i < v1.size(); i++) {
      cout << v1[i];
      if (i < v1.size() - 1) cout << "\n";
    }
  }
  return 0;
}

