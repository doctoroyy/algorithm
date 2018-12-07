#include<iostream>
using namespace std;
int find(int x) {
  int r = x;
  while (r != pre[r]) {
    r = pre[r];
  }
  return r;
}
void join(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) {
    pre[fx] = fy;
  } 
}

int main() {
  
}
