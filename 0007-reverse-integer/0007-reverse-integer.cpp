class Solution {
public:
    int reverse(int x) {
        int revNUM = 0;

        while (x != 0) {
            int dig = x % 10;

            if (revNUM > INT_MAX / 10 ||
               (revNUM == INT_MAX / 10 && dig > 7))
                return 0;

            if (revNUM < INT_MIN / 10 ||
               (revNUM == INT_MIN / 10 && dig < -8))
                return 0;

            revNUM = revNUM * 10 + dig;
            x /= 10;
        }

        return revNUM;
    }
};