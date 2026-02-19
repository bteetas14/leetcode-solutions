class Solution {
public:
    bool hasSuccesor(int i, vector<int>&hand, int groupSize){
        int n = hand.size();
        int next = hand[i]+1;
        hand[i] = -1;
        int count = 1;
        i++;
        while(i<n && count<groupSize){
            if(hand[i]==next){
                next = hand[i]+1;
                count++;
                hand[i] = -1;
            }
            i++;
        }
        return count==groupSize;
    }

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0) return false;

        sort(hand.begin(), hand.end());
        for(int i=0;i<n;i++){
            if(hand[i]>=0){
                if(!hasSuccesor(i, hand, groupSize)) return false;
            }
        }
        return true;
    }
};