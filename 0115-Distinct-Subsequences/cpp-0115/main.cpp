/// Source : https://leetcode.com/problems/distinct-subsequences/description/
/// Author : liuyubobobo
/// Time   : 2018-04-23

#include <iostream>
#include <string>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(s * t)
/// Space Complexity: O(s * t)
class Solution {
public:
    int numDistinct(string s, string t) {

        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for(int i = 0 ; i <= s.size() ; i ++)
            dp[i][0] = 1;

        for(int i = 1 ; i <= s.size() ; i ++)
            for(int j = 1 ; j <= t.size() ; j ++){
                dp[i][j] = dp[i - 1][j];
                if(s[i - 1] == t[j - 1])
                    dp[i][j] += dp[i - 1][j - 1];
            }

        return dp[s.size()][t.size()];
    }
};

int main() {

    string S1 = "rabbbit";
    string T1 = "rabbit";
    cout << Solution().numDistinct(S1, T1) << endl;
    // 3

    // ---

    string S2 = "babgbag";
    string T2 = "bag";
    cout << Solution().numDistinct(S2, T2) << endl;
    // 5

    return 0;
}