// https://leetcode.com/problems/3sum-closest/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


// int threeSumClosest(vector<int>& nums, int target) {
//   int res = -2e3;
//   for (int i = 0; i <= nums.size() - 3; i++) {
//     for (int j = i + 1; j <= nums.size() - 2; j++) {
//       for (int k = j + 1; k <= nums.size() - 1; k++) {
//         int sum = nums[i] + nums[j] + nums[k];
//         cout << nums[i] << nums[j] << nums[k] << endl;
//         if (abs(sum - target) < abs(res - target)) {
//           res = sum;
//         }
//       }
//     }
//   }
//   return res;
// }

vector<int> buff;
int vis[1000];

void dfs(vector<int> &nums, int start, int cnt) {
  if (buff.size() == 3) {
    cout << buff[0] << " " << buff[1] << " " << buff[2] << endl;
    return;
  }
  for (int i = start; i <= nums.size() - cnt; i++) {
    buff.push_back(nums[i]);
    dfs(nums, i + 1, cnt - 1);
    buff.pop_back();
  }  
} 

int main() { 
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) cin >> nums[i];
  dfs(nums, 0, 3);
  // int target;
  // cin >> target;
  // cout << threeSumClosest(nums, target) << endl;
}