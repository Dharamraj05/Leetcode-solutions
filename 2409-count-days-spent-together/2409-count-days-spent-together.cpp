class Solution {
public:
    int dayOfYear(string date) {
        vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};

        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        int total = day;
        for (int i = 0; i < month - 1; i++) {
            total += days[i];
        }
        return total;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        int a1 = dayOfYear(arriveAlice);
        int a2 = dayOfYear(leaveAlice);
        int b1 = dayOfYear(arriveBob);
        int b2 = dayOfYear(leaveBob);

        int start = max(a1, b1);
        int end = min(a2, b2);

        return max(0, end - start + 1);
    }
};