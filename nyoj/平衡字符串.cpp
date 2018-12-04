#include<iostream>
#include<algorithm>
#include<cstring>
#include<deque>
using namespace std;
int main() {
  char str[110];
  while (cin >> str) {
    int left = 0, right = 0, len = strlen(str);
    for (int i = 0; i < len; i++) {
      if (str[i] <= 'm') {
        left++;
      } else {
        right++;
      }
    }
    if (left == 0) {
      for (int i = 0; i < right / 2; i++) {
        str[i] -= 13;
      }
    } else if (right == 0) {
      for (int i = 0; i < left / 2; i++) {
        str[i] += 13;
      }
    } else if (right != left) {
      if (right > left) {
        for (int i = 0, j = 0; i < len, j < right - left; i++) {
          if (str[i] > 'm') {
            str[i] = 0;
            j++;
          }
        }
      } else {
        for (int i = 0, j = 0; i < len, j < left - right; i++) {
          if (str[i] <= 'm') {
            str[i] = 0;
            j++;
          }
        }
      }
    } 
    
    for (int i = len - 1; i >= 0; i--) {
      if (str[i]) cout << str[i];
    }
    cout << endl;
  }
}
