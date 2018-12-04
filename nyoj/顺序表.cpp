#include<iostream>
using namespace std;
const int maxn = 110;
int a[maxn];
int size, n;
int findEleByIndex(int index) {
  return a[index];
}
void deleteEleByIndex(int index) {
  a[index] = 0;
}
void insert(int pos, int num) {
  for (int i = n - 1; i >= pos - 1; i--) {
    a[i + 1] = a[i];
  }
  a[pos - 1] = num;
}
void printArr() {
  for (int i = 0; i < n; i++) {
    if (a[i]) cout << a[i] << " ";
  }
}
int main() {
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> a[i]; 
    }
    printArr();
  }
  return 0;
}

