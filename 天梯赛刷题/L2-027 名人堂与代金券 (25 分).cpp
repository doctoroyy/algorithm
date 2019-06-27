#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node {
  string email;
  int score;
  int rank;
};
bool cmp(const node &a, const node &b) {
  if (a.score == b.score) return a.email < b.email;
  return a.score > b.score;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<node> v;
  for (int i = 0; i < n; i++) {
    string email;
    int score;
    cin >> email >> score;
    v.push_back(node {email, score, 0});
  }
  sort(v.begin(), v.end(), cmp);
  vector<node> out;
  out.push_back(node {v[0].email, v[0].score, 1});
  int rank = 1;
  for (int i = 1; i < n; i++) {
    if (v[i].score != v[i - 1].score) {
      rank = out.size() + 1;
    }
    if (rank > k) break;
    out.push_back(node {v[i].email, v[i].score, rank});
  }
  int sum = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i].score >= m) {
      sum += 50;
    } else if (v[i].score >= 60) {
      sum += 20;
    }
  }
  cout << sum << endl;
  for (int i = 0; i < out.size(); i++) {
    cout << out[i].rank << " " << out[i].email << " " << out[i].score;
    if (i < out.size() - 1) cout << endl;
  }
  return 0;
}
