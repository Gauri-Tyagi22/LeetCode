class Solution {
public:
    string reverseWords(string s) {
      reverse(s.begin(),s.end());
      int start = 0;

for(int end = 0; end <= s.size(); end++) {

    if(end == s.size() || s[end] == ' ') {

        reverse(s.begin() + start, s.begin() + end);

        start = end + 1;
    }
}
      string result;
        stringstream ss(s);
        string word;

        while (ss >> word) {
            if (!result.empty()) result += " ";
            result += word;
        }

        return result;
    }
};