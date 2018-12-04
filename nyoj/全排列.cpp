#include<iostream>
using namespace std;
int cnt;
int vis[10];
int nums[10];
void dfs(int index) {
  if (index > 5) {
    cout << "*" << endl; 
    return;
  }
  if (index == 5) {
    for (int i = 0; i < 5; i++) {
      cout << nums[i] << " ";
    }
    cout << endl;
    return;
  }
  for (int i = 1; i <= 5; i++) {
    if (vis[i] == 0) {
      vis[i] = 1;
      nums[index] = i;
      dfs(index + 1);
      vis[i] = 0;
    }
  }
}
int main() {
  dfs(0);
  return 0;
}

