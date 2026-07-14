class Solution {
public:
    vector<int> plusOne(vector<int>& A) {
        int n = A.size();
       for( int i = n -1; i >= 0; i--){
        if(A[i] < 9){
            A[i]++;
            return A;
        }
        A[i] = 0;
       }
       A.insert(A.begin(),1);
       return A;
    }
};