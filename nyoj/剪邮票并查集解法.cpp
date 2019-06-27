#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int maxn = 1e6 + 10;
int pre[maxn];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int find(int x) {
  if (x == pre[x]) {
    return x;
  }
  return pre[x] = find(pre[x]);
}
int ele_in_buff(int ele, vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    if (ele == v[i]) return 1;
  }
  return 0;
}
void join(int p, vector<int> v) {
  int x = (p - 1) / 4, y = (p - 1) % 4;
  for (int i = 0; i < 4; i++) {
    int nx = x + dir[i][0], ny = y + dir[i][1]; //生成节点对应的坐标 
    if (nx < 0 || nx > 3 - 1 || ny < 0 || ny > 4 - 1) continue;
    int np = nx * 4 + ny + 1;
    if (ele_in_buff(np, v)) {
      pre[find(np)] = find(p);
    }
  }
}

int main() {
  int ans = 0;
  vector<int> buff;
  for (int a = 1; a <= 12 - 4; a++) {
    for (int b = a + 1; b <= 12 - 3; b++) {
      for (int c = b + 1; c <= 12 - 2; c++) {
        for (int d = c + 1; d <= 12 - 1; d++) {
          for (int e = d + 1; e <= 12; e++) {
            vector<int> v;
            v.push_back(a);
            v.push_back(b);
            v.push_back(c);
            v.push_back(d);
            v.push_back(e);
            for (int i = 1; i <= 12; i++) {
              pre[i] = i;
            }
            for (int i = 0; i < v.size(); i++) join(v[i], v);
            set<int> s;
            for (int i = 0; i < v.size(); i++) {
              s.insert(find(v[i]));
            }
            if (s.size() == 1) ans++; //如果这五个节点构成一个联通块, 集合元素总数就是 1 
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
