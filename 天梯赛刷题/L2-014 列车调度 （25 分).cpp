#include<iostream>
#include<set>
using namespace std;
int main() {
  int n;
  cin >> n;
  set<int> sset;
  sset.insert(0);
  while (n--) {
    int num;
    cin >> num;
    if (num < *sset.rbegin()) {
      sset.erase(*sset.upper_bound(num));
    }
    sset.insert(num);
  }
  cout << sset.size() - 1;
  return 0;
}
