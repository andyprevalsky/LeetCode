#include <iostream>
using namespace std;

class Solution {
    private:
        int dp[100][100] = {};
    public:
        int DTW(int rP, int kP, string ring, string key) {
            if (kP == -1) return 0;
            if (dp[rP][kP] != 0) return dp[rP][kP];
            int frP;
            int brP;
            int fWeight = 0;
            int bWeight = 0;
            if (kP == 0) {
                fWeight = ring.size()-rP;
                bWeight = rP;
                frP = 0;
                brP = 0;
            }
            else {
                char nextChar = key[kP-1];
                //clockwise
                int mod = ring.size();
                if (ring[rP] == nextChar) { frP = rP; brP = rP; }
                else {
                    for (int i = (rP+1)%mod; i != rP; i = (i+1)%mod) {
                        fWeight += 1;
                        if (ring[i] == nextChar) {
                            frP = i;
                            break;
                        }
                    }
                //counter
                    for (int i = (rP-1 + mod)%mod; i != rP; i = (i-1 + mod)%mod) {
                        bWeight += 1;
                        if (ring[i] == nextChar) {
                            brP = i;
                            break;
                        }
                    }
                }
            }
            int res = min(fWeight + DTW(frP, kP-1, ring, key), bWeight+DTW(brP, kP-1, ring, key)) + 1;
            dp[rP][kP] = res;
            return res;
        }
        int findRotateSteps(string ring, string key) {
            int res = 2000000000;
            for (int i = 0; i < ring.size(); i++) {
                if (ring[i] == key[key.size()-1]) {
                    res = min(res, DTW(i, key.size()-1, ring, key));
                }
            }
            return res;
        }
};

int main() {
    Solution s;
    cout << s.findRotateSteps("aaa", "aaa") << endl;
    return 0; 
}