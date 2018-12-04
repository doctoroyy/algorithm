/*
威佐夫博弈
 
必败局势：
0，0）、（1，2）、（3，5）、（4，7）、
（6，10）、（8，13）、（9，15）、
（11，18）、（12，20）、...... 、
（ak，bk） (k = 0, 1, 2, 3,......)。 

ak = [ k * (1 + √5) / 2 ], ([x]表示对x取整) 
bk = ak + k 
*/ 
#include<iostream>
#include<cmath>
using namespace std;
int main() {
  int a, b;
  while (cin >> a >> b) {
    if (a > b) swap(a, b);
    int k = b - a;
    int ak = 1.0 * k * (1 + sqrt(5)) / 2;
    if (ak == a) {
      cout << "0";
    } else {
      cout << "1";
    }
    cout << endl;
  }
  return 0;
} 
