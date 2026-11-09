class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> freeServers;
        for (int id = 0; id < k; ++id) {
            freeServers.insert(id);
        }

        // (finish time, server id)
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> busy;

        vector<int> handled(k, 0);

        for (int i = 0; i < arrival.size(); ++i) {
            // Servers finishing at this request's arrival time are available.
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                freeServers.insert(busy.top().second);
                busy.pop();
            }

            if (freeServers.empty()) continue; // Drop this request.

            int preferred = i % k;
            auto it = freeServers.lower_bound(preferred);

            if (it == freeServers.end()) {
                it = freeServers.begin(); // Wrap around.
            }

            int server = *it;
            freeServers.erase(it);

            ++handled[server];
            busy.push({arrival[i] + load[i], server});
        }

        int most = *max_element(handled.begin(), handled.end());
        vector<int> answer;

        for (int id = 0; id < k; ++id) {
            if (handled[id] == most) answer.push_back(id);
        }

        return answer;
    }
};