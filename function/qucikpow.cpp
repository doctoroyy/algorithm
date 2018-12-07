int qucikpow(int m, int n) {
  int base = m, res = 1;
  while (n) {
    if (n & 1) res *= base;
    base *= base;
    n >>= 1;
  }
  return res;
}
