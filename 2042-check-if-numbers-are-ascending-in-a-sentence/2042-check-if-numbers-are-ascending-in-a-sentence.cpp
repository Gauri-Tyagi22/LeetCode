class Solution {
public:
    bool areNumbersAscending(string s) {
        stringstream ss(s);
        string temp;
        int prev=-1;
        while(ss>>temp){
            if(isdigit(temp[0])){
                int curr=stoi(temp);
                if(curr<=prev) return false;
                prev=curr;
            }
        }
        return true;
    }
};