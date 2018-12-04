#include<stdio.h>
int used[10], 
square[3][4] = {0};// (0, 0) (2, 3)²»Ìî 
int count = 0;
void dfs(int raw, int col) {
  if (raw == 2 && col == 2) {
    count++;
    return;
  }
  for (int i = raw; i < 3; i++) {
    for (int j = col; j < 4; j++) {
      for (int k = 0; k < 10; k++) {
        if (a[k] == 0) {
          square[i][j] = k;
          used[k] = 1;
          dfs()
        }
      }
    }
  } 
}

int main() {
  
} 
