#include<iostream>
using namespace std;
int main() {
  int n, num[10010];
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> num[i];
    }
    //1 2 1 1 2
    //2 2 1 2 3 2 2 3 1
    int count = 0, left = 0, right = 1;
    while (right < n) {
      while (num[left] <= num[right] && right < n) left++, right++;
      while (num[left] >= num[right] && right < n) {
        left++, right++;
      }
      if (num[left] < num[right] && right < n) {
        count++;
        left = right;
        right = left + 1;
      }
    }
    cout << count << endl;
  }
}
