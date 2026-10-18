
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return Build(s) == Build(t);
    }

    string Build(string str) {
        stack<char> st;

        for (char ch : str) {
            if (ch != '#') {
                st.push(ch);
            }
            else if (!st.empty()) {
                st.pop();
            }
        }

        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
