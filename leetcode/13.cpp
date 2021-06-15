// https://leetcode.com/problems/3sum-closest/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


int threeSumClosest(vector<int>& nums, int target) {
  int res = -2e3;
  for (int i = 0; i <= nums.size() - 3; i++) {
    for (int j = i + 1; j <= nums.size() - 2; j++) {
      for (int k = j + 1; k <= nums.size() - 1; k++) {
        int sum = nums[i] + nums[j] + nums[k];
        cout << nums[i] << nums[j] << nums[k] << endl;
        if (abs(sum - target) < abs(res - target)) {
          res = sum;
        }
      }
    }
  }
  return res;
}

// vector<int> buff;
// int buff[1000];
// int vis[1000];

// void dfs(vector<int> &nums, int start, int cnt, int index) {
//   if (index == 3) {
//     cout << buff[0] << " " << buff[1] << " " << buff[2] << endl;
//     return;
//   }
//   for (int i = start; i <= nums.size() - cnt; i++) {
//     if (!vis[i]) {
//       buff[index] = (nums[i]);
//       vis[i] = 1;
//       dfs(nums, i + 1, cnt - 1, index + 1);
//       vis[i] = 0;
//     }
    
//   }  
// } 

int main() { 
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) cin >> nums[i];
  // dfs(nums, 0, 3, 0);
  int target;
  cin >> target;
  cout << threeSumClosest(nums, target) << endl;
}