class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' ||
               c == 'o' || c == 'u';
    }

    int getIndex(char c) {
        if (c == 'a') return 0;
        if (c == 'e') return 1;
        if (c == 'i') return 2;
        if (c == 'o') return 3;
        return 4;  
    }

    int countVowelSubstrings(string word) {
        int n = word.size(), ans = 0;

        for (int i = 0; i < n; i++) {
            int freq[5] = {0};
            int distinct = 0;

            for (int j = i; j < n; j++) {

                if (!isVowel(word[j]))
                    break;

                int idx = getIndex(word[j]);

                if (freq[idx] == 0)
                    distinct++;

                freq[idx]++;

                if (distinct == 5)
                    ans++;
            }
        }

        return ans;
    }
};