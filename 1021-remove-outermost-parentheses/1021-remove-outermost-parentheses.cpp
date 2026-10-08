class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int depth = 0;

        for (char c : s) {

            if (c == '(') {
                depth++;

                if (depth > 1) {
                    ans += c;
                }
            }
            else {
                depth--;

                if (depth > 0) {
                    ans += c;
                }
            }
        }

        return ans;
    }
};