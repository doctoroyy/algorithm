#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
#include<queue>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
const int maxn = 1000 + 10;
struct node {
	double tot, cnt;
};
bool cmp(const node &a, const node &b) {
	return (a.tot / a.cnt) > (b.tot / b.cnt);
}
int main() {
	double n, d;
	cin >> n >> d;
	vector<node> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].cnt;
	}
	for (int i = 0; i < n; i++) {
		cin >> v[i].tot;
	}
	sort(v.begin(), v.end(), cmp);

	double ans = 0.0;
//	for (int i = 0; i < v.size(); i++) cout << v[i].tot << " " << v[i].cnt << endl;
	
	for (int i = 0; i < n; i++) {
		if (v[i].cnt <= d) {
		  d -= v[i].cnt;
		  ans += v[i].tot;
    } else {
      ans += d * (v[i].tot / v[i].cnt);
      break;
    }
	}
	printf("%.2lf", ans);

	return 0;
}



