class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1,
                                       vector<int>& nums2, int k) {

        vector<vector<int>> result;

        // Min Heap: {sum, index1, index2}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > minHeap;

        // Insert first pair from each row
        for (int i = 0; i < min(k, (int)nums1.size()); i++) {
            minHeap.push({nums1[i] + nums2[0], i, 0});
        }

        while (k > 0 && !minHeap.empty()) {

            auto [sum, i, j] = minHeap.top();
            minHeap.pop();

            result.push_back({nums1[i], nums2[j]});

            // Move to the next element in nums2
            if (j + 1 < nums2.size()) {
                minHeap.push({
                    nums1[i] + nums2[j + 1], i, j + 1
                });
            }

            k--;
        }

        return result;
    }
};