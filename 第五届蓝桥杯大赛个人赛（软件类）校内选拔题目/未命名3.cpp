#include<iostream>
#include<cstring>
using namespace std;
long long mul[20];
int nums[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
int output[20];
int del[20];
void fun(int n) {
  n -= 1;

  for (int i = 12; i >= 1; i--) {
    int q = n / mul[i - 1];
    n %= mul[i - 1];
    int index = 0, cnt = 0;
    while (cnt <= q) {//在可选序列中选出第q个字符
      if (del[++index] == 0) {//跳过已选择的字符
        cnt++;
      }
    }
    output[i] = nums[index]; //将选出的字符加入到输出序列
    del[index] = 1;//在可选序列中删除
  }
}
int main() {
  mul[0] = mul[1] = 1;
  for (int i = 2; i <= 12; i++) {
    mul[i] = mul[i - 1] * i;
  }
  int t, n;
  cin >> t;
  while (t--) {
    memset(del, 0, sizeof(del)); 
    cin >> n;
    fun(n);
    for(int i = 12; i >= 1; i--) {
      cout << char(output[i] + 'a' - 1);

    }
    cout << endl;
  }
  return 0;
}

