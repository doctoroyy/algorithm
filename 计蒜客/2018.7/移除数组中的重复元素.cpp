#include<iostream>
using namespace std;
int main() {
	int n, a[1010];
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int pos = 0, sum = 1;
		while (pos + 1 < n) {
			if (a[pos] != a[pos+1]) {
				++sum;
			}
			pos++;
		}
		cout << sum << endl;
	}
	return 0;
}
