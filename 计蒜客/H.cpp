#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int N = 100;
int arr[N];
vector<string> v;
string intTOStr(int k) ;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      v.push_back(intTOStr(i));
    }
//    for (int i = 0; i < n; i++) {
//      cout << v[i] << " ";
//    }
//    cout << endl;
    sort(v.begin(),v.end());
    cout << v[k-1] << endl;  
    
    int num = 0;
    if (k == 1) {
      cout << "1";
    } else {
      if (arr[])
    }
  } 
  
  return 0;
}
string intTOStr(int k) {
  string s = "";
  while (k) {
    s += char('0' + k%10);
    k /= 10;
  }
  reverse(s.begin(),s.end());
  return s;
}
int getEveryNum(int x) {
  int num = 0;
  while (x) {
    arr[num++] = x%10;
    x /= 10;
  }
  return num;
}
