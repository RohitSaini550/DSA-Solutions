class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int n = arr.size();
        int ans = 0;
        vector<pair<int, int> > v;
        for(int i = 0; i < n; i++){
            v.push_back({arr[i][0] , arr[i][1]});
        }

        sort(v.begin() , v.end() ,[](auto &a, auto &b ){
            return a.second < b.second;
        });

        int freeTime = INT_MAX;
        for(int i = 0; i < n; i++){
            if(i != 0 && v[i].first < freeTime){
                ans++;
                
            }
            else{
                freeTime = v[i].second;
            }
        }
        return ans;
    }
};