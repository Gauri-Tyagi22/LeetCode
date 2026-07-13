class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string num="123456789";
        int leftcnt=0,rightcnt=0;
        int left=low,right=high;
        while(left){
            leftcnt++;
            left/=10;
        }
         while(right){
            rightcnt++;
            right/=10;
        }
        vector<int>res;
        for(int i=leftcnt;i<=rightcnt;i++){
            for(int st=0;st<=9-i;st++){
            string s=num.substr(st,i);
            int ans=stoi(s);
            if(low<=ans && ans<=high) res.push_back(ans);
        }
        }
        return res;
    }
};