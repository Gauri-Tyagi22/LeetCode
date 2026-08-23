class Solution {
public:
    bool sumGame(string num) {
        int diff = 0, q = 0;
        int n = num.size();

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                q++;
            else
                diff += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                q--;
            else
                diff -= num[i] - '0';
        }

        if (q % 2 != 0)
            return true;

        return diff != -q / 2 * 9;
    }
};