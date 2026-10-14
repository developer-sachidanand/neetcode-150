class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int sr = 0, er = m, sc = 0, ec = n;
        vector<int> ans;
        while(sr < er && sc < ec) {
            for(int i = sc; i < ec; i++) {
            ans.push_back(matrix[sr][i]);
            }
            sr++;
            for(int i = sr; i < er; i++) {
                ans.push_back(matrix[i][ec-1]);
            }
            ec--;

            if (!(sr < er && sc < ec)) break;

            for(int i = ec-1; i >= sc; i--) {
                ans.push_back(matrix[er-1][i]);
            }
            er--;
            for(int i = er-1; i >= sr; i--) {
                ans.push_back(matrix[i][sc]);
            }
            sc++;
        }
        return ans;
    }
};
