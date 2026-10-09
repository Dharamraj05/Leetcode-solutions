class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                open++;
            }
            else {
                // Har '(' ke liye 2 ')' chahiye
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                }
                else {
                    ans++;
                }

                if (open > 0) {
                    open--;
                }
                else {
                    ans++;
                }
            }
        }

        ans += open * 2;

        return ans;
    }
};