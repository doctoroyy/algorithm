#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 10;
int main() {
  int runs, l[maxn], r[maxn], n, q;
  cin >> runs;
  while (runs--) {
    string str, prefix[maxn];
    cin >> n >> q;
    cin >> str;
    prefix[0] = str[0];
    for (int i = 1; i < n; i++) {
      prefix[i] += prefix[i - 1] + str[i];
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < n; j++) {
        cout << prefix[j] - prefix[j - i] << endl;
      }
    }
    
//    for (int i = 0; i < q; i++) {
//      cin >> l[i] >> r[i];
//    }
//    for (int i = 0; i < q; i++) {
//      
//    }
  } 
}
