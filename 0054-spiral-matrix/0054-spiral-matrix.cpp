class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat[0].size(),m = mat.size();
        int srow = 0 , scols = 0 , erow = m-1 , ecols = n-1;

        vector<int> ans ;

        while( srow <= erow && scols <= ecols){
            for(int j = scols ; j <= ecols ; j++){
                ans.push_back(mat[srow][j]);
            }
            for(int i = srow + 1 ; i <= erow ; i++){
                ans.push_back(mat[i][ecols]);
            }       
            for(int j = ecols - 1 ; j >= scols ; j--){
                if(srow == erow){
                    break;
                }
                ans.push_back(mat[erow][j]);
            }
            for(int i = erow - 1 ; i >= srow + 1 ; i--){
                if(scols == ecols){
                    break;
                }
                ans.push_back(mat[i][scols]);
            }
            srow++ , scols++ , erow-- , ecols--;
        }
        return ans;
    }

};