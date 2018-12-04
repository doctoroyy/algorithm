#include<iostream>
#include<cstdio>
using namespace std;
int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isLeapYear(int year) {
	return (year % 100 != 0 && year % 4 == 0) || (year % 400 == 0);
}
//int DateToInt(int y, int m, int d) {
//	int tmp = y - 1;
//	int sum = tmp*365 + tmp/4 + tmp/400 - tmp/100;
//	for (int i = 1; i < m; i++) {
//		sum += month[i];
//	}
//	sum += d;
//	if (isLeapYear(y) && m > 2) {
//		sum++;
//	}
//	return sum;
//}
int findNum(int pat, int num) {
	while (pat) {
		if (pat % 10 == num) {
			return 1;
		}
		pat /= 10;
	}
	return 0;
}
int cal(int y, int m, int d) {
	int sum = 0;
	if (isLeapYear(y)) {
    month[2] = 29;
  } else {
    month[2] = 28;
  }
  for (int i = d; i <= month[m]; i++) {
    if (findNum(m, 4) || findNum(y, 4)) break;
    if (!findNum(i, 4)) sum++;
  }
  
  
	for (int i = m + 1; i <= 12; i++) {
	  if (findNum(y, 4)) break;
	  if (findNum(i, 4)) continue;
	  for (int j = 1; j <= month[i]; j++) {
	    if (!findNum(j, 4)) {
	      sum++;
      }
    }
  }
	
  for (int i = y + 1; i < 2018; i++) {
    if (findNum(i, 4)) continue;
    if (isLeapYear(i)) {
      month[2] = 29;
    } else {
      month[2] = 28;
    }
    for (int j = 1; j <= 12; j++) {
      if (findNum(j, 4)) continue;
      for (int k = 1; k <= month[j]; k++) {
        if (!findNum(k, 4)) {
          sum++;
        }
      }
    }
  }
  sum += 81;
  return sum;
}
int main() {
	int y, m, d;
	while (~scanf("%d-%d-%d", &y, &m, &d)) {
		cout << cal(y, m, d) << endl;
	}
}
