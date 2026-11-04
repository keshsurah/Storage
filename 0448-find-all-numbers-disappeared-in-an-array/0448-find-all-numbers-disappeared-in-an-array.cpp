
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();

        // Mark numbers that are present
        for (int i = 0; i < size; i++) {
            int index = abs(nums[i]) - 1;

            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }

        vector<int> answer;

        // Positive values indicate missing numbers
        for (int i = 0; i < size; i++) {
            if (nums[i] > 0) {
                answer.push_back(i + 1);
            }
        }

        return answer;
    }
};
