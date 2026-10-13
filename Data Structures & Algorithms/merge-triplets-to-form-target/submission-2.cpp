class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& t, vector<int>& tt) {
        unordered_set<int> good;

        for(vector<int>& x: t) {
            if (x[0] > tt[0] || x[1] > tt[1] || x[2] > tt[2]) continue;

            for(int i = 0; i < 3; i++) {
                if (x[i] == tt[i]) {
                    // cout<<i<<endl;
                    good.insert(i);
                }
            }
        }

        return good.size() == 3;
    }
};
