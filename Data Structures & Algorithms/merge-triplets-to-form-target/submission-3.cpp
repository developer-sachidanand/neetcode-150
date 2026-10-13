class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& t, vector<int>& tt) {
        unordered_set<int> good;
        vector<int> res(3, -1);
        for(vector<int>& x: t) {
            if (x[0] > tt[0] || x[1] > tt[1] || x[2] > tt[2]) continue;

            for(int i = 0; i < 3; i++) {
                if (x[i] == tt[i]) {
                    // cout<<i<<endl;
                    // good.insert(i);
                    res[i] = x[i];
                }
            }

            if (res[0] == tt[0] && res[1] == tt[1] && res[2] == tt[2]) return true;
        }

        if (res[0] == tt[0] && res[1] == tt[1] && res[2] == tt[2]) return true;

        return false;
    }
};
