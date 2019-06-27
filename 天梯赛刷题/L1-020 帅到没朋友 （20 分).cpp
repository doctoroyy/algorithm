#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
using namespace std;
int main() {
  long long n, k, m;
  map<long long, long long> mmap;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      long long id;
      cin >> id;
      if (k != 1) mmap[id] = 1;
      
    }
  }
  cin >> m;
  vector<long long> v;

  for (int i = 0; i < m; i++) {
    long long idd;
    cin >> idd;
    if (mmap[idd] != 1) v.push_back(idd); //坑点: 要排除一个人朋友圈的情况 
  }

  if (v.size() == 0) {
    cout << "No one is handsome";
  } else {
    map<long long, long long> mmap2;
    if (mmap2[v[0]] != 1) {
      printf("%05d", v[0]);
      mmap2[v[0]] = 1;
    }

    for (int i = 1; i < v.size(); i++) {
      if (mmap2[v[i]] != 1) {
//				cout << " " << v[i];
        printf(" %05d", v[i]);
        mmap2[v[i]] = 1;
      }
    }
  }
  return 0;
}



