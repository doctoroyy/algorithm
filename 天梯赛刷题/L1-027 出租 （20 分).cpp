#include<iostream>
#include<vector>
using namespace std;
int main() {
  string num;
  cin >> num;
  int target[10] = {0};
  for (int i = 0; i < num.size(); i++) {
    target[num[i] - '0']++;
  }
  vector<int> v, index;
  for (int i = 9; i >= 0; i--) {
    if (target[i] != 0)
      v.push_back(i);
  }
  
  for (int i = 0; i < num.size(); i++) {
    for (int j = 0; j < v.size(); j++) {
      if (num[i] - '0' == v[j]) {
        index.push_back(j);
      }
    }
  }
  cout << "int[] arr = new int[]{";
  for (int i = 0; i < v.size(); i++) {
    cout << v[i];
    if (i < v.size() - 1) cout << ",";
  }
  cout << "};\n";
  
  cout << "int[] index = new int[]{";
  for (int i = 0; i < index.size(); i++) {
    cout << index[i];
    if (i < index.size() - 1) cout << ",";
  }
  cout << "};";
  return 0;
}
/*
int[] arr = new int[]{8,3,2,1,0};
int[] arr = new int[]{8,3,2,1,0};
int[] index = new int[]{3,0,4,3,1,0,2,4,3,4,4};
int[] index = new int[]{3,0,4,3,1,0,2,4,3,4,4};
*/
