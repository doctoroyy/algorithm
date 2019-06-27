#include<iostream>
#include<map>
using namespace std;
int main() {
  map<char, string> mmap;
  mmap['-'] = "fu";
  mmap['0'] = "ling";
  mmap['1'] = "yi";
  mmap['2'] = "er";
  mmap['3'] = "san";
  mmap['4'] = "si";
  mmap['5'] = "wu";
  mmap['6'] = "liu";
  mmap['7'] = "qi";
  mmap['8'] = "ba";
  mmap['9'] = "jiu";

  string str;
  cin >> str;
  cout << mmap[char(str[0])];
  for (int i = 1; i < str.size(); i++) {
    cout << " " << mmap[char(str[i])]; 
  }
  return 0;
}

