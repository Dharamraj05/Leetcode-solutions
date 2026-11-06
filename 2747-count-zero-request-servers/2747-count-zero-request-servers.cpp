class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        
        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        vector<pair<int, int>> queryList;

        for (int i = 0; i < queries.size(); i++) {
            queryList.push_back({queries[i], i});
        }

        sort(queryList.begin(), queryList.end());

        vector<int> answer(queries.size());
        vector<int> count(n + 1, 0);

        int left = 0;
        int right = 0;
        int activeServers = 0;

        for (auto q : queryList) {
            int time = q.first;
            int index = q.second;

            while (right < logs.size() && logs[right][1] <= time) {
                int server = logs[right][0];

                if (count[server] == 0) {
                    activeServers++;
                }

                count[server]++;
                right++;
            }

            while (left < right && logs[left][1] < time - x) {
                int server = logs[left][0];

                count[server]--;

                if (count[server] == 0) {
                    activeServers--;
                }

                left++;
            }

            answer[index] = n - activeServers;
        }

        return answer;
    }
};