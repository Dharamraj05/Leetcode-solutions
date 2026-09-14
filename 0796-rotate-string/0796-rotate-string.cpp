class Solution {
public:
    bool rotateString(string s, string goal) {

        if (s.length() != goal.length())
            return false;

        string temp = s + s;

        return temp.find(goal) != string::npos;
    }
};