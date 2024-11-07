#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int getMinimumPenalty(const string& str1, const string& str2, int gap_cost, int mismatch_cost) {
    int m = str1.length();
    int n = str2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        dp[i][0] = i * gap_cost; 
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j * gap_cost; 
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; 
            } else {
                dp[i][j] = min({dp[i - 1][j - 1] + mismatch_cost, 
                                dp[i - 1][j] + gap_cost,      
                                dp[i][j - 1] + gap_cost});    
            }
        }
    }

    return dp[m][n];
}

int main() {
    string str1 = "occurance";
    string str2 = "occurrence";
    cout << getMinimumPenalty(str1, str2, 2, 3);
    return 0;
}
