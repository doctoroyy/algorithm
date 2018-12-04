#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxsize = 10000;
struct student {
  char name[15];
  int score;
}stu[maxsize+10];
bool cmp(const student a, const student b) {
  return a.score < b.score;
}
int Binary_Search(student stu[], int n, int key) {
  int left = 0, right = n - 1, mid;
  while (left <= right) {
    mid = (left + right) / 2;
    if (stu[mid].score > key) {
      right = mid - 1;
    } else if (stu[mid].score < key) {
      left = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}
int main() {
  int t, n, m, query;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%s%d", stu[i].name, &stu[i].score);
    }
    stable_sort(stu, stu + n, cmp);
    for (int i = 0; i < m; i++) {
      scanf("%d", &query);
      int code = Binary_Search(stu, n, query);
      while (stu[code-1].score == query && code > 0) code--;
      printf("%s\n", stu[code].name);
    } 
  }
}
