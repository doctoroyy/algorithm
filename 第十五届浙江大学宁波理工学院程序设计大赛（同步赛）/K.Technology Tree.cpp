#include<iostream>
using namespace std;
const int maxn = 200010;
struct node {
  int a, b;
}building[maxn];
int pre[maxn];
int main() {
  int t, n, q, num;
  cin >> t;
  while (t--) {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
      cin >> building[i].a >> building[i].b; 
    }
    for (int i = 1; i <= n - 1; i++) cin >> pre[i + 1];
    
    for (int i = 2; i <= n; i++) {
      building[i].a += building[pre[i]].a;
      building[i].b += building[pre[i]].b;
    }
    
    while (q--) {
      cin >> num;
      cout << building[num].a << " " << building[num].b << endl;
    }
  }
  return 0;
}

