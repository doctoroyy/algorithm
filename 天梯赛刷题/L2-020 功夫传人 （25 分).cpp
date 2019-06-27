#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn = 1e6 + 10;
double excellent[maxn];
int rank0[maxn], n;
double z, r, res = 0;
vector<vector<int> > v;
void bfs() {
  queue<int> q;
  q.push(0);
  rank0[0] = 0;
  while (!q.empty()) {
    int k = q.front();
    q.pop();
    for (int i = 0; i < v[k].size(); i++) {
      rank0[v[k][i]] = rank0[k] + 1;
      q.push(v[k][i]);
      if (excellent[v[k][i]]) {
        res += z * ((pow(1 - r / 100, rank0[v[k][i]] - rank0[0]))) * excellent[v[k][i]];
      }
    }
  }
}

int main() {
  cin >> n >> z >> r;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    if (k == 0) {
      cin >> excellent[i];
    }
    while (k--) {
      int id;
      cin >> id;
      v[i].push_back(id);
    }
  }
  bfs();
  //门派只有一个人的情况下特判一下 
  if (excellent[0]) {
    res += z * excellent[0];
  }
  cout << (long long) res;
  return 0;
}
