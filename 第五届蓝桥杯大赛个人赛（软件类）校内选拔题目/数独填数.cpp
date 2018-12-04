#include<iostream>
using namespace std;

int matrix[9][9] = {
  0,0,5,3,0,0,0,0,0,
  8,0,0,0,0,0,0,2,0,
  0,7,0,0,1,0,5,0,0,
  4,0,0,0,0,5,3,0,0,
  0,1,0,0,7,0,0,0,6,
  0,0,3,2,0,0,0,8,0,
  0,6,0,5,0,0,0,0,9,
  0,0,4,0,0,0,0,3,0,
  0,0,0,0,0,9,7,0,0
};
int valid(int r, int c, int num) {
  for (int i = 0; i < 9; i++) {
    if (matrix[r][i] == num || matrix[i][c] == num) {
      return false;
    }
  }

  int tmpx = r / 3, tmpy = c / 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (matrix[tmpx * 3 + i][tmpy * 3 + j] == num) {
        return false;
      }
    }
  }
  return true;
}
void printMat() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << matrix[i][j];
    }
    cout << endl;
  }
}
void dfs(int index) {
  
  if (index == 81) {
    printMat();
    return;
  }

  int raw = index / 9;
  int col = index % 9;


  if (matrix[raw][col] == 0) {
    for (int i = 1; i < 10; i++) {
      if (valid(raw, col, i)) {
        matrix[raw][col] = i;
        dfs(index + 1);
        matrix[raw][col] = 0;
      }
    }
  } else {
    dfs(index + 1);
  }
}

int main() {
  dfs(0);
  return 0;
}

