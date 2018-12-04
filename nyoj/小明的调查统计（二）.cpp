 
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct stu {
  int score, cno, sno, rank;
}s[100010];
bool cmp(stu a, stu b) {
  if (a.score != b.score) return a.score > b.score;
  if (a.cno != b.cno) return a.cno < b.cno;
  if (a.sno != b.sno) return a.sno < b.sno;
}
int main() {
  int t, m, sco;
  scanf("%d%d", &t, &m);
  int num = 1;
  for (int i = 1; i <= t; i++) {
    int n;
    scanf("%d", &n);
    for (int j = 1; j <= n; j++) {
      scanf("%d", &s[num].score);
      s[num].cno = i;
      s[num].sno = j;
      num++;
    }
  }
  sort(s+1, s + num, cmp);
  
  s[1].rank = 1;
  for (int i = 2; i <= num; i++) {
    if (s[i].score == s[i-1].score)  {
      s[i].rank = s[i-1].rank;
    } else {
      s[i].rank = s[i-1].rank + 1;
    }
  }
//  for (int i = 1; i < num; i++) {
//    printf("%d %d %d %d\n", s[i].cno, s[i].sno, s[i].score, s[i].rank);
//  }
  while (m--) {
    int q;
    scanf("%d", &q);
    for (int i = 1; i < num; i++) {
      if (s[i].rank == q) {
        printf("%d %d\n", s[i].cno, s[i].sno);
      }
    }
  }
}         
