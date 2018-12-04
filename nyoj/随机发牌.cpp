#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {
  int num[13], bucket[52];
  for (int i = 0; i < 52; i++) bucket[i] = i + 1;
  int cnt = 0;
  srand(time(0));
  while (cnt < 13) {
    num[cnt++] = bucket[rand()%52];
  }
  for (int i = 0; i < cnt; i++) printf("%d ", num[i]);
}
