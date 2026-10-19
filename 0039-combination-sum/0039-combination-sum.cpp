
class Solution {
public:
    set<vector<int>> s;

    void getAllCombination(vector<int>& arr, int idx, int tar,
                           vector<vector<int>>& ans,
                           vector<int>& combine) {
        if (tar == 0) {
            if (s.find(combine) == s.end()) {
                ans.push_back(combine);
                s.insert(combine);
            }
            return;
        }

        if (idx == arr.size() || tar < 0)
            return;

        combine.push_back(arr[idx]);

        // Include current element (reuse allowed)
        getAllCombination(arr, idx + 1, tar - arr[idx], ans, combine);
        getAllCombination(arr, idx, tar - arr[idx], ans, combine);

        combine.pop_back();

        // Exclude current element
        getAllCombination(arr, idx + 1, tar, ans, combine);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;

        s.clear();
        getAllCombination(candidates, 0, target, ans, combine);

        return ans;
    }
};
