#include<iostream>
#include<fstream>
using namespace std;
int main() {
  ofstream fout("e:/112.txt");
  for (int a = 1; a <= 12 - 4; a++) {
    for (int b = a + 1; b <= 12 - 3; b++) {
      for (int c = b + 1; c <= 12 - 2; c++) {
        for (int d = c + 1; d <= 12 - 1; d++) {
          for (int e = d + 1; e <= 12; e++) {
            fout << a << " " << b << " " << c << " " << d << " " << e << endl;
          }
        }
      }
    }
  }
  cout << "0";
}
