class Solution {
public:
    set<string> solve(string s, int &i) {
        set<string> ans;
        vector<string> cur = {""};

        while (i < s.size() && s[i] != '}') {
            if (s[i] == '{') {
                i++; 
                set<string> inside = solve(s, i);
                i++; // skip }

                vector<string> temp;
                for (string a : cur) {
                    for (string b : inside) {
                        temp.push_back(a + b);
                    }
                }
                cur = temp;
            }
            else if (s[i] == ',') {
                for (string x : cur)
                    ans.insert(x);

                cur = {""};
                i++;
            }
            else {
                char c = s[i];
                for (string &x : cur)
                    x += c;
                i++;
            }
        }

        for (string x : cur)
            ans.insert(x);

        return ans;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> result = solve(expression, i);

        return vector<string>(result.begin(), result.end());
    }
};