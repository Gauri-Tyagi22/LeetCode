class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.length();
        while(i<n && s[i]==' ')
               i++;
            int sign=1;
            if(i<n && (s[i]=='+' || s[i]=='-')){
                if(s[i]=='-') sign=-1;
                i++;

            }
            long long res=0;
            while(i<n && isdigit(s[i])){
                int digit=s[i]-'0';
                if(res>INT_MAX/10 || (res==INT_MAX/10 && digit>7)){
                    if(sign==1) return INT_MAX;
                    else return INT_MIN;
                }
                 res=res*10+digit;
                 i++;
            }
           
            
        
        return sign*res;
    }
};