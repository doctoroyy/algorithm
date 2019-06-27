#include<iostream>
using namespace std;
int res(int num) {
  int ans = 0;
  while (num) {
    ans += num % 10;
    num /= 10;
  }
  return ans;
} 
int main() {
  int num, runs;
  cin >> runs;
  while (runs--) {
    cin >> num;
    if (res(num / 1000) == res(num % 1000)) {
      cout << "You are lucky!";
    } else {
      cout << "Wish you good luck.";
    }
    cout << endl;
  }
  return 0;
}
