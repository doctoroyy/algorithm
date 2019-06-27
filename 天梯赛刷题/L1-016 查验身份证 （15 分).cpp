#include<iostream>
using namespace std;
int code[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2}; 
char valid[] = {'1','0','X','9','8','7','6','5','4','3','2'};
int main() {
  int n;
  cin >> n;
  string a[100];
  
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int flag = 0;
  for (int i = 0; i < n; i++) {
    int res = 0;
    for (int j = 0; j < 17; j++) {
      res += (a[i][j] - '0') * code[j];
    }
    res %= 11;
    if (valid[res] != a[i][17]) {
      cout << a[i] << endl;
      flag = 1;
    }
  }
  if (!flag) {
    cout << "All passed";
  }
  return 0;
}

