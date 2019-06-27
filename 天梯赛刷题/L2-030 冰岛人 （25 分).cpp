#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;
map<string, string> f;
map<string, int> g;
int check(string x, string y, int rank) {
  if (rank >= 5) return 1;
  if (f[x] != f[y]) return 1; 
  if (f[x] == f[y] && f.find(x) != f.end()) return 0;
  if (f[x] == y || x == f[y] || y == f[x] || f[y] == x) return 0;
  return check(f[x], f[y], rank + 1);
}

int main() {
  string s1 = "sson", s2 = "sdottir";
  int n, m;
  cin >> n;
  map<string, int> v;
  while (n--) {
    string a, b;
    cin >> a >> b;
    v[a] = v[b] = 1;
    if (b.find("sson") != string::npos) {
      f[b.substr(0, b.find("sson"))] = a;
      g[a] = 1;
    } else if (b.find("sdottir") != string::npos) {
      g[a] = 0;
      f[b.substr(0, b.find("sdottir"))] = a;
    } else if (b[b.size() - 1] == 'm') {
      g[a] = 1;
    } else if (b[b.size() - 1] == 'f') {
      g[a] = 0;
    }
  }
  cin >> m;
  while (m--) {
    string a, b, c, d;
    cin >> a >> c >> b >> d;
    if (v.find(a) == v.end() ||v.find(b) == v.end()) {
      cout << "NA";
    } else if (g[a] == g[b]) {
      cout << "Whatever";
    } else {
      if (check(a, b, 1)) {
        cout << "Yes";
      } else {
        cout << "No";
      }
    }
    cout << endl;
  }
  return 0;
}
