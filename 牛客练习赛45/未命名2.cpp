#include<iostream>
using namespace std;
struct node {
  int a, b, c;
};
int cmp(node x, node y) {
  if (x.a != y.a) return x.a > y.a;
  if (x.b != y.b) return x.b < y.b;
  if (x.c != y.c) return x.c < y.c;
  return -1;
}
int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  
  if (cmp(node{a, b, c}, node{d, e, f}) == 1) {
    cout << "1";
  } else if (cmp(node{a, b, c}, node{d, e, f}) == 0) {
    cout << "2";
  } else {
    cout << "God";
  }
  return 0;
}

