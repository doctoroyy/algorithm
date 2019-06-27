#include<iostream>
#include<vector>
using namespace std;
struct node {
  int id;
  string name;
};
int main() {
  int num;
  cin >> num;
  vector<node> v;
  for (int i = 0; i < num; i++) {
    int id;
    string name;
    cin >> id >> name;
    v.push_back(node{id, name});
  }
  num /= 2;
  for (int i = 0; i < num; i++) {
    for (int j = v.size() - 1; j > i; j--) {
      if (v[i].id + v[j].id == 1) {
        cout << v[i].name << " " << v[j].name << endl;
        v.erase(v.begin() + j);
        break;
      }
    }
  }
  return 0;
}

