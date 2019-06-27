#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int total = 0;
int n, k;
int a[11];
void dfs(int count) {
  if (count == n) {
    total++;
    return; 
  }
  for (int i = 0; i < k; i++) {
    int flag = i;
    if ((count == 0 && flag == 0) || (flag == 0 && a[count-1] == 0))
      continue;
    a[count] = flag;
    dfs(count+1);
  }
}
int main() {

  cin >> n >> k;
  dfs(0);
  cout << total << endl;
}

