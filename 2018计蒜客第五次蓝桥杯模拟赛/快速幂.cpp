#include<iostream>
using namespace std;
//·Çµİ¹é 
int quickPow(int x, int y) {
	int res = 1, base = x;
	while (y) {
		if (y&1) res *= base;
		base *= base;
		y /= 2;
	}
	return res;
}
//µİ¹é
int pw(int x, int y, int p) {
	if (!y) {
		return 1;
	}
	int res = pw(x*x, y/2, p);
	if (y & 1) {
		res = res * x % p;
	}
	return res;
}
int main() {
	cout << quickPow(2, 10);
}
