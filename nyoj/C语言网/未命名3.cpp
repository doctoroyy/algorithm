#include<iostream>
using namespace std;
void hanoi(int n, char from, char buff, char to) {
  if (n == 0) return;
  hanoi(n - 1, from, to, buff);
  cout << "move " << n << " from " << from << " to " << to << endl;
  hanoi(n - 1, buff, from, to);
}
int main() {
  int n;
  cin >> n;
  hanoi(n, 'A', 'B', 'C');
  return 0;
}

