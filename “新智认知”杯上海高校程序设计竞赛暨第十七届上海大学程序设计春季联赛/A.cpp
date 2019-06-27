#include<iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n >= 3) {
    cout << "BigBoLang\n";
  } else if (n >= 2) {
    cout << "YingHuaTang\n";
  } else if (n >= 1){
    cout << "XiZhiTang\n";
  } else {
    cout << "None\n"; 
  }
  return 0;
}

