class Solution {
public:
    int find(vector<vector<int>>& mat, int n, int m, int col) {
        int idx = -1;
        int maxval = -1;

        for(int i = 0; i < n; i++) {
            if(mat[i][col] > maxval) {
                maxval = mat[i][col];
                idx = i;
            }
        }
        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = m - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int maxidx = find(mat, n, m, mid);

            int left = (mid > 0) ? mat[maxidx][mid - 1] : -1;
            int right = (mid < m - 1) ? mat[maxidx][mid + 1] : -1;

            if(mat[maxidx][mid] > left &&
               mat[maxidx][mid] > right) {
                return {maxidx, mid};
            }
            else if(mat[maxidx][mid] < left) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};