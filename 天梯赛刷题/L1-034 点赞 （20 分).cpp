#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main() {
  int n, k;
  cin >> n;
  int max_times = -1;
  int s[1001] = {0};
  while (n--) {
    cin >> k;
    while (k--) {
      int id;
      cin >> id;
      s[id]++;
      max_times = max(max_times, s[id]);
    }
  }
  for (int i = 1000; i >= 1; i--) {
    if (s[i] == max_times) {
      cout << i << " " << s[i] << endl;
      break;
    }
  }
  return 0;
}

