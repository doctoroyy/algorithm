#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n, m, k;
//    cin >> n >> m >> k;
    scanf("%lld%lld%lld", &n, &m, &k);
    string str;
    for (int i = 0; i < n - m; i++) str += "0";
    for (int i = 0; i < m - 1; i++) str += "1";
    set<string> sset;
    //10110 
    string pre = str;
    int  count = 0;
    do {
//      string tmp = "1";
//      for (int = 0; i < str.size(); i++) tmp.push_back(str[i]);
//      if (pre != str) {
        count++;
//      }
      if (count == k) {
        cout << "1" + str << endl;
        break;
      }
//      sset.insert(str);
//      cout << str << endl;
//      if (sset.size() == k) {
//        cout << "1" + str << endl;
//        break;
//      }  
    } while (next_permutation(str.begin(), str.end())); 
    
//    set<string>::iterator it = sset.begin();
//    int cnt = 1;
//    while (cnt < k) {
//      cnt++;
//      it++;
//    }
//    cout << "1" + *it << endl;
  }  
  return 0;
}

