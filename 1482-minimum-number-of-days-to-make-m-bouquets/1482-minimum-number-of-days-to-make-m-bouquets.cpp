class Solution {
public:
int pos(vector<int>&bloomDay,int mid,int m,int k){
    int count=0,b=0;
    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i]<=mid){
            count++;
        }
        else{
            b+=(count/k);
            count=0;

        }
    }
    b+=(count/k);
    return b>=m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int left=*min_element(bloomDay.begin(),bloomDay.end());
        int right=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=0;
        if((long long)m*k>n) return -1;
        while(left<=right){
            int mid=(left+right)/2;
            if(pos(bloomDay,mid,m,k)){
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return ans;
    }
};