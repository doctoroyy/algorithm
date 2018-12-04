#include<iostream>
#include<vector>
using namespace std;
int N = 500001;
vector<int> v(N, 0);
int fun_min(int n) {
  int min = 0;
  for(int i = 1; i < n; i++){
    if(v[i] < v[min]) min = i;
  }
  return min;
}
int fun_max(int k, int n) {
  int max = k;
  for(int i = k + 1; i < n; i++){
    if(v[i] > v[max]) max = i;
  }
  return max;
}
int main() {
  int t, n;
  cin >> t;
  while(t--){
    
    cin >> n;
    int a;
    for(int i = 0; i < n; i++){
      cin >> a;
      v.push_back(a);
    }
    int sum = 0, count = 0, max, min;
    while(n > 0){
      min = fun_min(n);
      max = fun_max(min, n);
      if(v[max] > v[min]) {
        sum += v[max] - v[min];
        v.erase(max);
        v.erase(min);
        count += 2;
      }
      else {
        v.erase(min);
        n = min;
      }
    }  
    cout << sum << " " << count << endl;
    v.clear();
  }
}

