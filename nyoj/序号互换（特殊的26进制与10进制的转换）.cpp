#include<stdio.h>
#include<string.h>
bool ary_26(char* str) {
  int i = 0;
  while (str[i] != '\0') {
    if (str[i++] >= 'A') return true;
  }
  return false;
}
int ary_26_to_10(char* str) {
  int len = strlen(str), sum = 0, p = 1;
  for (int i = len - 1; i >= 0; i--) {
    if (str[i] == 'Z') {
      sum += p * 26;
    } else {
      sum += p * (str[i] - 'A' + 1);
    }
    p *= 26;
  }
  return sum;
}
void ary_10_to_26(int num) {
  char str[100];
  int len = 0, t = num;
  while (t) {
    str[len++] = (t - 1) % 26 + 'A';
    t = (t - 1) / 26;
  }
  if (num < 27) {
    printf("%c", str[0]);
    return;
  }
  for (int i = len - 1; i >= 0; i--) printf("%c", str[i]);
}
int ch_to_Int(char* str) {
  int i = 0, sum = 0;
  while (str[i] != '\0') {
    sum = sum * 10 + str[i++] - '0';
  }
  return sum;
}
int main() {
  int t;
  scanf("%d", &t);
  getchar();  
  while (t--) {
    char str[20];
    scanf("%s", str);
    if (ary_26(str)) {
      printf("%d\n", ary_26_to_10(str));
    } else {
      ary_10_to_26(ch_to_Int(str));
      printf("\n");
    }
  }
}
