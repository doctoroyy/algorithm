#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int t, n, m;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d%d", &n, &m);
		string a, b, c;
		cin >> a >> b >> c;
//		cout << "\n";
//		cout << a << "\n" <<  b  << "\n" << c << endl;
		int shifts = b[0] - a[0];
//		cout << shifts << endl;

		for (int j = 0; j < c.size(); j++) {
			if (c[j] - shifts < 'A' ) c[j] += 26;
			if (c[j] - shifts > 'Z') c[j] -= 26; 
			c[j] = c[j] - shifts;
//			cout << c[j] << endl;
		}
		printf("Case #%d: ", i);

		cout << c << endl;
	}
}
