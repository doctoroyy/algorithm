// https://leetcode.com/problems/median-of-two-sorted-arrays/

function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
  const getMergeArr = (nums1: number[], nums2: number[]): number[] => {
  if (nums1.length == 0) return nums2;
  if (nums2.length == 0) return nums1;
  let l = 0, r = 0, i = 0;
  const res = [];
    while (l < nums1.length && r < nums2.length) {
      if (nums1[l] < nums2[r]) {
        res[i++] = nums1[l++];
      } else {
        res[i++] = nums2[r++];
      }
    }
    while (l < nums1.length) res[i++] = nums1[l++];
    while (r < nums2.length) res[i++] = nums2[r++];

    return res;
  }
  const mergedArr = getMergeArr(nums1, nums2);
  console.log(mergedArr)
  if (mergedArr.length === 1) return Number(mergedArr[0].toFixed(5))

  const mid = Math.floor(mergedArr.length / 2);
  if (Math.floor(mergedArr.length) % 2 === 1){
    return Number(mergedArr[mid].toFixed(5));
  }
  return Number(((mergedArr[mid - 1] + mergedArr[mid])/2).toFixed(5))
}

console.log(findMedianSortedArrays([1], [2,3]))