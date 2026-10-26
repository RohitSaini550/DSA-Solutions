class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        // int n = intervals.size();
        intervals.push_back({newInterval[0] , newInterval[1]});

        sort(intervals.begin() , intervals.end() , [](vector<int> & a , vector<int> &b){
            return a[0] < b[0];
        });

        int n = intervals.size();
        vector<vector<int>> ans;
        // int j = -1;
        for(int i = 0; i < n; i++){
            if(!ans.empty() && intervals[i][0] <= ans.back()[1] ){
                // merging interval
                int mini = min(intervals[i][0] , ans.back()[0]);
                int maxi = max(intervals[i][1] , ans.back()[1]);
                ans.pop_back();
                // j--;
                ans.push_back({mini , maxi});
            }
            else{
                ans.push_back({intervals[i][0] , intervals[i][1]});
            }
        }
        return ans;
    }
};