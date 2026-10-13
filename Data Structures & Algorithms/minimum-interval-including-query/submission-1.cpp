using pi = pair<int, int>;
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = queries.size();
        vector<int> ans(n, -1);

        sort(intervals.begin(), intervals.end());

        vector<pi> sortedQueries(n);
        for(int i = 0; i < n; i++) {
            sortedQueries[i] = {queries[i], i};
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        priority_queue<pi, vector<pi>, greater<pi>> pq;

        int i = 0;
        int j = intervals.size();
        for(auto& [query, index]: sortedQueries) {
            while(i < j && intervals[i][0] <= query) {
                int length = intervals[i][1] - intervals[i][0] + 1;
                pq.push({length, intervals[i][1]});
                i++;
            }

            while(!pq.empty() && pq.top().second < query) pq.pop();

            if(!pq.empty()) {
                ans[index] = pq.top().first;
            }
        }
        return ans;
    }
};
