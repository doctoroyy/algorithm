#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int cmp(char a) {
  if (a == '+' || a == '-') {
    return 1;
  } else if (a == '*' || a == '/') {
    return 2;
  }
  return 0;
}     
int main() {
  char str[1010];
  int n;
  cin >> n;
  getchar();
  while (n--) {
    stack <char> ch;
    queue <char> num;
    gets(str);
//    getline(cin, str);
    for (int i = 0; str[i] != 0; i++) {
      if (str[i] >= '0' && str[i] <= '9') {
        num.push(str[i]);
      } else if (str[i] == '(') {
        ch.push(str[i]);
      } else if (str[i] == ')') {
        while (ch.top() != '(') {
          num.push(ch.top());
          ch.pop();
        }
        ch.pop();
      } else if (ch.empty()) {
        ch.push(str[i]);
      } else if (cmp(str[i]) > cmp(ch.top())) {
        ch.push(str[i]);
      } else {
        while (!ch.empty() && cmp(str[i]) <= cmp(ch.top())) {
          num.push(ch.top());
          ch.pop();
        }
        ch.push(str[i]);
      }
    }
    while (!ch.empty()) {
      num.push(ch.top());
      ch.pop();
    }
    while (!num.empty()) {
      cout << num.front();
      num.pop();
    }
    cout << endl;
  }
}
