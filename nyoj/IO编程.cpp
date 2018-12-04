#include<iostream>
#include<fstream>
using namespace std;
int main() {
  string filename;
  cin >> filename;
  ofstream fout(filename.c_str());
  fout << "This is a demo!\n";
  fout.close();
  ifstream fin(filename.c_str());
  char ch;
  while (fin.get(ch)) {
    cout << ch;
  }
  fin.close();
}
