class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] > b[1];   // descending order by second element
        });

        int totUnits = 0;

        for(auto it:boxTypes){
            int numBoxes = it[0];
            int numUnits = it[1];

            if(truckSize >= numBoxes){
                truckSize -= numBoxes;
                totUnits += (numUnits*numBoxes);
            }
            else{
                totUnits = totUnits + (numUnits*truckSize);
                break;
            }
        }
        return totUnits;
    }
};