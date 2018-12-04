/*9090000078001234 6
9900000078001234 5
9907000008001234 0

*/
#include<stdio.h>
#include<string.h>
void swap(char &a, char &b) {
  char t = a;
  a = b;
  b = t;
}
int main() {
  int k;
  char str[20];
  while (~scanf("%s%d", str, &k)) {
    int len = strlen(str), pos;
    for (int i = 0; i < len; i++) {
      pos = i;
      for (int j = i + 1; j <= i + k && j < len; j++) {
        if (str[j] > str[pos]) pos = j;
      }
      for (int j = pos; j > i; j--) {
        swap(str[j], str[j-1]);
      }
      k -= pos - i;
    }
    if (k == 0) {
      puts(str);
      continue;
    }
    puts(str);
  }
}

