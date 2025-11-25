/*  
    Day 4 – Smallest Repunit Divisible by K (LeetCode 1015)

    Approaches Used:

    1) Remainder Tracking with HashSet (Cycle Detection):
       - Compute remainder: rem = (rem * 10 + 1) % k
       - If remainder becomes 0 → answer found
       - If a remainder repeats → cycle detected → return -1
       - Uses unordered_set to detect repeated remainders

       Time Complexity: O(k)
       Space Complexity: O(k)

    2) Optimized Mathematical Remainder Simulation:
       - If k is divisible by 2 or 5 → repunit solution impossible
       - Track only remainder for at most k steps
       - When rem == 0 → return length
       - Space O(1), no extra storage needed

       Time Complexity: O(k)
       Space Complexity: O(1)

    How to Run:
    g++ SmallestRepunitDivisibleByK.cpp -o run
    ./run
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // -----------------------------------
    // Approach 1: Using HashSet (Cycle detection)
    // -----------------------------------
    
    int smallestRepunitDivByK(int k) {
        if(k%2==0||k%5==0) return -1;
        int rem=0;
        unordered_set<int> mp;
        for(int i=1;i<=k;i++){
            rem=(rem*10+1)%k;
            if(rem==0)return i;
            if(mp.count(rem))return -1;
            mp.insert(rem);
        }
        return -1;
    }


    // -----------------------------------
    // Approach 2: Optimized (Space O(1))
    // -----------------------------------
    int smallestRepunitDivByK(int k) {
        if(k%2==0||k%5==0) return -1;
        int rem=0;
        int length=0;
        for(int i=1;i<=k;i++){
            rem=(rem*10+ 1)% k;
            length++;
            if(rem==0)return length;
        }
      return -1;
    }
};

int main() {
    Solution obj;
    int k = 7;

    cout << "Approach 1 (HashSet): " 
         << obj.smallestRepunitDivByK_HashSet(k) << endl;

    cout << "Approach 2 (Optimized): "
         << obj.smallestRepunitDivByK(k) << endl;

    return 0;
}
