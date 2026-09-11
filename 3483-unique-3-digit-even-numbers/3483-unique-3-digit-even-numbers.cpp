class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        set<int> st;

        for (int i = 0; i < digits.size(); i++) {

            // First digit cannot be 0
            if (digits[i] == 0)
                continue;

            for (int j = 0; j < digits.size(); j++) {

                // Same digit cannot be used again
                if (j == i)
                    continue;

                for (int k = 0; k < digits.size(); k++) {

                    // Same digit cannot be used again
                    if (k == i || k == j)
                        continue;

                    // Last digit must be even
                    if (digits[k] % 2 != 0)
                        continue;

                    int num = digits[i] * 100
                            + digits[j] * 10
                            + digits[k];

                    st.insert(num);
                }
            }
        }

        return st.size();
    }
};