class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int low = 0;
        int high = nums.size() -1;
        
        int ind = binSearch(nums,low,high,target);
        
        return ind;
        
    }
    
    int binSearch(vector<int> &nums, int low, int high, int target){
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        
        return high + 1;
    }
};