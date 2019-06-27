#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1e5 + 10;
long long sum[maxn];
int main() {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }
  sort(v.begin(), v.end());
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + v[i - 1];
  }
  int index = n / 2;
  if (n & 1) {

    if (sum[n] - 2 * sum[index] < sum[n] - 2 * sum[index + 1]) {
      index += 1;
    }
    cout << "Outgoing #: " << max(index, n - index) << "\n" << "Introverted #: " << min(index, n - index) << endl;
  } else {
    cout  << "Outgoing #: " << n / 2 << "\n" << "Introverted #: " << n / 2 << endl;
  }
  cout << "Diff = " << sum[n] - 2 * sum[index];
  return 0;
}
