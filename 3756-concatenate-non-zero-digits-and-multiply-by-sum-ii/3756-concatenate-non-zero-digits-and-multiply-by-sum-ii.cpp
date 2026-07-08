class Solution {
public:
 static const int mod = 1000000007;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
       vector<int>digit,pos;
       int n=s.length();
       for(int i=0;i<s.length();i++){
        if(s[i]!='0'){
            pos.push_back(i);
            digit.push_back(s[i]-'0');
        }

       }
       int m=digit.size();
       int j=0;
       vector<int>nxt(n,-1),prev(n,-1);
       for(int i=0;i<n;i++){
        while(j<m && pos[j]<i) j++;
        if(j<m) nxt[i]=j;
       }
       j=m-1;
       for(int i=n-1;i>=0;i--){
        while(j>=0 && pos[j]>i) j--;
        if(j>=0) prev[i]=j;
       }
       vector<int>power(m+1,1),prefnum(m+1,0),prefsum(m+1,0);
       for(int i=1;i<=m;i++){
        power[i]=(1LL*power[i-1]*10)%mod;
        prefnum[i]=(1LL*prefnum[i-1]*10+digit[i-1])%mod;
        prefsum[i]=prefsum[i-1]+digit[i-1];
       }
        vector<int> ans;

        for (auto &q : queries) {
            int L = nxt[q[0]];
            int R = prev[q[1]];

            if (L == -1 || R == -1 || L > R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;

            long long num =
                (1LL*prefnum[R + 1] -
                 1LL*prefnum[L] * power[len] % mod + mod) % mod;

            long long sum = prefsum[R + 1] - prefsum[L];

            ans.push_back(num * sum % mod);
        }

        return ans;
    }
};