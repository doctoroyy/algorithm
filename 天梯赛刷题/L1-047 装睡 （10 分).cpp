#include<iostream>
#include<vector>

using namespace std;
struct node {
  string name;
  int a, b;
};
int main() {
  int n;
  cin >> n;
  vector<string> v;
  while (n--) {
    int a, b;
    string str;
    cin >> str >> a >> b;
    if (a < 15 || a > 20 || b < 50 || b > 70) v.push_back(str);
  }
  for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
  return 0;
}

