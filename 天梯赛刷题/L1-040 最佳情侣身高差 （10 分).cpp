#include<iostream>
using namespace std;
int main() {
  int runs;
  double h;
  char ch;
  cin >> runs;
  while (runs--) {
    cin >> ch >> h;
    if (ch == 'M') {
      printf("%.2lf", h / 1.09);
    } else {
      printf("%.2lf", h * 1.09);
    }
    cout << endl; 
  }
  return 0;
}

