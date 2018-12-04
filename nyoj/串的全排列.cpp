#include<iostream>
#include<cmath>
//#include<fstream>
using namespace std;
const int a[] = {0, 1, 2, 3, 4, 5, 6, 7};
int num[10], count = 0;
bool visited[10];
//ofstream fout("e:/out.txt");
bool check() {
	int sum = 0;
	for (int i = 0; i < 8; i++) {
		sum = sum * 10 + num[i];
	}
	for (int i = 2; i <= sqrt(sum) + 1; i++) {
		if (sum % i == 0) {
//		  fout << sum << " 因子是：" << i << endl;
			return false;
		}
	}
	return true;
}
void dfs(int index) {
	if (index > 8) return;
	if (index == 8) {
		if (num[0] == 0 || num[7] % 2 == 0) return;
		if (check()) {
//			cout << "找到一个!" << endl;
			count++;
		}
//		for (int i = 0; i < 9; i++) {
//			cout << num[i] << " ";
//		}
//		cout << endl;
		return;
	}
	for (int i = 0; i < 8; i++) {
		if (!visited[i]) {
			num[index] = a[i];
			visited[i] = 1;
			dfs(index+1);
			visited[i] = 0;
		}
	}
}
int main() {
	dfs(0);
	cout << count << endl;
}
