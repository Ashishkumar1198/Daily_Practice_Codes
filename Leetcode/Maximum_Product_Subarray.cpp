/*
    Day 1 – Maximum Product Subarray (LeetCode 152)

    Approach Used:
    Prefix and Suffix Product Method:
    - Scan array from left (prefix product)
    - Scan from right (suffix product)
    - Reset product to 1 whenever `0` appears
    - Max product will be maximum of prefix or suffix scans

    Time Complexity: O(n)
    Space Complexity: O(1)

    How to Run:
    g++ MaximumProductSubarray.cpp -o run
    ./run
*/


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),maxl=1,maxs=1,ans=INT_MIN;
        for(int i=0;i<n;i++){
            maxs *= nums[i];
            ans= max(ans,maxs);
            if(maxs==0)maxs=1;
        }
        for(int i=n-1;i>=0;i--){
            maxl *= nums[i];
            ans= max(ans,maxl);
            if(maxl==0)maxl=1;
        }
        return ans;
    }
};
int main() {
    vector<int> nums = {2, 3, -2, 4};
    Solution obj;

    cout << "Maximum Product Subarray = " << obj.maxProduct(nums) << endl;
    return 0;
}
