class Solution {
public:
    char findTheDifference(string s, string t) {
        int freq[26] = {0};

        for (char c : s)
            freq[c - 'a']++;

        for (char c : t)
            freq[c - 'a']--;

        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0)
                return 'a' + i;
        }

        return ' ';
    }
};