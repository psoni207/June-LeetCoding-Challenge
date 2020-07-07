class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        int max_ind = 0;
        int curr_max = 0;
        
        for(int i = 0; i < n; i += 1){
            int id = nums[i]%n;
            nums[id] += n;
        }
        
        for(int i = 0; i < n; i += 1){
            if(nums[i] > curr_max){
                curr_max = nums[i];
                max_ind = i;
            }
            nums[i] %= n;
        }
        
        return max_ind;
    }
};