#include<bits/stdc++.h>
using namespace std;
int pre[12];
struct youpiap {
	int x, y, flag;
} p[12];
int find(int x) {
	if(x == pre[x]) return x;
	return pre[x] = find(pre[x]);
}
void join(int n) {
	int xx = p[n].x, yy = p[n].y;
	int father = find(n);
	for(int i = 0; i < 12; i++) {
		if(i == n || p[i].flag == 0) continue;
		if((p[i].x==xx&&p[i].y==yy+1) || (p[i].x==xx&&p[i].y==yy-1) || (p[i].x==xx+1&&p[i].y==yy) || (p[i].x==xx-1&&p[i].y==yy)) {
			pre[find(i)] = father;
		}
	}
}
int main() {
	int sum = 0;
	for(int i = 0; i < 12; i++) {
		pre[i] = i;
		p[i].flag = 0;
	}
	int kk = 0;
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= 4; j++) {
			p[kk].x = i;
			p[kk].y = j;
			kk++;
		}
	for(int i = 0; i < 8; i++) {
		for(int j = i+1; j < 9; j++) {
			for(int k = j+1; k < 10; k++) {
				for(int q = k+1; q < 11; q++) {
					for(int t = q+1; t < 12; t++) {
						p[i].flag = 1, p[j].flag = 1, p[k].flag = 1, p[q].flag = 1, p[t].flag = 1;
						for(int i = 0; i < 12; i++)
							if(p[i].flag) join(i);
						set<int> s;
						for(int i = 0; i < 12; i++)
							if(p[i].flag) s.insert(find(i));
						if(s.size() == 1) sum++;
						for(int tt = 0; tt < 12; tt++)
							pre[tt] = tt;
						p[i].flag = 0, p[j].flag = 0, p[k].flag = 0, p[q].flag = 0, p[t].flag = 0;
					}
				}
			}
		}
	}
	cout << sum << endl;
	return 0;
}

