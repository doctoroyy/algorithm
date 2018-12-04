
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
static const int s[12] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800};
int main() {
  int t, n;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    n = n-1;
    vector<int> v;
    vector<int> a;
    for(int i = 1; i <= 12; i++)
      v.push_back(i);
    for(int i = 12; i >= 1; i--)  {
      int r = n % s[i-1];
      int t = n / s[i-1];
      cout << t << " " << r << endl;
      n = r;
      sort(v.begin(), v.end());
      a.push_back(v[t]);
      v.erase(v.begin() + t);
    }
//    for(int i = 0; i < 12; i++) {
////      cout << a[i] << " ";
//      
//      if(a[i] == 1) printf("a");
//      if(a[i] == 2) printf("b");
//      if(a[i] == 3) printf("c");
//      if(a[i] == 4) printf("d");
//      if(a[i] == 5) printf("e");
//      if(a[i] == 6) printf("f");
//      if(a[i] == 7) printf("g");
//      if(a[i] == 8) printf("h");
//      if(a[i] == 9) printf("i");
//      if(a[i] == 10) printf("j");
//      if(a[i] == 11) printf("k");
//      if(a[i] == 12) printf("l");
//    }
//    printf("\n");
  }
}
