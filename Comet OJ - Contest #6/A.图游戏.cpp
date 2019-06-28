#include<iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
  }
  if ((n - m) % 2 == 0) cout << "Illyasviel\n";
  else cout << "Star-dust\n";
  return 0;
}

