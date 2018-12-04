#include<iostream>
using namespace std;
int num[100000], q[100000];
struct query {
  int num;
  bool visited = false;
}a[100000];
int main() {
  int n, k, m;
  cin >> n;
  while (n--) {
    cin >> k;
    for (int i = 0; i < k; i++) {
      cin >> num[i];
      a[num[i]].num++;
    }
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> q[i];
    a[q[i]].visited = false;
  }
  int flag = 0;
  if (a[q[0]].num == 0 && a[q[0]].visited == false) {
    printf("%05d", q[0]);
    flag = 1;
  }
  for (int i = 1; i < m; i++) {
    if (a[q[i]].num == 0 && a[q[i]].visited == false) {
      if (!flag) {
        printf("%05d", q[i]);
      } else {
        printf("*%05d", q[i]);
      }
      
      a[q[i]].visited = true;
      flag = 1;
    }
  }
  if (!flag) cout << "No one is handsome";
}
