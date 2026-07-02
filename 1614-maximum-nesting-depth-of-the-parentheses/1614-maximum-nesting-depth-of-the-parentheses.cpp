class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int mxcount=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') count++;
            mxcount=max(mxcount,count);
             if(s[i]==')') count--;
        }
        return mxcount;
    }
};