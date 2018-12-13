#include<iostream>
using namespace std;
void f(int num) {
  if (num < 10) {
    cout << num;
    return;
  }
   
 f(num/10);
 cout << num % 10;
}
int main() {
  f(123);
  return 0;
}

