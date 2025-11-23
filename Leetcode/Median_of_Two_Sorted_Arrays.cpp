/*  
    Day 2 – Median of Two Sorted Arrays (LeetCode 4)

    Approach Used:
    Merge-Based Approach (Two Pointer Method):
    - Use two pointers to merge both sorted arrays into a new sorted array
    - Compare elements from both arrays and push the smaller one
    - If one array ends, push remaining elements from the other
    - Finally compute the median:
        - If total length is even → average of two middle values
        - If odd → middle value directly

    Time Complexity: O(m + n)
    Space Complexity: O(m + n)

    How to Run:
    g++ MedianOfTwoSortedArrays.cpp -o run
    ./run
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size()+nums2.size();
        vector<int> merged;
        int a=0,b=0;
        while (a < nums1.size() && b < nums2.size()){
            if(nums1[a]<nums2[b]){
                merged.push_back(nums1[a++]);
            }else{
                merged.push_back(nums2[b++]);
            }
        }
        while(a < nums1.size()){
            merged.push_back(nums1[a++]);
        }
        while(b < nums2.size()){
            merged.push_back(nums2[b++]);
        }
        if(m%2==0){
            return (merged[(m/2)-1]+merged[m/2]) / 2.0;
        }
        return merged[(m/2)];
    }
};
int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    Solution obj;
    cout << "Median of Two Sorted Arrays = " 
         << obj.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}
