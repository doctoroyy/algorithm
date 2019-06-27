#include<iostream>
#include<map>
using namespace std;
int main() {
  int num[10] = {0};
  string n;
  cin >> n;
  for (int i = 0; i < n.size(); i++) {
    num[char(n[i]) - '0']++;
  }
  for (int i = 0; i < 10; i++) {
    if (num[i]) {
      cout << i << ":" << num[i] << endl;
    }
  }
  return 0;
}

