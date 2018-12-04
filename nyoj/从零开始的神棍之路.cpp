#include<iostream>
#include<algorithm>

using namespace std;
bool ph(int card[], int l, int r) {
	int sum = 0;
	for (int i = l; i < r; i += 3) {
		if (card[i] == card[i+1] && card[i+1] == card[i+2]) {
			sum++;
		}
	}
	cout << "23333 ph is sum = " << sum << endl;
	return sum == 4;
}
bool ddh(int card[], int l, int r) {
	int sum = 0;
	for (int i = l; i < r; i += 3) {
		if (card[i] == card[i+1]-1 && card[i+1] == card[i+2]-1) {
			sum++;
		}
	}
	cout << "23333 ddh is sum = " << sum << endl;

	return sum == 4;
}

bool _1(int card[], int l, int r) {
	int sum = 0;
	for (int i = l; i < r; i += 3) {
		if ((card[i] == card[i+1]-1 && card[i+1] == card[i+2]-1) ||
		        (card[i] == card[i+1] && card[i+1] == card[i+2])
		   ) {
			sum++;
		}
	}
	if (sum == 4) {

		for (int i = 0; i < 14; i++) {
			int tmp = card[i] % 9 == 0 ? 9 : card[i] % 9;
			if (tmp == 1 || tmp == 9) return false;
		}
		return true;
	}
	return false;
}
bool _2(int card[], int l, int r) {
	int sum = 0;
	bool f1 = false, f2 = false;
	for (int i = l; i < r; i += 3) {
		if ((card[i] == card[i+1]-1 && card[i+1] == card[i+2]-1) ||
		        (card[i] == card[i+1] && card[i+1] == card[i+2])
		   ) {

			sum++;
		}
	}
	if (sum == 4) {
		if (l == 2) {
			for (int i = 0; i < 2; i++) {
				int tmp = card[i] % 9 == 0 ? 9 : card[i] % 9;
				if (tmp == 1 || tmp == 9) f1 = true;
			}
			if (f1) {
				for (int i = 2; i < 14; i+=3) {
					for (int j = i; j < i + 3; j++) {
						int tmp = card[j] % 9 == 0 ? 9 : card[j] % 9;
						if (tmp == 1 || tmp == 9) f2 = true;
					}
					if (!f2) return false;
				}
			}
		} else {


			for (int i = 0; i < 12; i+=3) {
				for (int j = i; j < i + 3; j++) {
					int tmp = card[j] % 9 == 0 ? 9 : card[j] % 9;
					if (tmp == 1 || tmp == 9) f2 = true;
				}
				if (!f2) return false;
			}
			if (f2) {
				for (int i = 12; i < 14; i++) {
					int tmp = card[i] % 9 == 0 ? 9 : card[i] % 9;
					if (tmp == 1 || tmp == 9) f1 = true;
				}
				return f1;
			}


		}

		return true;
	}
	return false;
}
bool is2222222(int card[]) {
	int sum = 0;
	for (int i = 0; i < 14; i+=2) {
		if (card[i] == card[i+1]) {
			sum++;
		}
	}
	cout << "2222222  : " << sum << endl;
	return sum == 7;
}
bool is23333(int card[]) {

	if (card[0] == card[1] &&
	        ((card[11] == card[12] && card[12] == card[13]) ||
	         (card[11] == card[12]-1 && card[12] == card[13]-1)
	        )) {
		if (ph(card, 2, 14)) {
			return true;
		} else if (ddh(card, 2, 14)) {
			return true;
		} else if (_1(card, 2, 14)){
			return true;
		} else {
		  return _2(card, 2, 14);
    }
//		return (ph(card, 2, 14) || ddh(card, 2, 14) || (!ph(card, 2, 14) && !ddh(card, 2, 14) &&_12(card, 2, 14)));
	} else if (card[12] == card[13] &&
	           ((card[0] == card[1] && card[1] == card[2] ) ||
	            (card[0] == card[1]-1 && card[1] == card[2]-1)
	           )
	          ) {
		if (ph(card, 0, 12)  ) {
			return true;
		} else if ( ddh(card, 0, 12)) {
			return true;
		}  else if (_1(card, 0, 12)){
			return true;
		} else {
		  return _2(card, 0, 12);
    }

//		return (ph(card, 0, 12) || ddh(card, 0, 12) || (!ph(card, 0, 12) && !ddh(card, 0, 12) && _12(card, 0, 12)));
	}
	return false;


}

int main() {
	int runs;
	cin >> runs;
	while (runs--) {
		int card[14];
		for (int i = 0; i < 14; i++) {
			cin >> card[i];
		}
		sort(card, card+14);
		cout << "res2222222:"<< is2222222(card) << "res23333:"  << is23333(card) << endl;
		cout << (int)(is2222222(card) || is23333(card)) << endl;
	}

}
