// class Solution {
// public:
//     int minGroups(vector<vector<int>>& nums) {
//         int n = nums.size();
//         sort(nums.begin() , nums.end());
//         vector<int> arrival;
//         vector<int> departure;
//         for(int i = 0; i < n; i++){
//             arrival.push_back(nums[i][0]);
//             departure.push_back(nums[i][1]);
//         }

//         int platform = 0;
//         for(int i = 0 ; i < n; i++){
//             int j = i - 1;
//             bool PlatAvailable = false;
//             while(j >= 0){
//                 if(departure[j] < arrival[i]){
//                     PlatAvailable = true;
//                     arrival.erase(arrival.begin() + j );
//                     departure.erase(departure.begin() + j );
//                     n--;
//                     i--;
//                     // arrival[j] = arrival[i];
//                     // departure[j] = departure[i];
//                     break;
//                 }
//                 j--;
//             }a
//             if(PlatAvailable == false){
//                 platform++;
//             }
//         }
//         return platform;
//     }
// };


class Solution {
public:
    int minGroups(vector<vector<int>>& nums) {
        if(nums.size() == 1) return 1;
        int n = nums.size();
        vector<int> arrival;
        vector<int> departure;
        for(int i = 0; i < n; i++){
            arrival.push_back(nums[i][0]);
            departure.push_back(nums[i][1]);
        }

        sort(arrival.begin() , arrival.end());
        sort(departure.begin() , departure.end());

        int i = 0;
        int j = 0;
        int currGrps = 0;
        int maxGroups = 0;
        while(i < n && j < n){
            if(arrival[j] <= departure[i]){
                currGrps++;
                maxGroups = max(maxGroups , currGrps);
                j++;
            }
            else if(arrival[j] > departure[i]){
                i++;
                currGrps--;
                // j++;
            }
        }
        return maxGroups;
    }
};