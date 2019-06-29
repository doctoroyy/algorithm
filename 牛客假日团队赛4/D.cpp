#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 300;
int n, w, buf[maxn];
double _max = -1;

struct Node {
  double wi, ti;
};
bool cmp(const Node &a, const Node &b) {
  return a.ti / a.wi > b.ti / b.wi;
}

//int buf[maxn];

void dfs(int index, int cnt, int sum, const vector<Node> &v) {
  if (sum <= 0) {
    double s1 = 0, s2 = 0;
    for (int i = 0; i < cnt; i++) {
      s1 += v[buf[i]].ti;
      s2 += v[buf[i]].wi;
    }
    _max = max(_max, s1 / s2);
    return;
  }
  for (int i = index; i < n; i++) {
    buf[cnt] = i;
    dfs(i + 1, cnt + 1, sum - v[i].wi, v);
  }
}
int main() {

  ios::sync_with_stdio(false);
  cin >> n >> w;
  vector<Node> v;
  for (int i = 0; i < n; i++) {
    double a, b;
    cin >> a >> b;
    v.push_back(Node {a, b});
  }

  _max = -1;
  dfs(0, 0, 0, v);
  cout << _max << endl;
  return 0;
}

