#include<iostream>
using namespace std;
const int maxn = 100;
int nums[maxn];
int n, r;
void dfs(int num, int index) {
//  cout << "dfs(" << num << "," << index << ") :" << endl;;
  if (index == r ) {
    for (int i = 0; i < r; i++) {
      cout << nums[i];
    }
    cout << endl;
    return;
  }
  for (int i = num; i >= 1; i--) {
    nums[index] = i;
    dfs(i - 1, index + 1);
  }
}
int main() {
  while (cin >> n >> r) {
    dfs(n, 0);
  }
  return 0;
}

