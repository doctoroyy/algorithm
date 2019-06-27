#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
  int time;
  int borrowed;
};
int main() {
  int n;
  scanf("%d", &n);
  int id, hh, mm;
  char key;
  for (int i = 0; i < n; i++) {
    node a[1010];
    int tot_times = 0, cnt = 0;
    while (1) {
      scanf("%d %c %d:%d", &id, &key, &hh, &mm);
      cin.get();
      if (id == 0) {
        break;
      }
      if (key == 'S') {
        a[id] = (node {hh * 60 + mm, 1});
      } else if (a[id].borrowed == 1) {
        tot_times += hh * 60 + mm - a[id].time;
        a[id].borrowed = 0;
        cnt++;
      }
    }
    if (cnt) {
      cout << cnt << " " << (int)((double) tot_times / cnt + 0.5) << endl;
    } else {
      cout << "0 0\n";
    }
  }
  return 0;
}

