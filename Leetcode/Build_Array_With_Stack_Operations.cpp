/*  
    Day 6 – Build Array With Stack Operations (LeetCode 1441)

    Approach Used:
    Simulating Stack Operations:
    -----------------------------
    - You start with numbers from 1 to n.
    - For each number:
        • If the current number matches target[i] → Push
        • Else → Push + Pop (discard it) until you reach target[i]
    - Continue until the entire target array is built.

    Why this works:
    - LeetCode forces you to generate the exact sequence of stack operations
      that result in forming the target array.
    - "Push" simulates adding a number.
    - "Pop" discards unwanted numbers.

    Time Complexity: O(n)
    Space Complexity: O(n)

    How to Run:
    g++ BuildArrayWithStackOps.cpp -o run
    ./run
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int j=1;
        for(int i=0;i<target.size();i++){
            if(target[i]==j){
                ans.push_back("Push");
                j++;
            }
            else{
                while(target[i]!=j){
                    ans.push_back("Push");
                    ans.push_back("Pop");
                    j++;
                }
                ans.push_back("Push");
                j++;
            }

        }
        return ans;
    }
};

int main() {
    vector<int> target = {1, 3};
    int n = 3;

    Solution obj;
    vector<string> res = obj.buildArray(target, n);

    cout << "Operations: ";
    for (auto &op : res) cout << op << " ";
    cout << endl;

    return 0;
}
