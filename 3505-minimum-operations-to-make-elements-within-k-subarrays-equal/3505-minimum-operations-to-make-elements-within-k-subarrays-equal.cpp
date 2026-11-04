
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        // Two multisets to maintain the sliding window median
        multiset<int> low, high;
        long long sumLow = 0, sumHigh = 0;

        vector<long long> cost;

        // Maintain median and calculate window cost
        auto balance = [&]() {
            while (low.size() > high.size() + 1) {
                int v = *low.rbegin();
                low.erase(prev(low.end()));
                sumLow -= v;

                high.insert(v);
                sumHigh += v;
            }

            while (low.size() < high.size()) {
                int v = *high.begin();
                high.erase(high.begin());
                sumHigh -= v;

                low.insert(v);
                sumLow += v;
            }
        };

        for (int i = 0; i < n; i++) {
            int v = nums[i];

            if (low.empty() || v <= *low.rbegin()) {
                low.insert(v);
                sumLow += v;
            } else {
                high.insert(v);
                sumHigh += v;
            }

            // Remove element outside the window
            if (i >= x) {
                int out = nums[i - x];

                auto it = low.find(out);

                if (it != low.end()) {
                    low.erase(it);
                    sumLow -= out;
                } else {
                    high.erase(high.find(out));
                    sumHigh -= out;
                }
            }

            balance();

            // Calculate minimum cost for this window
            if (i >= x - 1) {
                long long median = *low.rbegin();

                long long operations =
                    median * low.size() - sumLow
                    + sumHigh - median * high.size();

                cost.push_back(operations);
            }
        }

        // DP: minimum cost to select k non-overlapping windows
        const long long INF = LLONG_MAX / 4;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {
                // Skip current element
                curr[i] = curr[i - 1];

                // Select window ending at i
                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};
