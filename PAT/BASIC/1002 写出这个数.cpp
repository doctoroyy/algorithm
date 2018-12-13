#include<iostream>
using namespace std;
string num2pinyin[] = {"ling", "yi", "er", "san", "si", 
"wu", "liu", "qi", "ba", "jiu" 
};
void returnNumPinyin(int num) {
  if (num < 10) {
    cout << num2pinyin[num];
    return;
  }
  returnNumPinyin(num / 10);
  cout << " " << num2pinyin[num % 10];
}
int main() {
  string num;
  cin >> num;
  int sum = 0;
  for (int i = 0; i < num.size(); i++) sum += num[i] - '0';
  returnNumPinyin(sum);
  return 0;
}

