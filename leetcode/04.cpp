// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    vector<int> get_merge_array(vector<int>& nums1, vector<int>& nums2) {
      if (nums1.size() == 0) return nums2;
      if (nums2.size() == 0) return nums1;

      vector<int> res(nums1.size() + nums2.size());
      int l = 0, r = 0, i = 0;
      while (l < nums1.size() && r < nums2.size()) {
        if (nums1[l] < nums2[r]) {
          res[i++] = nums1[l++];
        } else {
          res[i++] = nums2[r++];
        }
      }
      while (l < nums1.size()) res[i++] = nums1[l++];
      while (r < nums2.size()) res[i++] = nums2[r++];

      return res;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      
      vector<int> merged_arr = get_merge_array(nums1, nums2);

      if (merged_arr.size() == 1) return (double) merged_arr[0];

      int mid = merged_arr.size() / 2;
      if (merged_arr.size() % 2 == 1) {
        return (double)merged_arr[mid];
      }
      
      return (double)(merged_arr[mid - 1] + merged_arr[mid]) / 2;
    }
};

int main() {

  int m, n;
  cin >> m >> n;
  vector<int> nums1(m), nums2(n);

  for (int i = 0; i < m; i++) cin >> nums1[i];
  for (int i = 0; i < n; i++) cin >> nums2[i];

  cout << (new Solution())->findMedianSortedArrays(nums1, nums2) << endl;
  


}