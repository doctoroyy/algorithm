#include<stdio.h>
//long long Binary_Search(long long left, long long right, long long key) {
//  if (left == right && right == key) {
//    return 1;
//  }
//  int mid, count = 0;
//  while (left < right) {
//    mid = (left + right) / 2;
//    count++;
//    if (mid == key) {
//      return count;
//    } else if (key > mid) {
//      left = mid + 1;
//    } else {
//      right = mid;
//    } 
//  }
//  return count;
//}
int main() {
  int begin, end, key, testcase;
  scanf("%d", &testcase);
  while (testcase--) {
    scanf("%d%d%d", &begin, &end, &key);
    int i, mid;
    for (i = 1; ; i++) {
      mid = (begin + end) / 2;
      if (mid == key) {
        break;
      } else if (mid < key) {
        begin = mid + 1;
      } else {
        end = mid;
      }
    }
    if (i&1) {
      printf("Win\n");
    } else {
      printf("Lose\n");
    }
  }
} 
