#include<iostream>
#include<vector> 
#include<cmath>
using namespace std;
struct node {
  string str;
  int n;
}ns[10100];
int main() {
  int n;
  cin >> n;
  long long tot = 0;
  for (int i = 0; i < n; i++) {
    
    cin >> ns[i].str >> ns[i].n;
    tot += ns[i].n;
  }
  long long ave = tot / n / 2, pos = 0, value_min = 100; 
  for (int i = 0; i < n; i++) {
    if (abs(ns[i].n - ave) < value_min) {
      value_min = abs(ns[i].n - ave);
      pos = i;
    }
  }
  cout << ave << " " << ns[pos].str;
  return 0;
}

