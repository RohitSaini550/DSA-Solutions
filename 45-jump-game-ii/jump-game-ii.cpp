class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int left = 0;
        int right = 0;
        while(right < n-1){
            int maxIdx = right;
            for(int i = left ; i <= right ; i++){       
                maxIdx = max(maxIdx ,nums[i] + i);
            }
            // if(maxIdx == right) ; 
            jumps++;
            left = right + 1;
            right = maxIdx;
        }
        return jumps;
    }
};