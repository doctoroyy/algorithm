#include<iostream>
#include<vector>
#include<map>
using namespace std;
struct node {
  string id;
  int msgNum;
}msg;
int main() {
//  map <string, int> msg;
  vector <msg> List;
  int t, friNum;
  string signal, id;
  cin >> t;
  while (t--) {
    cin >> friNum;
    while (friNum--) {
      cin >> siginal >> id;
      msg[id]++;
      switch (signal) {
        case "recv":
          List.insert(0, msg);
          break;
        case "up":
          List.insert(0, msg);
          break
        case "view":
          msg[id] = 0;
        
          break;
        case "down":
          
          break;
        case "delete":
          for (int i = 0; i < List.)
          break;
      }
    }
  }
}
