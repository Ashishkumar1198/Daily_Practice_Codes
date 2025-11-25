/*  
    Day 3 – Binary Prefix Divisible by 5 (LeetCode 1018)

    Approach Used:
    Binary-to-Decimal Running Remainder:
    - Instead of forming large binary numbers, we track only remainder mod 5
    - Update prefix remainder using:
        bit = (bit * 2 + nums[i]) % 5
    - If remainder becomes 0 → prefix is divisible by 5
    - Stores true/false for each prefix

    Why this works:
    - Modulus keeps number small
    - Avoids overflow for large prefixes

    Time Complexity: O(n)
    Space Complexity: O(n)

    How to Run:
    g++ BinaryPrefixDivisibleBy5.cpp -o run
    ./run
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        ans.reserve(nums.size());
        int bit=0;
        for(int i=0;i<nums.size();i++){
            bit=(bit*2+nums[i])%5;
            ans.push_back(bit == 0);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {0,1,1};
    Solution obj;

    cout << "Prefixes divisible by 5: ";
    vector<bool> res = obj.prefixesDivBy5(nums);

    for (bool x : res) cout << (x ? "true " : "false ");
    cout << endl;

    return 0;
}
