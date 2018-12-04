#include<iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {

    string king, a, b;
    cin >> king >> a >> b;
    int value_a = int(a[0]), value_b = int(b[0]);

    //特殊
    if (a[0] == 'A') value_a = 1;
    if (b[0] == 'A') value_b = 1;
    if (a[0] == '1') value_a = '9' + 1;
    if (b[0] == '1') value_b = '9' + 1;
    
//    cout << value_a << " " << value_b << endl;
    int ascore = 0, bscore = 0;
    if (king[0] == a[a.size() - 1]) ascore += 2;//权重加大，即使后来牌面大也大不过王牌 
    if (king[0] == b[b.size() - 1]) bscore += 2;
    if (value_a > value_b) {
      ascore++;
    } else if (value_b > value_a) {
      bscore++;
    }
    
    if (ascore > bscore) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << endl;

  }
  return 0;
}

