class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        // Palindrome possible?
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1)
            return "";

        // Characters available in first half
        vector<int> half(26);

        for (int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;

        string left;

        // Build first half
        for (int pos = 0; pos < n / 2; pos++) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                // Try character c
                half[c]--;
                left.push_back('a' + c);

                // Build the largest possible completion
                string candidate = left;

                for (int x = 25; x >= 0; x--) {
                    candidate += string(half[x], 'a' + x);
                }

                string palindrome = candidate;

                if (n & 1)
                    palindrome += mid;

                reverse(candidate.begin(), candidate.end());
                palindrome += candidate;

                // If even the largest completion works,
                // this character is safe.
                if (palindrome > target)
                    goto chosen;

                // Undo
                left.pop_back();
                half[c]++;
            }

            // No character can work
            return "";

        chosen:
            ;
        }

        // Construct final answer
        string ans = left;

        if (n & 1)
            ans += mid;

        reverse(left.begin(), left.end());
        ans += left;

        return ans > target ? ans : "";
    }
};