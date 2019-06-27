#include<iostream>
#include<map>
using namespace std;
const int maxn = 1e3 + 10;
int nodes[maxn];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int num;
    cin >> num;
//    nodes[i] = num;
    int j;
    for (j = i; nodes[j / 2] > num; j /= 2) {
      nodes[j] = nodes[j / 2];
//      swap(nodes[j], nodes[j / 2]);
    }
    nodes[j] = num;
  }
  map<int, int> mmap;
  for (int i = 1; i <= n; i++) {
//    cout << i << " " << nodes[i]<< endl;
    mmap[nodes[i]] = i;
  }
  cin.get();
  for (int i = 0; i < m; i++) {
    string str;
    getline(cin, str);
    int pos;
    if (str.find(" is the root") != string::npos) {
      pos = str.find(" is the root");
      int num = stoi(str.substr(0, pos));
      if (mmap[num] != 1) {
        cout << "F";
      } else {
        cout << "T";
      }
    } else if (str.find(" are siblings") != string::npos) {
      pos = str.find(" are siblings");
      str = str.substr(0, pos);
      pos = str.find(" and ");
      int a = stoi(str.substr(0, pos));
      int b = stoi(str.substr(pos + string(" and ").size() - 1));
      if (abs(mmap[a] - mmap[b]) == 1 && mmap[a] / 2 == mmap[b] / 2) {
        cout << "T";
      } else {
        cout << "F";
      }
    } else if (str.find(" is the parent of ") != string::npos) {
      pos = str.find(" is the parent of ");
      int a = stoi(str.substr(0, pos));
      int b = stoi(str.substr(pos + string(" is the parent of ").size() - 1));
      if (mmap[b] / 2 == mmap[a]) {
        cout << "T";
      } else {
        cout << "F";
      }
    } else {
      pos = str.find(" is a child of ");
      int a = stoi(str.substr(0, pos));
      int b = stoi(str.substr(pos + string(" is a child of ").size() - 1));
      if (mmap[a] / 2 == mmap[b]) {
        cout << "T";
      } else {
        cout << "F";
      }
    }
    if (i < m - 1) cout << endl;
  }
  return 0;
}
