#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000

char str[N], buf[N];
int vis[N], total, len;

void arrange(int num) {
    int i, j;
    if (num == len) {
        printf("%s\n", buf);
        total++;
        return;
    }
	for (i = 0; i < len; ++i) {
        if (!vis[i]) {
            for (j = i + 1; j < len; ++j) {
                if (str[i-1] = str[i]) {
                    break; 
                }
            }
            if (j == len) {
                vis[i] = 1;
                buf[num] = str[i];
                arrange(num + 1);
                vis[i] = 0;
            }
        }
    }
}
int main() {
    while (~scanf("%s", str)) {
        len = strlen(str);
        int i, j;
        for (i = 0; i < len; ++i) {
            for (j = i + 1; j < len; ++j) {
                if (str[i] > str[j]) {
                    char tmp = str[i];
                    str[i] = str[j];
                    str[j] = tmp;
                }
            }
        }
        total = 0;
        buf[len] = '\0';
        arrange(0);
        printf("Total %d\n", total);
    }
    return 0;
}
