#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int f[10000], b[10000];
int max(int a, int b) {
    return a > b ? a : b;
}
int lis(int n) {
    memset(f, 0, sizeof f);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (b[j] < b[i]) {
                f[i] = max(f[j] + 1, f[i]);
            }
        }
        res = max(res, f[i]);
    }
    return res+1;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", b + i);
    }
    printf("%d\n", lis(n));
    return 0;
}
