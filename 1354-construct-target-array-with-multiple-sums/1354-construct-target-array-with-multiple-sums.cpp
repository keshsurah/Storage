class Solution {
public:
    bool isPossible(vector<int>& target) {

        priority_queue<long long> maxHeap;

        long long totalSum = 0;

        for (int num : target) {
            maxHeap.push(num);
            totalSum += num;
        }

        while (true) {

            long long largest = maxHeap.top();
            maxHeap.pop();

            long long remainingSum = totalSum - largest;

            // All elements are 1
            if (largest == 1 || remainingSum == 1) {
                return true;
            }

            // Invalid condition
            if (remainingSum == 0 || largest <= remainingSum ||
                largest % remainingSum == 0) {
                return false;
            }

            // Reverse the operation
            long long previous = largest % remainingSum;

            totalSum = remainingSum + previous;

            maxHeap.push(previous);
        }

        return true;
    }
};