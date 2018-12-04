#include<iostream>
#include<map>
using namespace std;
int main() {
  int t, n, m, query, score;
  string name;
  cin >> t;
  while (t--) {
    map<int, string> info;
    cin >> n >> m;
    while (n--) {
      cin >> name >> score;
      if (!info.count(score)) {
        info[score] = name;
      }
    }
    while (m--) {
      cin >> query;
      cout << info[query] << endl;
    }
  }
}
