#include<iostream>
#include<cstdlib>
#include<stack>
#include<cstring> 
using namespace std;
int main() {
  char str[1000];
  stack <double> f;
  string ch[1010];
  while (gets(str)) {
    int j = 0;
    for (int i = 0; i < strlen(str); i++) {
      if (str[i] != ' ') {
        ch[j] += str[i];
      } else {
        j++;
      }
    }
    for (int i = 0; i <= j; i++) {
      cout << ch[i];
    }
    cout << endl;
  }
}
