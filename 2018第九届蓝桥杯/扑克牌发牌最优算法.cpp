#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main() {
  int a[52], n = 52;
  srand(time(0));
  for (int i = 0; i < 52; i++) a[i] = i + 1;
  for (int i = 0; i < 52; i++) {
    swap(a[i], a[rand() % 52]);
  }
  for (int i = 0; i < 52; i++) cout << a[i] << endl;
}
