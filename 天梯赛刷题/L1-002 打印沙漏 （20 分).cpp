#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
  int n; 
  char ch;
  cin >> n >> ch;
  int num = sqrt((n + 1) / 2), stars = 2 * num - 1, spaces = 0, d = 2;
  for (int i = 0; i < 2 * num - 1; i++) {
    for (int j = 0; j < spaces / 2; j++) {
      cout << " "; 
    }
    for (int j = 0; j < stars; j++) {
      cout << ch;
    }
    cout << endl;
    if (stars == 1) d = -d;
    spaces += d; 
    stars -= d;
  }
  cout << n - (2 * num * num - 1);
  return 0;
}

