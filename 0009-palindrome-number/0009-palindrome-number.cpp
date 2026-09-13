class Solution {

public:

    bool isPalindrome(int x) {

        long long temp = x;
        int original = x;
        int r;
        
        if (x < 0)
            return false;

        temp = 0;

        while(x != 0) {

            r = x % 10;

            temp = (temp * 10) + r;

            x = x / 10;
        }

        if(temp == original)
            return true;
        else
            return false;
    }
};