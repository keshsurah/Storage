
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int countZero = 0;
        int countOne = 0;

        // Count students' preferences
        for (int student : students) {
            if (student == 0)
                countZero++;
            else
                countOne++;
        }

        // Process sandwiches
        for (int sandwich : sandwiches) {
            if (sandwich == 0) {
                if (countZero == 0)
                    return countOne;
                countZero--;
            }
            else {
                if (countOne == 0)
                    return countZero;
                countOne--;
            }
        }

        return 0;
    }
};
