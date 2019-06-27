#include<iostream>
#include<set>
#include<vector>
#include<map>
using namespace std;
int main() {
  int n, q;
//  cin >> n >> q;
  scanf("%d%d", &n, &q);
//  getchar();
  set<string> sset;
  vector<string> v;
  map<string, int> vis;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
//    char str[50];
    string str;
    cin >> str;
    if (vis[str] == 1) {
      cnt++;
    } else {
      vis[str] = 1;

    }
//    sset.insert(str);
  }
  while (q--) {
    int op;
    scanf("%d", &op);
//    getchar();

    if (op == 1) {
      string str;
      cin >> str;
      if (vis[str] == 1) {
        cnt++;
      } else {
        vis[str] = 1;
      }
    } else {
      cout << cnt << endl;
    }
  }
  return 0;
}

