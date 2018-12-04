#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, hero[1010], enemy[1010];
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> hero[i];
		}
		for (int j = 0; j < n; j++) {
			cin >> enemy[j];
		}
		sort(hero, hero + n);
		sort(enemy, enemy + n);
		if (hero[n-1] >= enemy[n-1]) {
		  cout << "0" << endl;
		  continue;
    }
		cout << enemy[n-1] - hero[n-1] << endl;
	}
	return 0;
}
