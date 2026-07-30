class Solution {
public:
const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
      vector<int>pse(n);
      stack<int>st;
      for(int i=0;i<arr.size();i++){
        while(!st.empty() && arr[st.top()]>arr[i]) 
               st.pop();
        if(st.empty()) pse[i]=-1;
        else pse[i]=st.top();
        st.push(i);
      }  
      while (!st.empty()) st.pop();
      vector<int>nse(n);
     
      for(int i=arr.size()-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]) 
               st.pop();
        if(st.empty()) nse[i]=n;
        else nse[i]=st.top();
        st.push(i);
      }  
      long long ans=0;
      for(int i=0;i<arr.size();i++){
        int left=i-pse[i];
        int right=nse[i]-i;
        ans = (ans + 1LL * arr[i] * left * right) % MOD;
      }
      return ans;
    }
};