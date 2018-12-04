#include<iostream>
#include<algorithm>
using namespace std;
struct node {
  int a, b;
}work[2010];
bool cmp(const node x, const node y) {
  return x.b > y.b;
}
int main() {
  int n, a, b;
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> work[i].a >> work[i].b;
    }
    cout << "\n"; 
    sort(work, work + n, cmp);
    for (int i = 0; i < n; i++) {
      cout << work[i].a << " " << work[i].b << endl;
    }
    cout << endl;
    int sum = 0, time = n;
    for (int i = 1; i <= n; i++) {
      if (work[i-1].a >= time) {
        time--;
      } else {
        cout << i << endl; 
        sum += work[i-1].b;
      }
    }
    cout << sum << endl;
  }
}
