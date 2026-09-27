class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;

        string ans = "";

        while (i >= 0 || j >= 0 || carry) {
            int a = (i >= 0) ? num1[i] - '0' : 0;
            int b = (j >= 0) ? num2[j] - '0' : 0;

            int sum = a + b + carry;

            ans += char((sum % 10) + '0');
            carry = sum / 10;

            i--;
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};