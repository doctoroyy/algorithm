#include<iostream>
using namespace std;
int main() {
	string str;
	
	while (getline(cin,str)) {
	  bool flag = true;
	  int sum = 0;
		for (int i = str.size(); i >= 0; i--) {
			if(str[i] == ' ') {
			  flag = !flag;
      }
      if (flag) {
        sum++;
      }
		}
		cout << sum << endl;
	}
	return 0;
}
