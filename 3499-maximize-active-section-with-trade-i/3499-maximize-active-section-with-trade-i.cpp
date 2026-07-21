class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
         string t = "1" + s + "1";
        int n = t.size();

        vector<pair<char, int>> runs;


        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && t[j] == t[i]) j++;
            runs.push_back({t[i], j - i});
            i = j;
        }

        int originalOnes = 0;

        
        for (char c : s)
            if (c == '1')
                originalOnes++;

        int ans = originalOnes;

    
        for (int i = 1; i + 1 < runs.size(); i++) {
            if (runs[i].first == '1' &&
                runs[i - 1].first == '0' &&
                runs[i + 1].first == '0') {

                int gain = runs[i - 1].second + runs[i + 1].second;
                ans = max(ans, originalOnes + gain);
            }
        }

        return ans;
    }
};