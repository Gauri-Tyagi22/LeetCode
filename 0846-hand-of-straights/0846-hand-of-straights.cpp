class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>mp;
        for(int x:hand) mp[x]++;
        for(auto it:mp){
            int mn=it.first;
            while(mp[mn]>0){
                for(int i=0;i<groupSize;i++){
                    if(mp[mn+i]==0) return false;
                    mp[mn+i]--;
                }
            }
        }
        return true;
    }
};