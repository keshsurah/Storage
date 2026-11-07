class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        // Available servers: {weight, index}
        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> available;

        // Busy servers: {finishTime, weight, index}
        priority_queue<tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>> busy;

        int n = servers.size();
        vector<int> answer;

        // Initially, all servers are available
        for (int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        long long currentTime = 0;

        for (int i = 0; i < tasks.size(); i++) {

            currentTime = max(currentTime, (long long)i);

            // Release all servers that have finished
            while (!busy.empty() &&
                   get<0>(busy.top()) <= currentTime) {

                auto [finishTime, weight, index] = busy.top();
                busy.pop();

                available.push({weight, index});
            }

            // If no server is available, wait
            if (available.empty()) {
                currentTime = get<0>(busy.top());

                while (!busy.empty() &&
                       get<0>(busy.top()) <= currentTime) {

                    auto [finishTime, weight, index] = busy.top();
                    busy.pop();

                    available.push({weight, index});
                }
            }

            // Select the best available server
            auto [weight, index] = available.top();
            available.pop();

            answer.push_back(index);

            // Mark server as busy
            busy.push({
                currentTime + tasks[i],
                weight,
                index
            });
        }

        return answer;
    }
};