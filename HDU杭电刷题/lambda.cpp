#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Student {
  string name;
  int math, chinese, english;
};
vector<Student> v;
void print() {
  cout << "rank:\n";
  for (auto it:v) {
    cout << it.name << " " << it.math << " " << it.chinese << " " << it.english << endl;
  }
}
int main() {
  v.push_back(Student {"dxl", 90, 80, 89});
  v.push_back(Student {"xm", 93, 86, 87});
  v.push_back(Student {"oyy", 87, 81, 90});
  sort(v.begin(), v.end(), [](const Student &a, const Student &b) {
    return a.math < b.math;
  });
  print();
  sort(v.begin(), v.end(), [](const Student &a, const Student &b) {
    return a.chinese < b.chinese;
  });
  print();
  sort(v.begin(), v.end(), [](const Student &a, const Student &b) {
    return a.english < b.english;
  });
  print();
  return 0;
}
