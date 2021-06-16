#include<iostream>
#include<vector>
#include<cmath>
// #include<algorithm>
using namespace std;

int lower_bound(vector<int>& nums, int target) {
  int l = 0, r = nums.size() - 1, mid, res = -1;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (target < nums[mid]) {
      r = mid - 1;
    } else if (target > nums[mid]) {
      l = mid + 1;
    } else {
      r = mid - 1;
      res = mid;
    }
  }
  return res;
}

int upper_bound(vector<int>& nums, int target) {
  int l = 0, r = nums.size() - 1, mid, res = -1;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (target < nums[mid]) {
      r = mid - 1;
    } else if (target > nums[mid]) {
      l = mid + 1;
    } else {
      l = mid + 1;
      res = mid;
    }
  }
  return res;
}

vector<int> searchRange(vector<int>& nums, int target) {
  vector<int> res;
  int start = lower_bound(nums, target);
  int end = upper_bound(nums, target);
  res.push_back(start);
  res.push_back(end);
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) cin >> nums[i];
  int target;
  cin >> target;
  vector<int> res = searchRange(nums, target);
  cout << res[0] << " " << res[1] << endl;
}