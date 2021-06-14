// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include<iostream>
#include<vector>
using namespace std;

// int lengthOfLongestSubstring(string s) {
 
//   if (s.size() <= 1) return s.size();

//   int maxRange = 0;
//   int left = 0, right;
//   for (right = 1; right < s.size(); right++) {
//     int equalIndex = -1;

//     for (int i = right - 1; i >= left; i--) {
//       if (s[right] == s[i]) {
//         equalIndex = i;
//         break;
//       }
//     }

//     if (equalIndex != -1) {
//       left = equalIndex + 1;
//     }
//     maxRange = max(maxRange, right - left + 1);

//   }

//   return maxRange;
// }

int lengthOfLongestSubstring(string s) {
 
  if (s.size() <= 1) return s.size();

  vector<int> equalIndexes(128, -1);
  
  int maxRange = 0;
  int left = 0, right;
  for (right = 0; right < s.size(); right++) {
    int equalIndex = equalIndexes[s[right]];

    if (equalIndex != -1 && equalIndex >= left) {
      left = equalIndex + 1;
    }
    maxRange = max(maxRange, right - left + 1);
    equalIndexes[s[right]] = right;
  }

  return maxRange;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;
  }
  
}