class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n - 1;
        
        int  i = 0;
        while(i < n && mid <= high){
            if(nums[i] == 0){
                swap(nums[i],nums[low]);
                low += 1;
                mid += 1;
            }else if(nums[i] == 1){
                mid += 1;
            }else{
                swap(nums[i],nums[high]);
                high -= 1;
                i -= 1;
            }
            
            i += 1;
        }
        
        
    }
};