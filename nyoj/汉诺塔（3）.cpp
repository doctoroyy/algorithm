#include<iostream>
#include<stack>
using namespace std;
int main() {
  int t, p, q, a, b;
  cin >> t;
  while (t--) {
    cin >> p >> q;
    bool legal = true;
    stack <int> plate[4];
    for (int i = p; i > 0; i--) plate[0].push(i);
    for (int i = 0; i < q; i++) {
      cin >> a >> b;
      a -= 1, b -= 1;
      if (!plate[a].empty()) {
         if (!plate[b].empty() && plate[a].top() > plate[b].top()) {
           legal = false;
         } else {
           plate[b].push(plate[a].top());
           plate[a].pop();
         }
      } else {
        legal = false;
      }
    }
    if (legal) {
      cout << "legal" << endl;
    } else {
      cout << "illegal" << endl;
    }
  }
}
