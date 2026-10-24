class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin() , nums.end());

        int ans = INT_MAX;
        // stack<tuple<int, int, int>> stk;
        int prevDis = INT_MAX;
        for(int i = 0; i < n ; i++){
            // if(i >0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = n - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                int distance = abs(sum - target);
                if(distance < prevDis){ 
                    prevDis = distance;
                    ans = sum;
                }
                if(sum < target) left++;
                else if(sum > target) right--;
                else if(sum == target) return nums[i] + nums[left] + nums[right];
            }
        }
        return ans;
    }
};