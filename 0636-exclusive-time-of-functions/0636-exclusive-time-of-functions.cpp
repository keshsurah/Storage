class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n,0);
        stack<int> st;
        int prevTime = 0;

        for(string& log : logs){
            int id ,time;
            char type[6];

            sscanf(log.c_str(),"%d:%[^:]:%d",&id,type,&time);

            if(type[0] == 's'){
                if(!st.empty()){
                    ans[st.top()] += time - prevTime;
                }
                st.push(id);
                prevTime = time;
            }else{
                ans[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time + 1;
            }
        }
        return ans;
    }
};