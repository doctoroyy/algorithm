#include<iostream>
#include<cstdio> 
using namespace std;
int main() {
  int hh, mm;
  scanf("%d:%d", &hh, &mm);
  if (hh >= 0 && hh <= 12) {
    printf("Only %02d:%02d.  Too early to Dang.", hh, mm);
  } else {
    for (int i = 0; i < hh  - 12 + (mm > 0); i++) cout << "Dang";
    
  }
  return 0;
}

