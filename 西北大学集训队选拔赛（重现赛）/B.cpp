#include<iostream>
#include<vector>
#include<map>
using namespace std;
const int N = 2005;
double arr[N], ans;
int vis[N];
int n, m, k;
//vector<int> v;
//map<int,int> Map;
void dfs(int index,int sum,double p) ;
int main() {
  int a;
  double b;
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) arr[i] = 1;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (b == 1 && vis[a] == 0) {
      k--;
      arr[a] = 0;
      vis[a] = 1;
    } else {
      arr[a] = arr[a]*(1-b); // a 不被救援的概率 
    }
  }
  for (int i = 1; i <= m; i++) {
    arr[i] = 1-arr[i];
//    cout << arr[i] << " ";
  }
//  cout << endl;
  ans = 0;
  dfs(0,0,1.0);
  printf("%.3f",ans);

  return 0;
}
void dfs(int index,int sum,double p) {
  if (sum == k) {
    ans += p;
    return ;
  } 
  if (index > m) {
    return ;
  } 
  if (vis[index] == 0) {
    dfs(index+1,sum,p*(1-arr[index]));
    dfs(index+1,sum+1,p*arr[index]);  
  } else {
    dfs(index+1,sum,p);
  }
  
}
/*
2 2 1
1 0.25
2 0.75

3 2 2
1 0.5
1 0.75
2 0.5
*/

