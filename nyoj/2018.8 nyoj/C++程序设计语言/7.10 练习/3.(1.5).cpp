#include<iostream>
#include<cstdarg>
using namespace std;
void printStr(int n, ...) {
  va_list ap;
  va_start(ap, n);
  for (int i = 0; i < n; i++) {
    char* p = va_arg(ap, char*);
    cout << "hello: " << p << endl;
  }
  va_end(ap);
}
//int max(int n, ...) { // 定参 n 表示后面变参数量，定界用，输入时切勿搞错
//  va_list ap;       // 定义一个 va_list 指针来访问参数表
//  va_start(ap, n);     // 初始化 ap，让它指向第一个变参
//  int maximum = -0x7FFFFFFF;   // 这是一个最小的整数
//  int temp;
//  for(int i = 0; i < n; i++) {
//    temp = va_arg(ap, int);   // 获取一个 int 型参数，并且 ap 指向下一个参数
//    if (maximum < temp)
//      maximum = temp;
//  }
//  va_end(ap);       // 善后工作，关闭 ap
//  return maximum;
//}


int main() {
//  cout << max(4, 1, -1, 0, 7, 3);
  printStr(3, "fsdgv", "swef", "ef");
  return 0;
}

