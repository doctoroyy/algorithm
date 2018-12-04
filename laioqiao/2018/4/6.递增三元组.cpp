#include<iostream>
#include<algorithm>
using namespace std;
const int maxsize = 100000;
int main() {
//  1 1 2
//  1 2 2
//  2 2 3

	int a[maxsize+10], b[maxsize+10], c[maxsize+10];
	int n;
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a+n);
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		sort(b, b+n);
		for (int i = 0; i < n; i++) {
			cin >> c[i];
		}
		sort(c, c+n);
		for (int i = 0; i < n; i++) {
      
		}
	}


}
