class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;

        for(int i=0;i<numRows;i++){
            int size = i+1;
            vector<int> temp;

            for(int j=0;j<size;j++){
                if(j==0){
                    temp.push_back(1);
                }
                else if(j==size-1){
                    temp.push_back(1);
                }
                else{
                    int x = ans[i-1][j] + ans[i-1][j-1];
                    temp.push_back(x);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};