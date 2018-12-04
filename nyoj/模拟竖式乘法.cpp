//11 11 121
//11(3)*11(3) 
//    4 5
//* 1 2 3
//----------
//  6 1 5
//4 9 2
//----------
//5 5 3 5
  1  1
* 1  1
----------
  1  1
1 1
---------
1 2  1
#include<iostream>
using namespace std;
int main() {
  string str1, str2;
  int res;
  int a[100];
  while (cin >> str1 >> str2 >> res) {
    cout << str1 << " " << str2 << endl;
    for (int ary = 3; ary <= 13; ary++) {
      int len = 0, carry;
      for (int i = str1.size() - 1; i >= 0; i--) {
        carry = 0;
        for (int j = str2.size() - 1; j >= 0; j--) {
          a[len++] = (str1[i] - '0')*(str2[j] - '0') % ary + carry;
          carry = (str1[i] - '0')*(str2[j] - '0') / ary;
        }
      }
      while (carry > 0) {
        a[++len] = carry % ary;
        carry /= ary;
      }
      int sum = 0;
      for (int i = len; i >= 0; i--) {
//        sum = sum * ary + a[i];
        printf("%d", a[i]);
      }printf("\n");
      break;
//      if (sum == res) {
//        printf("%d\n", ary);
//        break;
//      }
    }
  } 
}
