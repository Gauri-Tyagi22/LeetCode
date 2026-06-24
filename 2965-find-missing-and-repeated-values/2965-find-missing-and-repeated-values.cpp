class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
       long long n = grid.size();
        long long N = n * n;

        long long expectedSum = N * (N + 1) / 2;
        long long expectedSqSum = N * (N + 1) * (2 * N + 1) / 6;

        long long actualSum = 0, actualSqSum = 0;

        for (auto &row : grid) {
            for (int x : row) {
                actualSum += x;
                actualSqSum += 1LL * x * x;
            }
        }

        long long diff1 = actualSum - expectedSum;      
        long long diff2 = actualSqSum - expectedSqSum;  

        long long sumXY = diff2 / diff1;               

        long long repeated = (diff1 + sumXY) / 2;
        long long missing = sumXY - repeated;

        return {(int)repeated, (int)missing}; 
    }
};