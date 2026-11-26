
class Solution {
public:
    bool canAliceWin(int n) {
        int x = 10, count = 0;

        while (n >= x) {
            n -= x;
            x--;
            count++;
        }

        return count % 2 == 1;
    }
};
