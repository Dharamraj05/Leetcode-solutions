class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> visited(256, 0);
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {

            while (visited[s[right]] == 1) {
                visited[s[left]] = 0;
                left++;
            }

            visited[s[right]] = 1;

            int currLen = right - left + 1;
            maxLen = max(maxLen, currLen);
        }

        return maxLen;
    }
};