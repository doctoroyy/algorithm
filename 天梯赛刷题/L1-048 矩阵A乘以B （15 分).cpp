#include<iostream>
#include<vector>
using namespace std;
int main() {
  int m1, n1, n2, m2;
  cin >> m1 >> n1;
  vector<vector<int> > v1(m1);
  for (int i = 0; i < m1; i++) {
    for (int j = 0; j < n1; j++) {
      int num;
      cin >> num;
      v1[i].push_back(num);
    }
  }
  cin >> n2 >> m2;
  vector<vector<int> > v2(n2);
  for (int i = 0; i < n2; i++) {
    for (int j = 0; j < m2; j++) {
      int num;
      cin >> num;
      v2[i].push_back(num);
    }
  }
  vector<vector<int> > out(m1);

  if (n1 != n2) {
    cout << "Error: " << n1 << " != " << n2;
  } else {
    for (int i = 0; i < m1; i++) {
      for (int j = 0; j < m2; j++) {
        int res = 0;
        for (int k = 0; k < n1; k++) {
          res += v1[i][k] * v2[k][j];
        }
        out[i].push_back(res);
      }
    }
    cout << m1 << " " << m2 << endl;
    for (int i = 0; i < m1; i++) {
      for (int j = 0; j < m2; j++) {
        cout << out[i][j];
        if (j < m2 - 1) cout << " ";
      }
      if (i < m1 - 1) cout << endl;
    }
  }

  return 0;
}

