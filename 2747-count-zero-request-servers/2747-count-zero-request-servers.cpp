
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();

        // Sort logs by request time
        sort(logs.begin(), logs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        // Store {query time, original index}
        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < m; i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> frequency(n + 1, 0);
        vector<int> answer(m);

        int left = 0, right = 0;
        int activeServers = 0;

        for (auto [queryTime, index] : sortedQueries) {

            int windowStart = queryTime - x;

            // Add logs inside the right boundary
            while (right < logs.size() && logs[right][1] <= queryTime) {
                int serverId = logs[right][0];

                if (frequency[serverId] == 0) {
                    activeServers++;
                }

                frequency[serverId]++;
                right++;
            }

            // Remove logs outside the left boundary
            while (left < logs.size() && logs[left][1] < windowStart) {
                int serverId = logs[left][0];

                frequency[serverId]--;

                if (frequency[serverId] == 0) {
                    activeServers--;
                }

                left++;
            }

            // Servers with zero requests
            answer[index] = n - activeServers;
        }

        return answer;
    }
};
