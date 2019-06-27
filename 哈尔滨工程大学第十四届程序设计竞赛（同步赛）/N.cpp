#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
  int id, val;
};
bool cmp(const node &a, const node &b) {
  return a.val > b.val;
}
int main() {
  int runs, n;
  cin >> runs;
  while (runs--) {
    vector<node> v1, v2;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int num;
      cin >> num;
      v1.push_back(node {i, num});
    }
    for (int i = 1; i <= n; i++) {
      int num;
      cin >> num;
      v2.push_back(node {i, num});
    }
    sort(v1.begin(), v1.end(), cmp);
    sort(v2.begin(), v2.end(), cmp);

    while (!v1.empty() || !v2.empty()) {
      if (!v1.empty()) {
        cout << v1[0].id << " ";
        v1.erase(v1.begin());
      }
      if (!v2.empty()) {
        cout << v2[0].id << " ";
        v2.erase(v2.begin());
      }
    }
    cout << endl;
  }
  return 0;
}
