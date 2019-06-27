#include<bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin>>n;
  queue<int> q;
  int sum = 1, k, count = 1;
  while(1) {
    if (sum < n) {
      q.push(0);
      sum = sum*10+1;
    } else if (sum % n == 0) {
      q.push(1);
      break;
    } else {
      q.push(sum/n);
      sum = (sum%n)*10+1;
    }
    count++;
    cout << "*\n";
  }
  for (int i = 0; i < count; i++) {
    if (!q.front()) {
      q.pop();
    } else {
      break;
    }
  }
  k = q.size();
  for (int i = 0; i < k; i++) {
    cout<<q.front();
    q.pop();
  }
  cout<<" "<<count<<endl;
}
