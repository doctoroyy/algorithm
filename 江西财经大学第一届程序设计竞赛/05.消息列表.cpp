#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<set>
using namespace std;
struct node {
  int msgNum = 0;
  int exit = 0;
  int up = 0;
}msg[1000000];
int main() {
  int t, friNum;
//  int msg[1000000];
  list <node> li;
  string signal;int id;
  cin >> t;
  while (t--) {
    cin >> friNum;
    while (friNum--) {
      cin >> signal >> id;
     
      if (signal == "recv") {
       
      } else if (signal == "up") {
       
      } else if (signal == "view") {
       
      } else if (signal == "down") {
       
      }
    }
  }
}
