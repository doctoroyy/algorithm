#include<iostream>
#include<vector>
using namespace std;
int ref[2][2] = {129, 25, 130, 27};
int main() {
  int runs;
  cin >> runs;
  vector<string> v;
  while (runs--) {
    int id, h, w;
    cin >> id >> h >> w;
    if (h < ref[id][0]) v.push_back("duo chi yu! ");
    else if (h > ref[id][0]) v.push_back("ni li hai! ");
    else v.push_back("wan mei! ");
    if (w < ref[id][1]) v.push_back("duo chi rou!");
    else if (w > ref[id][1]) v.push_back("shao chi rou!");
    else v.push_back("wan mei!");
  }
  for (int i = 0; i < v.size() / 2; i++) {
    cout << v[2 * i] << v[2 * i + 1];
    if (i < v.size() / 2 - 1) cout << endl;
  } 
  return 0;
}

