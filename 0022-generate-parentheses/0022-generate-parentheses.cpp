class Solution {
public:
    void solve(int open, int close, string cur, vector<string>& ans, int n) {

        if (cur.size() == 2 * n) {
            ans.push_back(cur);
            return;
        }

        if (open < n) {
            solve(open + 1, close, cur + '(', ans, n);
        }

        if (close < open) {
            solve(open, close + 1, cur + ')', ans, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        solve(0, 0, "", ans, n);

        return ans;
    }
};