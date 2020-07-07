class Solution {
public:
    int singleNumber(vector<int>& nums) {
    
    int n = nums.size();
    if(nums.size() == 0){
        return 0;
    }
    
    int first = 0, second = 0;
    for(int i = 0; i < n; i++){
        first = (first ^ nums[i]) & (~second);
        second = (second ^ nums[i]) & (~first);
    } 

    /*
    for(int i = 0; i < n; i++){
        second = second | (first & nums[i]);
        first = first ^ nums[i];
        int check = ~(first & second);
        first = first & check;
        second = second & check;
    } 
    */
    return first;
        
    }
};