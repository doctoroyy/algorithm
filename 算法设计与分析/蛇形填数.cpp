//(3)编程打印如图3-5的n*n方阵 
#include<iostream>
#include<cstdio>
using namespace std;
int a[110][110];
int main() {
	int n;
	while (cin >> n) {
	  int cnt = 0;
	  for (int i = 0; i <= (n - 1) / 2; i++) {

	    for (int j = i; j <= n - i - 1; j++) { 
	      a[i][j] = ++cnt; //00 01 02 03             11 12
	    }
	    for (int j = i + 1; j <= n - i - 1; j++) {
	      a[j][n - i - 1] = ++cnt; //13 23 33      22
	    }
	    for (int j = n - i - 1 - 1; j >= i; j--) {
	      a[n - i - 1][j] = ++cnt; //32 31 30    21
	    }
	    for (int j = n - i - 1 - 1; j > i; j--) {
	      a[j][i] = ++cnt; //20 10 
	    }
	  }
	  for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
	      printf("%3d", a[i][j]);
	    }
	    printf("\n");
	  }
	}
}
/*
            1   2   3   4
            12  13  14  5
            11  16  15  6
            10  9   8   7
            
*/

