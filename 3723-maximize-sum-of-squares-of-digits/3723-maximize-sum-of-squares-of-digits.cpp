class Solution {
public:
string maxSumOfSquares(int num, int sum) {
if (sum > 9 * num) {
return "";
}

    string ans = "";

    while (sum >= 9) {
        ans += '9';
        sum -= 9;
    }

    if (sum > 0) {
        ans += char('0' + sum);
    }

    while (ans.size() < num) {
        ans += '0';
    }

    return ans;
}
};
