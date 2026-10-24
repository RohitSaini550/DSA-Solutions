// class Solution {
// public:
//     int eraseOverlapIntervals(vector<vector<int>>& arr) {
//         int n = arr.size();
//         int ans = 0;
//         vector<pair<int, int> > v;
//         for(int i = 0; i < n; i++){
//             v.push_back({arr[i][0] , arr[i][1]});
//         }

//         sort(v.begin() , v.end() ,[](auto &a, auto &b ){
//             return a.second < b.second;
//         });

//         int freeTime = INT_MAX;
//         for(int i = 0; i < n; i++){
//             if(i != 0 && v[i].first < freeTime){
//                 ans++;
                
//             }
//             else{
//                 freeTime = v[i].second;
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    static bool comp(vector<int> first , vector<int> second){
        return first[1] < second[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int n = arr.size();
        
        // vector<pair<int, int> > v;
        // for(int i = 0; i < n; i++){
        //     v.push_back({arr[i][0] , arr[i][1]});
        // }
        if(arr.size() == 0 || arr.size() == 1) return 0;
        sort(arr.begin() , arr.end() ,comp);

        int intervalRemoved = 0;
        int freeTime = arr[0][1];
        for(int i = 1; i < n; i++){
            if(arr[i][0] < freeTime){
                intervalRemoved++;
                
            }
            else{
                freeTime = arr[i][1];
            }
        }
        return intervalRemoved;
    }
};