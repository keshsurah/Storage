class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int row = accounts.size();
        int col = accounts[0].size();

        int WEALTHYMAN = INT_MIN;

        for(int i = 0 ;i<row;i++){
            int Wealth = 0 ;
            for(int j = 0 ;j < col ;j++){
                Wealth += accounts[i][j];
            }
            WEALTHYMAN = max(WEALTHYMAN,Wealth);
        }
        return WEALTHYMAN;
    }
};