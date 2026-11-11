class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        long long option1 = (long long)need1 * cost1
                          + (long long)need2 * cost2;

        long long option2 = (long long)max(need1, need2) * costBoth;

        int common = min(need1, need2);

        long long option3 = (long long)common * costBoth;

        option3 += (long long)(need1 - common) * cost1;
        option3 += (long long)(need2 - common) * cost2;

        return min(option1, min(option2, option3));
    }
};