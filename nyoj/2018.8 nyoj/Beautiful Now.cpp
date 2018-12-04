#include<iostream>
#include<cstring>
#include<fstream> 
using namespace std;

int findMinValuePos(int idx, string num) {
  char str = num[idx];
  int pos = idx;
  for (int i = idx + 1; i < num.size(); i++) {
    if (num[i] <= str) {
      str = num[i];
      pos = i;
    }
  }
  return pos;
}

int findMaxValuePos(int idx, string num) {
  char str = num[idx];
  int pos = idx;
  for (int i = idx + 1; i < num.size(); i++) {
    if (num[i] > str) {
      str = num[i];
      pos = i;
    }
  }
  return pos;
}

string getMaxString(int k, string num) {
  for (int i = 0; i < num.size(); i++) {
//    cout << "pos: " << findMaxValuePos(i, num) << endl;
    if (i != findMaxValuePos(i, num) && k) {
      swap(num[i], num[findMaxValuePos(i, num)]);
      k--;
    }
  }
  return num;
}

string getMinString(int k, string num) {
  for (int i = 0; i < num.size(); i++) {
    if (i != findMinValuePos(i, num) && k) {
      swap(num[i], num[findMinValuePos(i, num)]);
      k--;
    }
  }
  return num;
}
int main() {
  ofstream fout("out.txt"); 
  int runs, k;
  string num;
  cin >> runs;
  while (runs--) {
    cin >> num >> k;
    string min = num, max = num;
    fout << getMinString(k, min) << " " << getMaxString(k, max) << endl;
  }
  return 0;
}
//5
//12 1            min = 12, max = 21
//213 2           min = 1 23, max = 3 21
//998244353 1     min = 2 98944353, max = 998 544323
//998244353 2     min = 2 98944353 --> 23 8944359, max = 998 544323 --> 9985443 23 --> 9985443 32
//998244353 3
//238944359 2 max = 9 38244359 --> 99 8244353
