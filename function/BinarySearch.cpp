int binarySearch(int a[], int len, int key) {//返回第一个大于关键字的索引
  int l = 0, r = len - 1, mid, pos = -1;
  while (l <= r) {
    mid = (l + r) / 2;
    if (a[mid] <= key) {
      l = mid + 1;
      pos = l;
    } else {
      r = mid - 1;
      pos = mid;
    }
  }
  return pos;
}
