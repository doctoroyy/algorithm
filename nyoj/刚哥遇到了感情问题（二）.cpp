#include<iostream>
#include<algorithm>
using namespace std;
int main() {
  string letter;
  while (getline(cin, letter)) {
    for (int i = 0; i < letter.size(); i++) {
      if (letter.substr(i, 5) == "apple") {
        letter.replace(i, 5, "miss");
      } else if (letter.substr(i, 6) == "banana") {
        letter.replace(i, 6, "love");
      } else if (letter.substr(i, 6) == "orange") {
        letter.replace(i, 6, "kiss");
      }
    }
    cout << letter << endl;
  }
}
