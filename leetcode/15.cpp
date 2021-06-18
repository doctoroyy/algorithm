// https://leetcode.com/problems/3sum/

#include<iostream>
#include<vector>
#include<cmath>
#include<set>
using namespace std;

vector<vector<int> > threeSum(vector<int>& nums) {
  sort(nums.begin(), nums.end());

  vector<vector<int> > res;

  if (nums.size() < 3) return res;

  for (int i = 0; i <= nums.size() - 3; i++) {
    if (nums[i] > 0) continue;
    if (i > 0 && nums[i] == nums[i - 1]) continue;
    int l = i + 1, r = nums.size() - 1;
    while (l < r) {
      int sum = nums[i] + nums[l] + nums[r];
      if (sum == 0) {
        vector<int> buffer;
        buffer.push_back(nums[i]);
        buffer.push_back(nums[l]);
        buffer.push_back(nums[r]);
        res.push_back(buffer);
        while (l < r && nums[l] == nums[l + 1]) l++;
        while (l < r && nums[r] == nums[r - 1]) r--;
        l++;
        r--;
      } else if (sum < 0) {
        l++;
      } else {
        r--;
      }
      
    }
  }

  return res;
}

