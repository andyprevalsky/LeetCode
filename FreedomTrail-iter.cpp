#include <iostream>
using namespace std;

class Solution {
    public:
        int findRotateSteps(string ring, string key) {
            int mod = ring.size();
            int dp[key.size()][ring.size()];
            for (int i = 0; i < key.size(); i++) {
                for (int j = 0; j < ring.size(); j++) {
                    dp[i][j] = 1000000000;
                }
            }
            for (int i = 0; i < ring.size(); i++) {
                if (ring[i] == key[0]) dp[0][i] = min(i, (int)ring.size()-i) + 1;
            }
            for (int i = 1; i < key.size(); i++) {
                for (int j = 0; j < ring.size(); j++) {
                    if (ring[j] == key[i]) {
                        int count = 0;
                        dp[i][j] = dp[i-1][j] + 1;
                        for (int k = (j+1)%mod; k != j; k = (k+1)%mod) {
                            count += 1;
                            dp[i][j] = min(dp[i][j], dp[i-1][k] + count + 1);
                        }
                        count = 0;
                        for (int k = (j-1+mod)%mod; k != j; k = (k-1+mod)%mod) {
                            count += 1;
                            dp[i][j] = min(dp[i][j], dp[i-1][k] + count + 1);
                        }
                    }
                }
            }
            int res = 2000000000;
            for (int i = 0; i < ring.size(); i++) {
                res = min(res, dp[key.size()-1][i]);
            }
            return res;
        }
};

int main() {
    Solution s;
    cout << s.findRotateSteps("abcdefg", "de") << endl;
}