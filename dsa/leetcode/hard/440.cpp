class Solution {
public:
    int findKthNumber(int n, int k) {
        long long cur = 1;
        k--;
        while (k > 0) {
            long long steps = 0;
            for (long long first = cur, last = cur + 1; first <= n; first *= 10, last *= 10) {
                steps += min(static_cast<long long>(n) + 1, last) - first; // n+1 to inculde n , and in last we did not because we do not want to include last
            }
            if (steps <= k) {
                k -= steps;
                cur++;
            } else {
                k--;
                cur *= 10;
            }
        }
        return cur;
    }
};