vector<string> split(string str, string regx) {
  vector<string> arr;
  int offset = 0;
  for (int i = 0; str[i]; ++i) {
    if (str[i] == regx[0]) {
      arr.push_back(str.substr(offset, i - 1 - offset + 1));
      offset = i + 1;
    }
  }
  arr.push_back(str.substr(offset));
  return arr;
}
map<string, int> dic;

long long hex2ten(vector<string> arr) {
  long long  res = 0;
  for (int i = 0; i < arr.size(); i++) {
    res = res * 16 + dic[arr[i]];
  }
  return res;
}
