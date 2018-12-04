#include<iostream>
#include<algorithm>
using namespace std;
struct stu {
  int sno, time;
};
bool cmp(const stu a, const stu b) {
  return a.time < b.time;
}
int main() {
  stu a[2010];
  int n, m, t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[cnt].time;
        a[cnt++].sno = i;
      }
    }
    sort(a, a+cnt, cmp);
    int ans = 0, res = (1 << 30);
    for (int i = 0; i < cnt; i++) {
      int visited[210] = {0}, t = 1;
      visited[a[i].sno] = 1;
      for (int j = i; j < cnt; j++) {
        if (!visited[a[j].sno]) {
          visited[a[j].sno] = 1;
          t++;
          if (t == n) {
//            printf("*\n");
            res = min(res, a[j].time - a[i].time);
            break;
          }
        }
        
      }
    }
    cout << res << endl;
  }
}
