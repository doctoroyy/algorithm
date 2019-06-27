#include<iostream>
#include<vector> 
using namespace std;
int main() {
  int num;
  vector<int> v;
  cin >> num;
  v.push_back(num);
  while (cin.get() != '\n') {
    cin >> num;
    v.push_back(num);
  }
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == 250) {
      cout << i + 1;
      break;
    }
  }
  return 0;
}

